#ifndef BULLDOZER_H
#define BULLDOZER_H

#include "Robot.hpp"

class bulldozer : public Robot {
public:
    bulldozer(int creation_sequence_number);
    std::string getType() override;
    int getDamage() override;
    void setHitpoint(int damage)override;
    int getHit()override;
};

#endif 
