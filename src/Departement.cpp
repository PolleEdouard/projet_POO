#include "Departement.hpp"
#include <algorithm>

// Constructeur
Departement::Departement(const std::string &nom) : nom(nom) {}

// Destructeur (ne supprime PAS les enseignants ni les UE)
Departement::~Departement() {}

// Getters
std::string Departement::getNom() const { return nom; }

const std::vector<Enseignant *> &Departement::getEnseignants() const {
  return enseignants;
}

const std::vector<UE *> &Departement::getUEs() const { return ues; }

int Departement::getNbEnseignants() const {
  return static_cast<int>(enseignants.size());
}

int Departement::getNbUEs() const { return static_cast<int>(ues.size()); }

// Setters
void Departement::setNom(const std::string &nom) { this->nom = nom; }

// Gestion des enseignants
void Departement::ajouterEnseignant(Enseignant *enseignant) {
  if (enseignant != nullptr) {
    enseignants.push_back(enseignant);
  }
}

void Departement::retirerEnseignant(Enseignant *enseignant) {
  auto it = std::find(enseignants.begin(), enseignants.end(), enseignant);
  if (it != enseignants.end()) {
    enseignants.erase(it);
  }
}

// Gestion des UE
void Departement::ajouterUE(UE *ue) {
  if (ue != nullptr) {
    ues.push_back(ue);
  }
}

void Departement::retirerUE(UE *ue) {
  auto it = std::find(ues.begin(), ues.end(), ue);
  if (it != ues.end()) {
    ues.erase(it);
  }
}
