#ifndef BULLDOZER_H
#define BULLDOZER_H

#include "Robot.hpp"

class bulldozer : public Robot {
public:
    bulldozer(int newStrength, int newHit, std::string name);
    std::string getType() override;
    int getDamage() override;
    char getSymbol() const override;
};

#endif // BULLDOZER_H
