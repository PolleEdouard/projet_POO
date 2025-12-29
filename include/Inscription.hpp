#ifndef INSCRIPTION_HPP
#define INSCRIPTION_HPP

#include "Semestre.hpp"
#include "UE.hpp"

/**
 * @brief Classe d'association entre UE et Semestre
 *
 * Représente l'inscription d'étudiants à une UE pour un semestre donné.
 */
class Inscription {
private:
  UE *ue;             // Pointeur vers l'UE (pas de propriété)
  Semestre *semestre; // Pointeur vers le semestre (pas de propriété)
  int nbEtudiants;    // Nombre d'étudiants inscrits

public:
  /**
   * @brief Constructeur
   * @param ue Pointeur vers l'UE
   * @param semestre Pointeur vers le semestre
   * @param nbEtudiants Nombre d'étudiants inscrits
   */
  Inscription(UE *ue, Semestre *semestre, int nbEtudiants = 0);

  /**
   * @brief Destructeur (ne supprime PAS les objets pointés)
   */
  ~Inscription();

  // Getters
  UE *getUE() const;
  Semestre *getSemestre() const;
  int getNbEtudiants() const;

  // Setters
  void setUE(UE *ue);
  void setSemestre(Semestre *semestre);
  void setNbEtudiants(int nbEtudiants);
};

#endif
