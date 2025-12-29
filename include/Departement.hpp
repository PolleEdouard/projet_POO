#ifndef DEPARTEMENT_HPP
#define DEPARTEMENT_HPP

#include "Enseignant.hpp"
#include "UE.hpp"
#include <string>
#include <vector>

/**
 * @brief Classe représentant un département universitaire
 *
 * Contient les enseignants rattachés et les UE sous sa responsabilité
 */
class Departement {
private:
  std::string nom;                       // Nom du département
  std::vector<Enseignant *> enseignants; // Enseignants rattachés
  std::vector<UE *> ues;                 // UE sous responsabilité

public:
  /**
   * @brief Constructeur
   * @param nom Nom du département
   */
  Departement(const std::string &nom);

  /**
   * @brief Destructeur (ne supprime PAS les objets contenus)
   */
  ~Departement();

  // Getters
  std::string getNom() const;
  const std::vector<Enseignant *> &getEnseignants() const;
  const std::vector<UE *> &getUEs() const;
  int getNbEnseignants() const;
  int getNbUEs() const;

  // Setters
  void setNom(const std::string &nom);

  // Gestion des enseignants
  void ajouterEnseignant(Enseignant *enseignant);
  void retirerEnseignant(Enseignant *enseignant);

  // Gestion des UE
  void ajouterUE(UE *ue);
  void retirerUE(UE *ue);
};

#endif
