#include "Cm.hpp"

Cm::Cm(double heures, int nbGroupes)
    : heures(heures), nbGroupes(nbGroupes) {}

double Cm::getHeures() const {
    return heures;
}

int Cm::getNbGroupes() const {
    return nbGroupes;
}

double Cm::getCoefficient() const {
    return coefficient;
}

double Cm::calculerETD() const {
    return nbGroupes * heures * coefficient;
}
