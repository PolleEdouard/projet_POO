#include "Intervention.hpp"

// Constructeur
Intervention::Intervention(Enseignant *enseignant, UE *ue, double heuresCM,
                           double heuresTD, double heuresTP)
    : enseignant(enseignant), ue(ue), heuresCM(heuresCM), heuresTD(heuresTD),
      heuresTP(heuresTP) {}

// Destructeur 
Intervention::~Intervention() {}

// Getters
Enseignant *Intervention::getEnseignant() const { return enseignant; }

UE *Intervention::getUE() const { return ue; }

double Intervention::getHeuresCM() const { return heuresCM; }

double Intervention::getHeuresTD() const { return heuresTD; }

double Intervention::getHeuresTP() const { return heuresTP; }

// Setters
void Intervention::setEnseignant(Enseignant *enseignant) {
  this->enseignant = enseignant;
}

void Intervention::setUE(UE *ue) { this->ue = ue; }

void Intervention::setHeuresCM(double heures) { this->heuresCM = heures; }

void Intervention::setHeuresTD(double heures) { this->heuresTD = heures; }

void Intervention::setHeuresTP(double heures) { this->heuresTP = heures; }

// Calcul du total des heures effectuées
double Intervention::calculerHeuresEffectuees() const {
  return heuresCM + heuresTD + heuresTP;
}

// Calcul de l'ETD effectué avec coefficients
double Intervention::calculerETDEffectue() const {
  double etdCM = heuresCM * 1.5;
  double etdTD = heuresTD * 1.0;
  double etdTP = heuresTP * (2.0 / 3.0);

  return etdCM + etdTD + etdTP;
}
