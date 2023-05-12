#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include "humanic.hpp"

class optimusprime : public humanic
{
public:
    optimusprime(int creation_sequence_number);
    std::string getType() override;
    int getDamage() override;
    void setHitpoint(int damage)override;
    int getHit()override;
};

#endif
