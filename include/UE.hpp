#ifndef UE_HPP
#define UE_HPP

#include "Cm.hpp"
#include "Enseignant.hpp"
#include "Td.hpp"
#include "Tp.hpp"
#include <string>

/**
 * @brief Classe représentant une Unité d'Enseignement (UE)
 *
 * Contient les volumes horaires pour CM, TD et TP avec leurs groupes
 * respectifs, ainsi qu'un pointeur vers l'enseignant responsable.
 */
class UE {
private:
  std::string nom;
  Cm cm;                   // Cours Magistraux
  Td td;                   // Travaux Dirigés
  Tp tp;                   // Travaux Pratiques
  Enseignant *responsable; // Pointeur vers l'enseignant responsable

public:
  /**
   * @brief Constructeur de la classe UE
   * @param nom Nom de l'UE
   * @param heuresCm Volume horaire des CM
   * @param nbGroupesCm Nombre de groupes pour les CM
   * @param heuresTd Volume horaire des TD
   * @param nbGroupesTd Nombre de groupes pour les TD
   * @param heuresTp Volume horaire des TP
   * @param nbGroupesTp Nombre de groupes pour les TP
   * @param responsable Pointeur vers l'enseignant responsable (optionnel)
   */
  UE(const std::string &nom, double heuresCm = 0.0, int nbGroupesCm = 0,
     double heuresTd = 0.0, int nbGroupesTd = 0, double heuresTp = 0.0,
     int nbGroupesTp = 0, Enseignant *responsable = nullptr);

  // Getters
  std::string getNom() const;
  Cm getCm() const;
  Td getTd() const;
  Tp getTp() const;
  Enseignant *getResponsable() const;

  // Setters
  void setNom(const std::string &nom);
  void setCm(const Cm &cm);
  void setTd(const Td &td);
  void setTp(const Tp &tp);
  void setResponsable(Enseignant *responsable);

  /**
   * @brief Calcule le coût total en Équivalent Temps Didactique (ETD)
   * @return Le total ETD calculé selon la formule: heures × groupes ×
   * coefficient
   *
   * Coefficients appliqués:
   * - CM: 1.5
   * - TD: 1.0
   * - TP: 2/3 (0.666...)
   */
  double calculerCoutTotalETD() const;
};

#endif
