#ifndef ENSEIGNANT_HPP
#define ENSEIGNANT_HPP

#include <string>

/**
 * @brief Classe abstraite représentant un enseignant
 *
 * Cette classe sert de base pour tous les types d'enseignants.
 * Elle définit les attributs communs et une interface virtuelle pure.
 */
class Enseignant {
protected:
  std::string nom;
  std::string prenom;
  std::string adresse;
  int id;
  double nbHeuresDues;

public:
  /**
   * @brief Constructeur de la classe Enseignant
   * @param nom Nom de l'enseignant
   * @param prenom Prénom de l'enseignant
   * @param adresse Adresse de l'enseignant
   * @param id Identifiant unique de l'enseignant
   * @param nbHeuresDues Nombre d'heures dues par l'enseignant
   */
  Enseignant(const std::string &nom, const std::string &prenom,
             const std::string &adresse, int id, double nbHeuresDues);

  /**
   * @brief Destructeur virtuel (essentiel pour le polymorphisme)
   */
  virtual ~Enseignant();

  // Getters
  std::string getNom() const;
  std::string getPrenom() const;
  std::string getAdresse() const;
  int getId() const;
  double getNbHeuresDues() const;

  // Setters
  void setNom(const std::string &nom);
  void setPrenom(const std::string &prenom);
  void setAdresse(const std::string &adresse);
  void setId(int id);
  void setNbHeuresDues(double nbHeuresDues);

  /**
   * @brief Méthode virtuelle pure pour calculer les heures
   * @return Le nombre d'heures calculé
   *
   * Cette méthode doit être implémentée par toutes les classes dérivées.
   */
  virtual double calculerHeures() const = 0;
};

#endif
