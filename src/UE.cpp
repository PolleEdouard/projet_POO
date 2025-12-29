#include "UE.hpp"

// Constructeur
UE::UE(const std::string &nom, double heuresCm, int nbGroupesCm,
       double heuresTd, int nbGroupesTd, double heuresTp, int nbGroupesTp,
       Enseignant *responsable)
    : nom(nom), cm(heuresCm, nbGroupesCm), td(heuresTd, nbGroupesTd),
      tp(heuresTp, nbGroupesTp), responsable(responsable) {}

// Getters
std::string UE::getNom() const { return nom; }

Cm UE::getCm() const { return cm; }

Td UE::getTd() const { return td; }

Tp UE::getTp() const { return tp; }

Enseignant *UE::getResponsable() const { return responsable; }

// Setters
void UE::setNom(const std::string &nom) { this->nom = nom; }

void UE::setCm(const Cm &cm) { this->cm = cm; }

void UE::setTd(const Td &td) { this->td = td; }

void UE::setTp(const Tp &tp) { this->tp = tp; }

void UE::setResponsable(Enseignant *responsable) {
  this->responsable = responsable;
}

// Calcul du coût total ETD
double UE::calculerCoutTotalETD() const {
  double etdCm = cm.calculerETD(); // heures × groupes × 1.5
  double etdTd = td.calculerETD(); // heures × groupes × 1.0
  double etdTp = tp.calculerETD(); // heures × groupes × 2/3

  return etdCm + etdTd + etdTp;
}
