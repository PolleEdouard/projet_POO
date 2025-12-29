#ifndef INTERVENTION_HPP
#define INTERVENTION_HPP

#include "Enseignant.hpp"
#include "UE.hpp"

/**
 * @brief Classe d'association entre Enseignant et UE
 *
 * Représente l'intervention d'un enseignant dans une UE
 * avec les heures effectuées pour chaque type de cours.
 */
class Intervention {
private:
  Enseignant *enseignant; // Pointeur vers l'enseignant (pas de propriété)
  UE *ue;                 // Pointeur vers l'UE (pas de propriété)
  double heuresCM;        // Heures de CM effectuées
  double heuresTD;        // Heures de TD effectuées
  double heuresTP;        // Heures de TP effectuées

public:
  /**
   * @brief Constructeur
   * @param enseignant Pointeur vers l'enseignant
   * @param ue Pointeur vers l'UE
   * @param heuresCM Heures de CM effectuées
   * @param heuresTD Heures de TD effectuées
   * @param heuresTP Heures de TP effectuées
   */
  Intervention(Enseignant *enseignant, UE *ue, double heuresCM = 0.0,
               double heuresTD = 0.0, double heuresTP = 0.0);

  /**
   * @brief Destructeur (ne supprime PAS les objets pointés)
   */
  ~Intervention();

  // Getters
  Enseignant *getEnseignant() const;
  UE *getUE() const;
  double getHeuresCM() const;
  double getHeuresTD() const;
  double getHeuresTP() const;

  // Setters
  void setEnseignant(Enseignant *enseignant);
  void setUE(UE *ue);
  void setHeuresCM(double heures);
  void setHeuresTD(double heures);
  void setHeuresTP(double heures);

  /**
   * @brief Calcule le total des heures effectuées
   * @return Total des heures (CM + TD + TP)
   */
  double calculerHeuresEffectuees() const;

  /**
   * @brief Calcule l'ETD effectué avec les coefficients
   * @return ETD total (CM×1.5 + TD×1.0 + TP×2/3)
   */
  double calculerETDEffectue() const;
};

#endif
