#ifndef AUTRE_HPP
#define AUTRE_HPP

#include "Enseignant.hpp"

/**
 * @brief Classe représentant un autre type d'enseignant
 *
 * Cette catégorie d'enseignants doit effectuer 384 heures par an.
 */
class Autre : public Enseignant {
public:
  /**
   * @brief Constructeur de la classe Autre
   * @param nom Nom de l'enseignant
   * @param prenom Prénom de l'enseignant
   * @param adresse Adresse de l'enseignant
   * @param id Identifiant unique de l'enseignant
   */
  Autre(const std::string &nom, const std::string &prenom,
        const std::string &adresse, int id);

  /**
   * @brief Destructeur
   */
  ~Autre() override;

  /**
   * @brief Calcule les heures pour un enseignant autre
   * @return Le nombre d'heures dues (384)
   */
  double calculerHeures() const override;
};

#endif
