#include "Semestre.hpp"
#include "Inscription.hpp"
#include <algorithm>
#include <numeric>

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

// Calcul du coût total du semestre
double Semestre::calculerCout() const {
  return std::accumulate(inscriptions.begin(), inscriptions.end(), 0.0,
                         [](double total, const Inscription *inscr) {
                           if (inscr && inscr->getUE()) {
                             // Coût ETD de l'UE × nombre d'inscrits dans ce
                             // semestre
                             double coutUE =
                                 inscr->getUE()->calculerCoutTotalETD();
                             int nbInscrits = inscr->getNbEtudiants();
                             return total + (coutUE * nbInscrits);
                           }
                           return total;
                         });
}
