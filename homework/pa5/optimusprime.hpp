#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include "humanic.hpp"

class optimusprime : public humanic
{
public:
    optimusprime(int newStrength, int newHit, std::string name);
    std::string getType() override;
    int getDamage() override;
    char getSymbol() const override;
};

#endif // OPTIMUSPRIME_H
