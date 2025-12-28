#ifndef TD_HPP
#define TD_HPP

class Td {
private:
    double heures;
    int nbGroupes;
    static constexpr double coefficient = 1.0;

public:
    Td(double heures = 0.0, int nbGroupes = 0);

    double getHeures() const;
    int getNbGroupes() const;
    double getCoefficient() const;

    double calculerETD() const;
};

#endif
