#include "Inscription.hpp"

// Constructeur
Inscription::Inscription(UE *ue, Semestre *semestre, int nbEtudiants)
    : ue(ue), semestre(semestre), nbEtudiants(nbEtudiants) {}

// Destructeur
Inscription::~Inscription() {}

// Getters
UE *Inscription::getUE() const { return ue; }

Semestre *Inscription::getSemestre() const { return semestre; }

int Inscription::getNbEtudiants() const { return nbEtudiants; }

// Setters
void Inscription::setUE(UE *ue) { this->ue = ue; }

void Inscription::setSemestre(Semestre *semestre) { this->semestre = semestre; }

void Inscription::setNbEtudiants(int nbEtudiants) {
  this->nbEtudiants = nbEtudiants;
}
