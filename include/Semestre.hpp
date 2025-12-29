#ifndef SEMESTRE_HPP
#define SEMESTRE_HPP

#include <string>
#include <vector>

// Forward declaration pour éviter dépendance circulaire
class Inscription;

/**
 * @brief Classe représentant un semestre académique
 *
 * Contient une collection d'inscriptions (UE inscrites pour ce semestre)
 */
class Semestre {
private:
  int numero;                              // Numéro du semestre (1 ou 2)
  std::string annee;                       // Année académique (ex: "2024-2025")
  std::vector<Inscription *> inscriptions; // Liste des inscriptions

public:
  /**
   * @brief Constructeur
   * @param numero Numéro du semestre (1 ou 2)
   * @param annee Année académique
   */
  Semestre(int numero, const std::string &annee);

  /**
   * @brief Destructeur
   */
  ~Semestre();

  // Getters
  int getNumero() const;
  std::string getAnnee() const;
  const std::vector<Inscription *> &getInscriptions() const;
  int getNbInscriptions() const;

  // Setters
  void setNumero(int numero);
  void setAnnee(const std::string &annee);

  // Gestion des inscriptions
  void ajouterInscription(Inscription *inscription);
  void retirerInscription(Inscription *inscription);
};

#endif
