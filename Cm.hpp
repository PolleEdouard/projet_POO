#ifndef CM_HPP
#define CM_HPP

class Cm {
private:
    double heures;
    int nbGroupes;
    static constexpr double coefficient = 1.5;

public:
    Cm(double heures = 0.0, int nbGroupes = 0);

    double getHeures() const;
    int getNbGroupes() const;
    double getCoefficient() const;

    double calculerETD() const;
};

#endif
