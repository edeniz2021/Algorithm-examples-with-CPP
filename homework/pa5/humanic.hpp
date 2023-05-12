#ifndef HUMANIC_H
#define HUMANIC_H

#include "Robot.hpp"

class humanic : public Robot {
public:
humanic();
    humanic(int newStrength, int newHit, std::string name);
    int getDamage() override;
};

#endif 
