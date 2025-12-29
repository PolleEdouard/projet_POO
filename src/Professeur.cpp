#include "Professeur.hpp"

// Constructeur - initialise avec 192 heures dues
Professeur::Professeur(const std::string &nom, const std::string &prenom,
                       const std::string &adresse, int id)
    : Enseignant(nom, prenom, adresse, id, 192.0) {}

// Destructeur
Professeur::~Professeur() {}

// Implémentation de la méthode virtuelle pure
double Professeur::calculerHeures() const { return nbHeuresDues; }
