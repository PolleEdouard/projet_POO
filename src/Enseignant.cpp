#include "Enseignant.hpp"

// Constructeur
Enseignant::Enseignant(const std::string &nom, const std::string &prenom,
                       const std::string &adresse, int id, double nbHeuresDues)
    : nom(nom), prenom(prenom), adresse(adresse), id(id),
      nbHeuresDues(nbHeuresDues) {}

// Destructeur virtuel
Enseignant::~Enseignant() {}

// Getters
std::string Enseignant::getNom() const { return nom; }

std::string Enseignant::getPrenom() const { return prenom; }

std::string Enseignant::getAdresse() const { return adresse; }

int Enseignant::getId() const { return id; }

double Enseignant::getNbHeuresDues() const { return nbHeuresDues; }

// Setters
void Enseignant::setNom(const std::string &nom) { this->nom = nom; }

void Enseignant::setPrenom(const std::string &prenom) { this->prenom = prenom; }

void Enseignant::setAdresse(const std::string &adresse) {
  this->adresse = adresse;
}

void Enseignant::setId(int id) { this->id = id; }

void Enseignant::setNbHeuresDues(double nbHeuresDues) {
  this->nbHeuresDues = nbHeuresDues;
}
