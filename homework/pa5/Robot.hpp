#ifndef ROBOT_H
#define ROBOT_H

#include <string>

class Robot
{
public:
    Robot();
    Robot(int newType, int newStrength, int newHit, std::string newName);
    virtual std::string getType() = 0;
    virtual int getDamage() = 0;
    virtual char getSymbol() const = 0;

protected:
    int strength;
    int hit;
    std::string name;
    int type;
};

#endif 
