#include "Semestre.hpp"
#include "Inscription.hpp"
#include <algorithm>

// Constructeur
Semestre::Semestre(int numero, const std::string &annee)
    : numero(numero), annee(annee) {}

// Destructeur (ne supprime PAS les inscriptions)
Semestre::~Semestre() {}

// Getters
int Semestre::getNumero() const { return numero; }

std::string Semestre::getAnnee() const { return annee; }

const std::vector<Inscription *> &Semestre::getInscriptions() const {
  return inscriptions;
}

int Semestre::getNbInscriptions() const {
  return static_cast<int>(inscriptions.size());
}

// Setters
void Semestre::setNumero(int numero) { this->numero = numero; }

void Semestre::setAnnee(const std::string &annee) { this->annee = annee; }

// Gestion des inscriptions
void Semestre::ajouterInscription(Inscription *inscription) {
  if (inscription != nullptr) {
    inscriptions.push_back(inscription);
  }
}

void Semestre::retirerInscription(Inscription *inscription) {
  auto it = std::find(inscriptions.begin(), inscriptions.end(), inscription);
  if (it != inscriptions.end()) {
    inscriptions.erase(it);
  }
}
