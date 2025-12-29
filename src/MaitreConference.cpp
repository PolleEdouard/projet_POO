#include "MaitreConference.hpp"

// Constructeur - initialise avec 192 heures dues
MaitreConference::MaitreConference(const std::string &nom,
                                   const std::string &prenom,
                                   const std::string &adresse, int id)
    : Enseignant(nom, prenom, adresse, id, 192.0) {}

// Destructeur
MaitreConference::~MaitreConference() {}

// Implémentation de la méthode virtuelle pure
double MaitreConference::calculerHeures() const { return nbHeuresDues; }
