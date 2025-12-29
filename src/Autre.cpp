#include "Autre.hpp"

// Constructeur - initialise avec 384 heures dues
Autre::Autre(const std::string &nom, const std::string &prenom,
             const std::string &adresse, int id)
    : Enseignant(nom, prenom, adresse, id, 384.0) {}

// Destructeur
Autre::~Autre() {}

// Implémentation de la méthode virtuelle pure
double Autre::calculerHeures() const { return nbHeuresDues; }
