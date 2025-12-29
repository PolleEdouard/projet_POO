#ifndef DIPLOME_HPP
#define DIPLOME_HPP

#include "Semestre.hpp"
#include <string>
#include <vector>

/**
 * @brief Classe représentant un diplôme universitaire
 *
 * Contient une collection de semestres qui composent le diplôme
 */
class Diplome {
private:
  std::string nom;                   // Nom du diplôme
  std::vector<Semestre *> semestres; // Liste des semestres

public:
  /**
   * @brief Constructeur
   * @param nom Nom du diplôme
   */
  Diplome(const std::string &nom);

  /**
   * @brief Destructeur (ne supprime PAS les semestres)
   */
  ~Diplome();

  // Getters
  std::string getNom() const;
  const std::vector<Semestre *> &getSemestres() const;
  int getNbSemestres() const;

  // Setters
  void setNom(const std::string &nom);

  // Gestion des semestres
  void ajouterSemestre(Semestre *semestre);
  void retirerSemestre(Semestre *semestre);
};

#endif
