#include "Diplome.hpp"
#include <algorithm>

// Constructeur
Diplome::Diplome(const std::string &nom) : nom(nom) {}

// Destructeur 
Diplome::~Diplome() {}

// Getters
std::string Diplome::getNom() const { return nom; }

const std::vector<Semestre *> &Diplome::getSemestres() const {
  return semestres;
}

int Diplome::getNbSemestres() const {
  return static_cast<int>(semestres.size());
}

// Setters
void Diplome::setNom(const std::string &nom) { this->nom = nom; }

// Gestion des semestres
void Diplome::ajouterSemestre(Semestre *semestre) {
  if (semestre != nullptr) {
    semestres.push_back(semestre);
  }
}

void Diplome::retirerSemestre(Semestre *semestre) {
  auto it = std::find(semestres.begin(), semestres.end(), semestre);
  if (it != semestres.end()) {
    semestres.erase(it);
  }
}
