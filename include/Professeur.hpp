#ifndef PROFESSEUR_HPP
#define PROFESSEUR_HPP

#include "Enseignant.hpp"

/**
 * @brief Classe représentant un Professeur
 *
 * Un professeur doit effectuer 192 heures par an.
 */
class Professeur : public Enseignant {
public:
  /**
   * @brief Constructeur de la classe Professeur
   * @param nom Nom du professeur
   * @param prenom Prénom du professeur
   * @param adresse Adresse du professeur
   * @param id Identifiant unique du professeur
   */
  Professeur(const std::string &nom, const std::string &prenom,
             const std::string &adresse, int id);

  /**
   * @brief Destructeur
   */
  ~Professeur() override;

  /**
   * @brief Calcule les heures pour un professeur
   * @return Le nombre d'heures dues (192)
   */
  double calculerHeures() const override;
};

#endif
