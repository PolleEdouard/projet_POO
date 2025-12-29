#ifndef TP_HPP
#define TP_HPP

class Tp {
private:
    double heures;
    int nbGroupes;
    static constexpr double coefficient = 2.0 / 3.0;

public:
    Tp(double heures = 0.0, int nbGroupes = 0);

    double getHeures() const;
    int getNbGroupes() const;
    double getCoefficient() const;

    double calculerETD() const;
};

#endif
