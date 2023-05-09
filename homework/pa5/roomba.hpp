#ifndef ROOMBA_H
#define ROOMBA_H

#include "Robot.hpp"

class roomba : public Robot {
public:
roomba();
    roomba(int newStrength, int newHit, std::string name);
    std::string getType() override;
    int getDamage() override;
    char getSymbol() const override;
};

#endif 
