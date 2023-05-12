#ifndef ROOMBA_H
#define ROOMBA_H

#include "Robot.hpp"

class roomba : public Robot {
public:
    roomba(int creation_sequence_number);
    std::string getType() override;
    int getDamage() override;
    void setHitpoint(int damage)override;
    int getHit()override;
};

#endif 
