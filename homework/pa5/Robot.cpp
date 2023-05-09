#include "Robot.hpp"
#include <iostream>
Robot::Robot(): type(3), strength(10), hit(10) {}

Robot::Robot(int newType, int newStrength, int newHit, std::string newName)
{
    type = newType;
    strength = newStrength;
    hit = newHit;
    name = newName;
}
/*std::string Robot::getType()
{
    return "Robot";
}

int Robot::getDamage()
{
    int  damage = (rand() % strength) + 1;
    std::cout << getType() << " attacks for " << damage << " points!" << std::endl;
    return damage;
}*/
