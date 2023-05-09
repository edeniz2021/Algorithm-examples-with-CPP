#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "humanic.hpp"

class robocop : public humanic {
public:
    robocop(int newStrength, int newHit, std::string name);
    std::string getType() override;
    int getDamage() override;
    char getSymbol() const override;
};

#endif // ROBOCOP_H
