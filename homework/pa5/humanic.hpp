#ifndef HUMANIC_H
#define HUMANIC_H

#include "Robot.hpp"

class humanic : public Robot {
public:
    humanic(int newStrength, int newHit, std::string name);
    std::string getType() override;
    int getDamage() override;
    char getSymbol() const override;
};

#endif // HUMANIC_H
