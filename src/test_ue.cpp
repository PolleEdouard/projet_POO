#include "Professeur.hpp"
#include "UE.hpp"
#include <iomanip>
#include <iostream>

int main() {
  std::cout << "=== Test de la classe UE ===" << std::endl << std::endl;

  // Création d'un enseignant responsable
  Professeur responsable("Durand", "Marie", "10 Rue des Sciences", 5001);

  std::cout << "Enseignant responsable: " << responsable.getPrenom() << " "
            << responsable.getNom() << std::endl
            << std::endl;

  // Création d'une UE complète
  UE ue1("Programmation Orientée Objet", 20.0, 1, // CM: 20 heures, 1 groupe
         30.0, 2,                                 // TD: 30 heures, 2 groupes
         20.0, 3,                                 // TP: 20 heures, 3 groupes
         &responsable);

  std::cout << "UE: " << ue1.getNom() << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  // Affichage des détails CM
  Cm cm = ue1.getCm();
  std::cout << "CM:" << std::endl;
  std::cout << "  Heures: " << cm.getHeures() << "h" << std::endl;
  std::cout << "  Groupes: " << cm.getNbGroupes() << std::endl;
  std::cout << "  Coefficient: " << cm.getCoefficient() << std::endl;
  std::cout << "  ETD CM = " << cm.getHeures() << " × " << cm.getNbGroupes()
            << " × " << cm.getCoefficient() << " = " << cm.calculerETD() << "h"
            << std::endl
            << std::endl;

  // Affichage des détails TD
  Td td = ue1.getTd();
  std::cout << "TD:" << std::endl;
  std::cout << "  Heures: " << td.getHeures() << "h" << std::endl;
  std::cout << "  Groupes: " << td.getNbGroupes() << std::endl;
  std::cout << "  Coefficient: " << td.getCoefficient() << std::endl;
  std::cout << "  ETD TD = " << td.getHeures() << " × " << td.getNbGroupes()
            << " × " << td.getCoefficient() << " = " << td.calculerETD() << "h"
            << std::endl
            << std::endl;

  // Affichage des détails TP
  Tp tp = ue1.getTp();
  std::cout << "TP:" << std::endl;
  std::cout << "  Heures: " << tp.getHeures() << "h" << std::endl;
  std::cout << "  Groupes: " << tp.getNbGroupes() << std::endl;
  std::cout << "  Coefficient: " << std::fixed << std::setprecision(4)
            << tp.getCoefficient() << std::endl;
  std::cout << "  ETD TP = " << tp.getHeures() << " × " << tp.getNbGroupes()
            << " × " << tp.getCoefficient() << " = " << std::setprecision(2)
            << tp.calculerETD() << "h" << std::endl
            << std::endl;

  // Calcul et affichage de l'ETD total
  double etdTotal = ue1.calculerCoutTotalETD();
  std::cout << "========================================" << std::endl;
  std::cout << "COÛT TOTAL ETD: " << etdTotal << " heures" << std::endl;
  std::cout << "========================================" << std::endl
            << std::endl;

  // Vérification manuelle du calcul
  double verif = (20.0 * 1 * 1.5) + (30.0 * 2 * 1.0) + (20.0 * 3 * (2.0 / 3.0));
  std::cout << "Vérification du calcul:" << std::endl;
  std::cout << "  (20×1×1.5) + (30×2×1.0) + (20×3×0.667)" << std::endl;
  std::cout << "  = 30 + 60 + 40 = " << verif << "h" << std::endl;

  if (std::abs(etdTotal - verif) < 0.01) {
    std::cout << "✓ Calcul correct!" << std::endl;
  } else {
    std::cout << "✗ Erreur de calcul!" << std::endl;
  }

  std::cout << std::endl;

  // Test avec une UE sans responsable
  UE ue2("Mathématiques", 15.0, 1, 20.0, 1, 10.0, 2);
  std::cout << "UE sans responsable: " << ue2.getNom() << std::endl;
  std::cout << "Coût ETD: " << ue2.calculerCoutTotalETD() << "h" << std::endl;
  std::cout << "Responsable: "
            << (ue2.getResponsable() ? "Défini" : "Non défini") << std::endl;

  std::cout << std::endl << "=== Tests réussis! ===" << std::endl;

  return 0;
}
