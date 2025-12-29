#include "Autre.hpp"
#include "Departement.hpp"
#include "Diplome.hpp"
#include "GestionFichiers.hpp"
#include "Inscription.hpp"
#include "Intervention.hpp"
#include "MaitreConference.hpp"
#include "Professeur.hpp"
#include "Semestre.hpp"
#include "UE.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Données globales
vector<Enseignant *> enseignants;
vector<UE *> ues;
vector<Departement *> departements;
vector<Diplome *> diplomes;
vector<Semestre *> semestres;
vector<Intervention *> interventions;
vector<Inscription *> inscriptions;

// Utilitaires
void clearScreen() {
  cout << "\033[2J\033[1;1H"; // ANSI escape code
}

void pause() {
  cout << "\nAppuyez sur Entrée pour continuer...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.get();
}

int lireEntier(const string &message, int min = 0, int max = 1000000) {
  int valeur;
  while (true) {
    cout << message;
    cin >> valeur;

    if (cin.fail() || valeur < min || valeur > max) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "❌ Entrée invalide. Veuillez entrer un nombre entre " << min
           << " et " << max << endl;
    } else {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return valeur;
    }
  }
}

double lireDouble(const string &message, double min = 0.0,
                  double max = 1000.0) {
  double valeur;
  while (true) {
    cout << message;
    cin >> valeur;

    if (cin.fail() || valeur < min || valeur > max) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "❌ Entrée invalide. Veuillez entrer un nombre entre " << min
           << " et " << max << endl;
    } else {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return valeur;
    }
  }
}

string lireString(const string &message) {
  string valeur;
  cout << message;
  getline(cin, valeur);
  return valeur;
}

// Menu principal
void afficherMenu() {
  clearScreen();
  cout << "╔════════════════════════════════════════════════╗" << endl;
  cout << "║     SYSTÈME DE GESTION UNIVERSITAIRE          ║" << endl;
  cout << "╠════════════════════════════════════════════════╣" << endl;
  cout << "║  SAISIE                                        ║" << endl;
  cout << "║  1. Saisir un enseignant                      ║" << endl;
  cout << "║  2. Saisir une UE                             ║" << endl;
  cout << "║  3. Saisir un département                     ║" << endl;
  cout << "║  4. Saisir une intervention                   ║" << endl;
  cout << "║                                                ║" << endl;
  cout << "║  AFFICHAGE                                     ║" << endl;
  cout << "║  5. Afficher charges d'un enseignant          ║" << endl;
  cout << "║  6. Afficher taux encadrement (département)   ║" << endl;
  cout << "║  7. Lister tous les objets                    ║" << endl;
  cout << "║                                                ║" << endl;
  cout << "║  PERSISTANCE                                   ║" << endl;
  cout << "║  8. Sauvegarder les données                   ║" << endl;
  cout << "║  9. Charger les données                       ║" << endl;
  cout << "║                                                ║" << endl;
  cout << "║  0. Quitter                                    ║" << endl;
  cout << "╚════════════════════════════════════════════════╝" << endl;
  cout << "\nNombre d'enseignants: " << enseignants.size() << endl;
  cout << "Nombre d'UE: " << ues.size() << endl;
  cout << "Nombre de départements: " << departements.size() << endl;
  cout << endl;
}

// 1. Saisir enseignant
void saisirEnseignant() {
  clearScreen();
  cout << "=== SAISIR UN ENSEIGNANT ===" << endl << endl;

  cout << "Type d'enseignant:" << endl;
  cout << "  1. Professeur (192h)" << endl;
  cout << "  2. Maître de Conférence (192h)" << endl;
  cout << "  3. Autre (384h)" << endl;
  int type = lireEntier("Choix: ", 1, 3);

  string nom = lireString("Nom: ");
  string prenom = lireString("Prénom: ");
  string adresse = lireString("Adresse: ");
  int id = lireEntier("ID: ", 1, 99999);

  Enseignant *ens = nullptr;
  switch (type) {
  case 1:
    ens = new Professeur(nom, prenom, adresse, id);
    break;
  case 2:
    ens = new MaitreConference(nom, prenom, adresse, id);
    break;
  case 3:
    ens = new Autre(nom, prenom, adresse, id);
    break;
  }

  if (ens) {
    enseignants.push_back(ens);
    cout << "\nOK Enseignant ajouté avec succès!" << endl;
    cout << "  Type: " << GestionFichiers::getTypeEnseignant(ens) << endl;
    cout << "  Heures dues: " << ens->getNbHeuresDues() << "h" << endl;
  }

  pause();
}

// 2. Saisir UE
void saisirUE() {
  clearScreen();
  cout << "=== SAISIR UNE UE ===" << endl << endl;

  string nom = lireString("Nom de l'UE: ");

  cout << "\nCours Magistraux (CM):" << endl;
  double heuresCM = lireDouble("  Heures: ", 0, 200);
  int groupesCM = lireEntier("  Nombre de groupes: ", 0, 10);

  cout << "\nTravaux Dirigés (TD):" << endl;
  double heuresTD = lireDouble("  Heures: ", 0, 200);
  int groupesTD = lireEntier("  Nombre de groupes: ", 0, 20);

  cout << "\nTravaux Pratiques (TP):" << endl;
  double heuresTP = lireDouble("  Heures: ", 0, 200);
  int groupesTP = lireEntier("  Nombre de groupes: ", 0, 20);

  Enseignant *responsable = nullptr;
  if (!enseignants.empty()) {
    cout << "\nEnseignant responsable:" << endl;
    for (size_t i = 0; i < enseignants.size(); i++) {
      cout << "  " << (i + 1) << ". " << enseignants[i]->getPrenom() << " "
           << enseignants[i]->getNom() << endl;
    }
    cout << "  0. Aucun" << endl;

    int choix = lireEntier("Choix: ", 0, enseignants.size());
    if (choix > 0) {
      responsable = enseignants[choix - 1];
    }
  }

  UE *ue = new UE(nom, heuresCM, groupesCM, heuresTD, groupesTD, heuresTP,
                  groupesTP, responsable);
  ues.push_back(ue);

  cout << "\nOK UE ajoutée avec succès!" << endl;
  cout << "  Coût ETD total: " << fixed << setprecision(2)
       << ue->calculerCoutTotalETD() << "h" << endl;

  pause();
}

// 3. Saisir département
void saisirDepartement() {
  clearScreen();
  cout << "=== SAISIR UN DÉPARTEMENT ===" << endl << endl;

  string nom = lireString("Nom du département: ");
  Departement *dept = new Departement(nom);

  // Ajouter enseignants
  if (!enseignants.empty()) {
    cout << "\nAjouter des enseignants (plusieurs choix possibles):" << endl;
    for (size_t i = 0; i < enseignants.size(); i++) {
      cout << "  " << (i + 1) << ". " << enseignants[i]->getPrenom() << " "
           << enseignants[i]->getNom() << endl;
    }

    while (true) {
      int choix = lireEntier("Ajouter enseignant (0 pour terminer): ", 0,
                             enseignants.size());
      if (choix == 0)
        break;
      dept->ajouterEnseignant(enseignants[choix - 1]);
      cout << "  OK Ajouté" << endl;
    }
  }

  // Ajouter UE
  if (!ues.empty()) {
    cout << "\nAjouter des UE (plusieurs choix possibles):" << endl;
    for (size_t i = 0; i < ues.size(); i++) {
      cout << "  " << (i + 1) << ". " << ues[i]->getNom() << endl;
    }

    while (true) {
      int choix = lireEntier("Ajouter UE (0 pour terminer): ", 0, ues.size());
      if (choix == 0)
        break;
      dept->ajouterUE(ues[choix - 1]);
      cout << "  OK Ajouté" << endl;
    }
  }

  departements.push_back(dept);

  cout << "\nOK Département créé avec succès!" << endl;
  cout << "  Enseignants: " << dept->getNbEnseignants() << endl;
  cout << "  UE: " << dept->getNbUEs() << endl;

  pause();
}

// 4. Saisir intervention
void saisirIntervention() {
  clearScreen();
  cout << "=== SAISIR UNE INTERVENTION ===" << endl << endl;

  if (enseignants.empty() || ues.empty()) {
    cout << "❌ Il faut d'abord créer des enseignants et des UE!" << endl;
    pause();
    return;
  }

  cout << "Enseignant:" << endl;
  for (size_t i = 0; i < enseignants.size(); i++) {
    cout << "  " << (i + 1) << ". " << enseignants[i]->getPrenom() << " "
         << enseignants[i]->getNom() << endl;
  }
  int choixEns = lireEntier("Choix: ", 1, enseignants.size());

  cout << "\nUE:" << endl;
  for (size_t i = 0; i < ues.size(); i++) {
    cout << "  " << (i + 1) << ". " << ues[i]->getNom() << endl;
  }
  int choixUE = lireEntier("Choix: ", 1, ues.size());

  double heuresCM = lireDouble("\nHeures de CM effectuées: ", 0, 200);
  double heuresTD = lireDouble("Heures de TD effectuées: ", 0, 200);
  double heuresTP = lireDouble("Heures de TP effectuées: ", 0, 200);

  Intervention *interv =
      new Intervention(enseignants[choixEns - 1], ues[choixUE - 1], heuresCM,
                       heuresTD, heuresTP);
  interventions.push_back(interv);

  cout << "\nOK Intervention enregistrée!" << endl;
  cout << "  Total heures: " << interv->calculerHeuresEffectuees() << "h"
       << endl;
  cout << "  ETD effectué: " << fixed << setprecision(2)
       << interv->calculerETDEffectue() << "h" << endl;

  pause();
}

// 5. Afficher charges enseignant
void afficherChargesEnseignant() {
  clearScreen();
  cout << "=== CHARGES D'UN ENSEIGNANT ===" << endl << endl;

  if (enseignants.empty()) {
    cout << "❌ Aucun enseignant enregistré!" << endl;
    pause();
    return;
  }

  for (size_t i = 0; i < enseignants.size(); i++) {
    cout << "  " << (i + 1) << ". " << enseignants[i]->getPrenom() << " "
         << enseignants[i]->getNom() << endl;
  }
  int choix = lireEntier("\nChoix: ", 1, enseignants.size());

  Enseignant *ens = enseignants[choix - 1];

  cout << "\n" << string(50, '=') << endl;
  cout << "Enseignant: " << ens->getPrenom() << " " << ens->getNom() << endl;
  cout << "Type: " << GestionFichiers::getTypeEnseignant(ens) << endl;
  cout << "Heures dues: " << ens->getNbHeuresDues() << "h" << endl;
  cout << string(50, '=') << endl;

  // Chercher interventions
  cout << "\nInterventions:" << endl;
  double totalHeures = 0;
  double totalETD = 0;
  int nbInterventions = 0;

  for (const auto &interv : interventions) {
    if (interv->getEnseignant() == ens) {
      cout << "  • " << interv->getUE()->getNom() << endl;
      cout << "    CM: " << interv->getHeuresCM() << "h, "
           << "TD: " << interv->getHeuresTD() << "h, "
           << "TP: " << interv->getHeuresTP() << "h" << endl;
      cout << "    Total: " << interv->calculerHeuresEffectuees() << "h, "
           << "ETD: " << fixed << setprecision(2)
           << interv->calculerETDEffectue() << "h" << endl;
      totalHeures += interv->calculerHeuresEffectuees();
      totalETD += interv->calculerETDEffectue();
      nbInterventions++;
    }
  }

  if (nbInterventions == 0) {
    cout << "  Aucune intervention enregistrée" << endl;
  } else {
    cout << "\nRÉSUMÉ:" << endl;
    cout << "  Nombre d'interventions: " << nbInterventions << endl;
    cout << "  Total heures effectuées: " << totalHeures << "h" << endl;
    cout << "  Total ETD: " << totalETD << "h" << endl;
    cout << "  Heures restantes: " << (ens->getNbHeuresDues() - totalETD) << "h"
         << endl;
  }

  pause();
}

// 6. Afficher taux encadrement
void afficherTauxEncadrement() {
  clearScreen();
  cout << "=== TAUX D'ENCADREMENT ===" << endl << endl;

  if (departements.empty()) {
    cout << "❌ Aucun département enregistré!" << endl;
    pause();
    return;
  }

  for (size_t i = 0; i < departements.size(); i++) {
    cout << "  " << (i + 1) << ". " << departements[i]->getNom() << endl;
  }
  int choix = lireEntier("\nChoix: ", 1, departements.size());

  Departement *dept = departements[choix - 1];

  cout << "\n" << string(50, '=') << endl;
  cout << "Département: " << dept->getNom() << endl;
  cout << string(50, '=') << endl;

  cout << "\nEnseignants (" << dept->getNbEnseignants() << "):" << endl;
  double totalHeuresDues = 0;
  for (const auto &ens : dept->getEnseignants()) {
    cout << "  • " << ens->getPrenom() << " " << ens->getNom() << " ("
         << ens->getNbHeuresDues() << "h)" << endl;
    totalHeuresDues += ens->getNbHeuresDues();
  }
  cout << "  Total: " << totalHeuresDues << "h" << endl;

  cout << "\nUE (" << dept->getNbUEs() << "):" << endl;
  double totalCoutsETD = 0;
  for (const auto &ue : dept->getUEs()) {
    double coutETD = ue->calculerCoutTotalETD();
    cout << "  • " << ue->getNom() << " (" << fixed << setprecision(2)
         << coutETD << "h ETD)" << endl;
    totalCoutsETD += coutETD;
  }
  cout << "  Total: " << totalCoutsETD << "h" << endl;

  double taux = dept->calculerTauxEncadrement();
  cout << "\n" << string(50, '=') << endl;
  cout << "TAUX D'ENCADREMENT: " << fixed << setprecision(4) << taux << endl;
  cout << string(50, '=') << endl;

  if (taux > 1.0) {
    cout << "OK Taux > 1: Enseignants surdimensionnés" << endl;
  } else if (taux < 1.0) {
    cout << "ATTENTION Taux < 1: Manque d'enseignants" << endl;
  } else {
    cout << "= Taux = 1: Équilibre parfait" << endl;
  }

  pause();
}

// 7. Lister tous les objets
void listerObjets() {
  clearScreen();
  cout << "=== LISTE DE TOUS LES OBJETS ===" << endl << endl;

  cout << "ENSEIGNANTS (" << enseignants.size() << "):" << endl;
  for (const auto &ens : enseignants) {
    cout << "  • " << ens->getPrenom() << " " << ens->getNom() << " ("
         << GestionFichiers::getTypeEnseignant(ens) << ", "
         << ens->getNbHeuresDues() << "h)" << endl;
  }

  cout << "\nUE (" << ues.size() << "):" << endl;
  for (const auto &ue : ues) {
    cout << "  • " << ue->getNom() << " (ETD: " << fixed << setprecision(2)
         << ue->calculerCoutTotalETD() << "h)" << endl;
  }

  cout << "\nDÉPARTEMENTS (" << departements.size() << "):" << endl;
  for (const auto &dept : departements) {
    cout << "  • " << dept->getNom() << " (" << dept->getNbEnseignants()
         << " ens., " << dept->getNbUEs() << " UE)" << endl;
  }

  cout << "\nINTERVENTIONS (" << interventions.size() << "):" << endl;
  for (const auto &interv : interventions) {
    cout << "  • " << interv->getEnseignant()->getNom() << " → "
         << interv->getUE()->getNom() << " ("
         << interv->calculerHeuresEffectuees() << "h)" << endl;
  }

  pause();
}

// 8. Sauvegarder
void sauvegarder() {
  clearScreen();
  cout << "=== SAUVEGARDE ===" << endl << endl;

  map<Enseignant *, int> mapEnsToId;
  map<UE *, int> mapUEToId;

  int id = 1;
  for (auto ens : enseignants)
    mapEnsToId[ens] = id++;

  id = 1;
  for (auto ue : ues)
    mapUEToId[ue] = id++;

  bool ok1 = GestionFichiers::sauvegarderEnseignants(enseignants,
                                                     "data/enseignants.csv");
  bool ok2 = GestionFichiers::sauvegarderUEs(ues, "data/ues.csv");
  bool ok3 = GestionFichiers::sauvegarderDepartements(
      departements, "data/departements.csv", mapEnsToId, mapUEToId);

  cout << "Enseignants: " << (ok1 ? "OK" : "ERREUR") << endl;
  cout << "UE: " << (ok2 ? "OK" : "ERREUR") << endl;
  cout << "Départements: " << (ok3 ? "OK" : "ERREUR") << endl;

  if (ok1 && ok2 && ok3) {
    cout << "\nOK Toutes les données ont été sauvegardées dans data/" << endl;
  } else {
    cout << "\n❌ Erreur lors de la sauvegarde" << endl;
  }

  pause();
}

// 9. Charger
void charger() {
  clearScreen();
  cout << "=== CHARGEMENT ===" << endl << endl;
  cout << "ATTENTION Attention: les données actuelles seront remplacées!" << endl;
  cout << "Continuer? (o/n): ";

  char reponse;
  cin >> reponse;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (reponse != 'o' && reponse != 'O') {
    cout << "Annulé" << endl;
    pause();
    return;
  }

  // Nettoyer données actuelles
  for (auto ens : enseignants)
    delete ens;
  for (auto ue : ues)
    delete ue;
  for (auto dept : departements)
    delete dept;
  for (auto interv : interventions)
    delete interv;

  enseignants.clear();
  ues.clear();
  departements.clear();
  interventions.clear();

  // Charger
  map<int, Enseignant *> mapIdToEns;
  map<int, UE *> mapIdToUE;

  enseignants =
      GestionFichiers::chargerEnseignants("data/enseignants.csv", mapIdToEns);
  ues = GestionFichiers::chargerUEs("data/ues.csv", mapIdToEns, mapIdToUE);
  departements = GestionFichiers::chargerDepartements("data/departements.csv",
                                                      mapIdToEns, mapIdToUE);

  cout << "\nOK Données chargées:" << endl;
  cout << "  Enseignants: " << enseignants.size() << endl;
  cout << "  UE: " << ues.size() << endl;
  cout << "  Départements: " << departements.size() << endl;

  pause();
}

// Main
int main() {
  int choix;
  bool quitter = false;

  cout << "Bienvenue dans le Système de Gestion Universitaire!" << endl;
  cout << "\nChargement des données existantes..." << endl;

  // Tentative de chargement au démarrage
  map<int, Enseignant *> mapIdToEns;
  map<int, UE *> mapIdToUE;

  enseignants =
      GestionFichiers::chargerEnseignants("data/enseignants.csv", mapIdToEns);
  ues = GestionFichiers::chargerUEs("data/ues.csv", mapIdToEns, mapIdToUE);
  departements = GestionFichiers::chargerDepartements("data/departements.csv",
                                                      mapIdToEns, mapIdToUE);

  if (!enseignants.empty() || !ues.empty() || !departements.empty()) {
    cout << "OK Données chargées depuis data/" << endl;
  }

  pause();

  while (!quitter) {
    afficherMenu();
    choix = lireEntier("Choix: ", 0, 9);

    switch (choix) {
    case 1:
      saisirEnseignant();
      break;
    case 2:
      saisirUE();
      break;
    case 3:
      saisirDepartement();
      break;
    case 4:
      saisirIntervention();
      break;
    case 5:
      afficherChargesEnseignant();
      break;
    case 6:
      afficherTauxEncadrement();
      break;
    case 7:
      listerObjets();
      break;
    case 8:
      sauvegarder();
      break;
    case 9:
      charger();
      break;
    case 0:
      cout << "\nSauvegarder avant de quitter? (o/n): ";
      char rep;
      cin >> rep;
      if (rep == 'o' || rep == 'O') {
        sauvegarder();
      }
      quitter = true;
      break;
    }
  }

  // Nettoyage mémoire
  cout << "\nNettoyage de la mémoire..." << endl;
  for (auto ens : enseignants)
    delete ens;
  for (auto ue : ues)
    delete ue;
  for (auto dept : departements)
    delete dept;
  for (auto interv : interventions)
    delete interv;
  for (auto inscr : inscriptions)
    delete inscr;

  cout << "Au revoir!" << endl;

  return 0;
}
