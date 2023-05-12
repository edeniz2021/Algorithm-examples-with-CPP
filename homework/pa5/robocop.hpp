#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "humanic.hpp"

class robocop : public humanic {
public:
    robocop(int creation_sequence_number);
    std::string getType() override;
    int getDamage() override;
    void setHitpoint(int damage)override;
    int getHit()override;
};

#endif
