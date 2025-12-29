#include "Td.hpp"

Td::Td(double heures, int nbGroupes)
    : heures(heures), nbGroupes(nbGroupes) {}

double Td::getHeures() const {
    return heures;
}

int Td::getNbGroupes() const {
    return nbGroupes;
}

double Td::getCoefficient() const {
    return coefficient;
}

double Td::calculerETD() const {
    return nbGroupes * heures * coefficient;
}
