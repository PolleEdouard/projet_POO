#include "Tp.hpp"

Tp::Tp(double heures, int nbGroupes)
    : heures(heures), nbGroupes(nbGroupes) {}

double Tp::getHeures() const {
    return heures;
}

int Tp::getNbGroupes() const {
    return nbGroupes;
}

double Tp::getCoefficient() const {
    return coefficient;
}

double Tp::calculerETD() const {
    return nbGroupes * heures * coefficient;
}
