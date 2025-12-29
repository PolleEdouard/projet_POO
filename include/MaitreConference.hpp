#ifndef MAITRECONFERENCE_HPP
#define MAITRECONFERENCE_HPP

#include "Enseignant.hpp"

/**
 * @brief Classe représentant un Maître de Conférence
 *
 * Un maître de conférence doit effectuer 192 heures par an.
 */
class MaitreConference : public Enseignant {
public:
  /**
   * @brief Constructeur de la classe MaitreConference
   * @param nom Nom du maître de conférence
   * @param prenom Prénom du maître de conférence
   * @param adresse Adresse du maître de conférence
   * @param id Identifiant unique du maître de conférence
   */
  MaitreConference(const std::string &nom, const std::string &prenom,
                   const std::string &adresse, int id);

  /**
   * @brief Destructeur
   */
  ~MaitreConference() override;

  /**
   * @brief Calcule les heures pour un maître de conférence
   * @return Le nombre d'heures dues (192)
   */
  double calculerHeures() const override;
};

#endif
