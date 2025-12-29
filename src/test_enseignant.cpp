#include "Autre.hpp"
#include "Enseignant.hpp"
#include "MaitreConference.hpp"
#include "Professeur.hpp"
#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::cout << "=== Test de la hiérarchie des classes Enseignant ==="
            << std::endl
            << std::endl;

  // Création de différents types d'enseignants
  Professeur prof("Dupont", "Jean", "123 Rue de l'Université", 1001);
  MaitreConference mcf("Martin", "Marie", "456 Avenue des Sciences", 1002);
  Autre autre("Durand", "Pierre", "789 Boulevard du Campus", 1003);

  // Test des getters
  std::cout << "1. Professeur:" << std::endl;
  std::cout << "   Nom: " << prof.getNom() << " " << prof.getPrenom()
            << std::endl;
  std::cout << "   ID: " << prof.getId() << std::endl;
  std::cout << "   Heures dues: " << prof.getNbHeuresDues() << "h" << std::endl;
  std::cout << "   Heures calculées: " << prof.calculerHeures() << "h"
            << std::endl
            << std::endl;

  std::cout << "2. Maître de Conférence:" << std::endl;
  std::cout << "   Nom: " << mcf.getNom() << " " << mcf.getPrenom()
            << std::endl;
  std::cout << "   ID: " << mcf.getId() << std::endl;
  std::cout << "   Heures dues: " << mcf.getNbHeuresDues() << "h" << std::endl;
  std::cout << "   Heures calculées: " << mcf.calculerHeures() << "h"
            << std::endl
            << std::endl;

  std::cout << "3. Autre:" << std::endl;
  std::cout << "   Nom: " << autre.getNom() << " " << autre.getPrenom()
            << std::endl;
  std::cout << "   ID: " << autre.getId() << std::endl;
  std::cout << "   Heures dues: " << autre.getNbHeuresDues() << "h"
            << std::endl;
  std::cout << "   Heures calculées: " << autre.calculerHeures() << "h"
            << std::endl
            << std::endl;

  // Test du polymorphisme avec un vecteur de pointeurs
  std::cout << "=== Test du polymorphisme ===" << std::endl;
  std::vector<std::unique_ptr<Enseignant>> enseignants;
  enseignants.push_back(
      std::make_unique<Professeur>("Leroy", "Sophie", "11 Rue Pasteur", 2001));
  enseignants.push_back(std::make_unique<MaitreConference>(
      "Bernard", "Luc", "22 Avenue Curie", 2002));
  enseignants.push_back(
      std::make_unique<Autre>("Moreau", "Claire", "33 Place Einstein", 2003));

  for (size_t i = 0; i < enseignants.size(); ++i) {
    std::cout << "Enseignant " << (i + 1) << ": " << enseignants[i]->getPrenom()
              << " " << enseignants[i]->getNom() << " - "
              << enseignants[i]->calculerHeures() << "h dues" << std::endl;
  }

  std::cout << std::endl << "=== Test réussi! ===" << std::endl;

  return 0;
}
