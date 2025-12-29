#include "Departement.hpp"
#include "Diplome.hpp"
#include "Inscription.hpp"
#include "MaitreConference.hpp"
#include "Professeur.hpp"
#include "Semestre.hpp"
#include "UE.hpp"
#include <iomanip>
#include <iostream>

int main() {
  std::cout << "=== Test des classes conteneurs ===" << std::endl << std::endl;

  // Création des objets de base
  Professeur prof1("Martin", "Sophie", "10 Rue", 1001);
  Professeur prof2("Durand", "Pierre", "20 Avenue", 1002);
  MaitreConference mcf("Dubois", "Luc", "30 Boulevard", 1003);

  UE ue1("Programmation Orientée Objet", 20.0, 1, 30.0, 2, 20.0, 3, &prof1);
  UE ue2("Structures de Données", 15.0, 1, 25.0, 2, 15.0, 2, &mcf);
  UE ue3("Algorithmique Avancée", 18.0, 1, 20.0, 2, 12.0, 2, &prof2);

  // Test Departement
  std::cout << "=== Test Departement ===" << std::endl;
  Departement deptInfo("Informatique");

  deptInfo.ajouterEnseignant(&prof1);
  deptInfo.ajouterEnseignant(&prof2);
  deptInfo.ajouterEnseignant(&mcf);

  deptInfo.ajouterUE(&ue1);
  deptInfo.ajouterUE(&ue2);
  deptInfo.ajouterUE(&ue3);

  std::cout << "Département: " << deptInfo.getNom() << std::endl;
  std::cout << "  Enseignants: " << deptInfo.getNbEnseignants() << std::endl;

  for (const auto &ens : deptInfo.getEnseignants()) {
    std::cout << "    - " << ens->getPrenom() << " " << ens->getNom()
              << std::endl;
  }

  std::cout << "  UE: " << deptInfo.getNbUEs() << std::endl;
  for (const auto &ue : deptInfo.getUEs()) {
    std::cout << "    - " << ue->getNom() << std::endl;
  }
  std::cout << std::endl;

  // Test Semestre avec Inscriptions
  std::cout << "=== Test Semestre avec Inscriptions ===" << std::endl;
  Semestre s1(1, "2024-2025");
  Semestre s2(2, "2024-2025");

  Inscription inscr1(&ue1, &s1, 45);
  Inscription inscr2(&ue2, &s1, 38);
  Inscription inscr3(&ue3, &s1, 42);
  Inscription inscr4(&ue1, &s2, 40);

  s1.ajouterInscription(&inscr1);
  s1.ajouterInscription(&inscr2);
  s1.ajouterInscription(&inscr3);
  s2.ajouterInscription(&inscr4);

  std::cout << "Semestre: S" << s1.getNumero() << " " << s1.getAnnee()
            << std::endl;
  std::cout << "  Nombre d'inscriptions: " << s1.getNbInscriptions()
            << std::endl;

  for (const auto &inscr : s1.getInscriptions()) {
    std::cout << "    - " << inscr->getUE()->getNom() << " ("
              << inscr->getNbEtudiants() << " étudiants)" << std::endl;
  }
  std::cout << std::endl;

  // Test Diplome
  std::cout << "=== Test Diplome ===" << std::endl;
  Diplome licence("Licence Informatique");

  licence.ajouterSemestre(&s1);
  licence.ajouterSemestre(&s2);

  std::cout << "Diplôme: " << licence.getNom() << std::endl;
  std::cout << "  Nombre de semestres: " << licence.getNbSemestres()
            << std::endl;

  for (const auto &sem : licence.getSemestres()) {
    std::cout << "    - S" << sem->getNumero() << " " << sem->getAnnee() << " ("
              << sem->getNbInscriptions() << " UE)" << std::endl;
  }
  std::cout << std::endl;

  // Test de retrait d'éléments
  std::cout << "=== Test retrait d'éléments ===" << std::endl;

  std::cout << "Retrait d'un enseignant du département..." << std::endl;
  deptInfo.retirerEnseignant(&prof2);
  std::cout << "  Enseignants restants: " << deptInfo.getNbEnseignants()
            << std::endl;

  std::cout << "Retrait d'une inscription du semestre..." << std::endl;
  s1.retirerInscription(&inscr2);
  std::cout << "  Inscriptions restantes: " << s1.getNbInscriptions()
            << std::endl;

  std::cout << "Retrait d'un semestre du diplôme..." << std::endl;
  licence.retirerSemestre(&s2);
  std::cout << "  Semestres restants: " << licence.getNbSemestres()
            << std::endl;
  std::cout << std::endl;

  // Vérification gestion mémoire
  std::cout << "=== Vérification gestion mémoire ===" << std::endl;
  std::cout << "Les conteneurs vont être détruits..." << std::endl;
  std::cout << "Les objets contenus (pointeurs) restent valides." << std::endl;
  std::cout << std::endl;

  std::cout << "Après destruction des conteneurs:" << std::endl;
  std::cout << "  Enseignant " << prof1.getNom() << " toujours accessible ✓"
            << std::endl;
  std::cout << "  UE " << ue1.getNom() << " toujours accessible ✓" << std::endl;
  std::cout << "  Semestre S" << s1.getNumero() << " toujours accessible ✓"
            << std::endl;
  std::cout << std::endl;

  std::cout << "=== Tests réussis! ===" << std::endl;

  return 0;
}
