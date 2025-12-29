#include "GestionFichiers.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>

// ===================== Fonctions utilitaires =====================

std::vector<std::string> GestionFichiers::split(const std::string &str,
                                                char delimiter) {
  std::vector<std::string> tokens;
  std::stringstream ss(str);
  std::string token;

  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }

  return tokens;
}

std::string GestionFichiers::getTypeEnseignant(Enseignant *ens) {
  if (dynamic_cast<Professeur *>(ens))
    return "Professeur";
  if (dynamic_cast<MaitreConference *>(ens))
    return "MaitreConference";
  if (dynamic_cast<Autre *>(ens))
    return "Autre";
  return "Unknown";
}

Enseignant *GestionFichiers::creerEnseignant(const std::string &type,
                                             const std::string &nom,
                                             const std::string &prenom,
                                             const std::string &adresse,
                                             int id) {
  if (type == "Professeur") {
    return new Professeur(nom, prenom, adresse, id);
  } else if (type == "MaitreConference") {
    return new MaitreConference(nom, prenom, adresse, id);
  } else if (type == "Autre") {
    return new Autre(nom, prenom, adresse, id);
  }
  return nullptr;
}

// ===================== Sauvegarde =====================

bool GestionFichiers::sauvegarderEnseignants(
    const std::vector<Enseignant *> &enseignants, const std::string &filename) {
  // Créer le dossier data/ s'il n'existe pas
  mkdir("data", 0755);

  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Erreur: impossible d'ouvrir " << filename << std::endl;
    return false;
  }

  // En-tête CSV
  file << "id,type,nom,prenom,adresse,nbHeuresDues" << std::endl;

  // Données
  int id = 1;
  for (const auto &ens : enseignants) {
    if (ens) {
      file << id << "," << getTypeEnseignant(ens) << "," << ens->getNom() << ","
           << ens->getPrenom() << "," << ens->getAdresse() << ","
           << ens->getNbHeuresDues() << std::endl;
      id++;
    }
  }

  file.close();
  return true;
}

bool GestionFichiers::sauvegarderUEs(const std::vector<UE *> &ues,
                                     const std::string &filename) {
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Erreur: impossible d'ouvrir " << filename << std::endl;
    return false;
  }

  // En-tête CSV
  file << "id,nom,heuresCM,groupesCM,heuresTD,groupesTD,heuresTP,groupesTP"
       << std::endl;

  // Données
  int id = 1;
  for (const auto &ue : ues) {
    if (ue) {
      file << id << "," << ue->getNom() << "," << ue->getCm().getHeures() << ","
           << ue->getCm().getNbGroupes() << "," << ue->getTd().getHeures()
           << "," << ue->getTd().getNbGroupes() << ","
           << ue->getTp().getHeures() << "," << ue->getTp().getNbGroupes()
           << std::endl;
      id++;
    }
  }

  file.close();
  return true;
}

bool GestionFichiers::sauvegarderDepartements(
    const std::vector<Departement *> &departements, const std::string &filename,
    const std::map<Enseignant *, int> &mapEnseignants,
    const std::map<UE *, int> &mapUEs) {
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Erreur: impossible d'ouvrir " << filename << std::endl;
    return false;
  }

  // En-tête CSV
  file << "id,nom,idsEnseignants,idsUE" << std::endl;

  // Données
  int id = 1;
  for (const auto &dept : departements) {
    if (dept) {
      file << id << "," << dept->getNom() << ",";

      // IDs des enseignants (séparés par ;)
      bool first = true;
      for (const auto &ens : dept->getEnseignants()) {
        auto it = mapEnseignants.find(ens);
        if (it != mapEnseignants.end()) {
          if (!first)
            file << ";";
          file << it->second;
          first = false;
        }
      }
      file << ",";

      // IDs des UE (séparés par ;)
      first = true;
      for (const auto &ue : dept->getUEs()) {
        auto it = mapUEs.find(ue);
        if (it != mapUEs.end()) {
          if (!first)
            file << ";";
          file << it->second;
          first = false;
        }
      }
      file << std::endl;
      id++;
    }
  }

  file.close();
  return true;
}

// ===================== Chargement =====================

std::vector<Enseignant *>
GestionFichiers::chargerEnseignants(const std::string &filename,
                                    std::map<int, Enseignant *> &outMap) {
  std::vector<Enseignant *> enseignants;
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Erreur: impossible d'ouvrir " << filename << std::endl;
    return enseignants;
  }

  std::string line;
  std::getline(file, line); // Ignorer l'en-tête

  while (std::getline(file, line)) {
    auto tokens = split(line, ',');
    if (tokens.size() >= 6) {
      int id = std::stoi(tokens[0]);
      std::string type = tokens[1];
      std::string nom = tokens[2];
      std::string prenom = tokens[3];
      std::string adresse = tokens[4];

      Enseignant *ens = creerEnseignant(type, nom, prenom, adresse, id);
      if (ens) {
        enseignants.push_back(ens);
        outMap[id] = ens;
      }
    }
  }

  file.close();
  return enseignants;
}

std::vector<UE *>
GestionFichiers::chargerUEs(const std::string &filename,
                            const std::map<int, Enseignant *> &mapEnseignants,
                            std::map<int, UE *> &outMap) {
  std::vector<UE *> ues;
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Erreur: impossible d'ouvrir " << filename << std::endl;
    return ues;
  }

  std::string line;
  std::getline(file, line); // Ignorer l'en-tête

  while (std::getline(file, line)) {
    auto tokens = split(line, ',');
    if (tokens.size() >= 8) {
      int id = std::stoi(tokens[0]);
      std::string nom = tokens[1];
      double heuresCM = std::stod(tokens[2]);
      int groupesCM = std::stoi(tokens[3]);
      double heuresTD = std::stod(tokens[4]);
      int groupesTD = std::stoi(tokens[5]);
      double heuresTP = std::stod(tokens[6]);
      int groupesTP = std::stoi(tokens[7]);

      UE *ue = new UE(nom, heuresCM, groupesCM, heuresTD, groupesTD, heuresTP,
                      groupesTP);
      ues.push_back(ue);
      outMap[id] = ue;
    }
  }

  file.close();
  return ues;
}

std::vector<Departement *> GestionFichiers::chargerDepartements(
    const std::string &filename,
    const std::map<int, Enseignant *> &mapEnseignants,
    const std::map<int, UE *> &mapUEs) {
  std::vector<Departement *> departements;
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Erreur: impossible d'ouvrir " << filename << std::endl;
    return departements;
  }

  std::string line;
  std::getline(file, line); // Ignorer l'en-tête

  while (std::getline(file, line)) {
    auto tokens = split(line, ',');
    if (tokens.size() >= 4) {
      std::string nom = tokens[1];
      Departement *dept = new Departement(nom);

      // Restaurer enseignants
      if (!tokens[2].empty()) {
        auto idsEns = split(tokens[2], ';');
        for (const auto &idStr : idsEns) {
          int id = std::stoi(idStr);
          auto it = mapEnseignants.find(id);
          if (it != mapEnseignants.end()) {
            dept->ajouterEnseignant(it->second);
          }
        }
      }

      // Restaurer UE
      if (!tokens[3].empty()) {
        auto idsUE = split(tokens[3], ';');
        for (const auto &idStr : idsUE) {
          int id = std::stoi(idStr);
          auto it = mapUEs.find(id);
          if (it != mapUEs.end()) {
            dept->ajouterUE(it->second);
          }
        }
      }

      departements.push_back(dept);
    }
  }

  file.close();
  return departements;
}
