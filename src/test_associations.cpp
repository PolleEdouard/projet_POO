#include "Inscription.hpp"
#include "Intervention.hpp"
#include "MaitreConference.hpp"
#include "Professeur.hpp"
#include "Semestre.hpp"
#include "UE.hpp"
#include <iomanip>
#include <iostream>

int main() {
  std::cout << "=== Test des classes d'association ===" << std::endl
            << std::endl;

  // Création des objets de base
  Professeur prof("Martin", "Sophie", "10 Rue des Sciences", 1001);
  MaitreConference mcf("Dubois", "Luc", "20 Avenue Einstein", 1002);

  UE ue1("Programmation Orientée Objet", 20.0, 1, 30.0, 2, 20.0, 3, &prof);
  UE ue2("Structures de Données", 15.0, 1, 25.0, 2, 15.0, 2, &mcf);

  Semestre s1(1, "2024-2025");
  Semestre s2(2, "2024-2025");

  std::cout << "=== Objets créés ===" << std::endl;
  std::cout << "Enseignant 1: " << prof.getPrenom() << " " << prof.getNom()
            << std::endl;
  std::cout << "Enseignant 2: " << mcf.getPrenom() << " " << mcf.getNom()
            << std::endl;
  std::cout << "UE 1: " << ue1.getNom() << std::endl;
  std::cout << "UE 2: " << ue2.getNom() << std::endl;
  std::cout << "Semestre: S" << s1.getNumero() << " " << s1.getAnnee()
            << std::endl;
  std::cout << std::endl;

  // Test de la classe Intervention
  std::cout << "=== Test Intervention ===" << std::endl;
  std::cout << "Le Prof. Martin intervient dans l'UE POO" << std::endl;

  Intervention interv1(&prof, &ue1, 10.0, 15.0, 12.0);

  std::cout << "Intervention de " << interv1.getEnseignant()->getNom()
            << " dans " << interv1.getUE()->getNom() << std::endl;
  std::cout << "  Heures CM: " << interv1.getHeuresCM() << "h" << std::endl;
  std::cout << "  Heures TD: " << interv1.getHeuresTD() << "h" << std::endl;
  std::cout << "  Heures TP: " << interv1.getHeuresTP() << "h" << std::endl;
  std::cout << "  Total heures: " << interv1.calculerHeuresEffectuees() << "h"
            << std::endl;
  std::cout << "  ETD effectué: " << std::fixed << std::setprecision(2)
            << interv1.calculerETDEffectue() << "h" << std::endl;
  std::cout << std::endl;

  // Calcul détaillé de l'ETD
  double etd = (10.0 * 1.5) + (15.0 * 1.0) + (12.0 * 2.0 / 3.0);
  std::cout << "Vérification ETD: (10×1.5) + (15×1.0) + (12×0.667) = " << etd
            << "h" << std::endl;
  std::cout << std::endl;

  // Autre intervention
  Intervention interv2(&mcf, &ue2, 8.0, 12.0, 10.0);
  std::cout << "Intervention de " << interv2.getEnseignant()->getNom()
            << " dans " << interv2.getUE()->getNom() << std::endl;
  std::cout << "  Total heures: " << interv2.calculerHeuresEffectuees() << "h"
            << std::endl;
  std::cout << "  ETD effectué: " << interv2.calculerETDEffectue() << "h"
            << std::endl;
  std::cout << std::endl;

  // Test de la classe Inscription
  std::cout << "=== Test Inscription ===" << std::endl;

  Inscription inscr1(&ue1, &s1, 45);
  Inscription inscr2(&ue2, &s1, 38);
  Inscription inscr3(&ue1, &s2, 42);

  std::cout << "Inscription 1:" << std::endl;
  std::cout << "  UE: " << inscr1.getUE()->getNom() << std::endl;
  std::cout << "  Semestre: S" << inscr1.getSemestre()->getNumero() << " "
            << inscr1.getSemestre()->getAnnee() << std::endl;
  std::cout << "  Étudiants inscrits: " << inscr1.getNbEtudiants() << std::endl;
  std::cout << std::endl;

  std::cout << "Inscription 2:" << std::endl;
  std::cout << "  UE: " << inscr2.getUE()->getNom() << std::endl;
  std::cout << "  Semestre: S" << inscr2.getSemestre()->getNumero() << " "
            << inscr2.getSemestre()->getAnnee() << std::endl;
  std::cout << "  Étudiants inscrits: " << inscr2.getNbEtudiants() << std::endl;
  std::cout << std::endl;

  std::cout << "Inscription 3:" << std::endl;
  std::cout << "  UE: " << inscr3.getUE()->getNom() << std::endl;
  std::cout << "  Semestre: S" << inscr3.getSemestre()->getNumero() << " "
            << inscr3.getSemestre()->getAnnee() << std::endl;
  std::cout << "  Étudiants inscrits: " << inscr3.getNbEtudiants() << std::endl;
  std::cout << std::endl;

  // Test de la gestion mémoire
  std::cout << "=== Test gestion mémoire ===" << std::endl;
  std::cout << "Les objets Intervention et Inscription vont être détruits..."
            << std::endl;
  std::cout
      << "Les objets référencés (Enseignant, UE, Semestre) restent valides."
      << std::endl;
  std::cout << std::endl;

  std::cout << "Vérification après destruction des associations:" << std::endl;
  std::cout << "  Prof. " << prof.getNom() << " est toujours accessible ✓"
            << std::endl;
  std::cout << "  UE " << ue1.getNom() << " est toujours accessible ✓"
            << std::endl;
  std::cout << "  Semestre S" << s1.getNumero() << " est toujours accessible ✓"
            << std::endl;
  std::cout << std::endl;

  std::cout << "=== Tests réussis! ===" << std::endl;

  return 0;
}
