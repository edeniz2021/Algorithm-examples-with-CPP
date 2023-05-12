#include "Robot.hpp"
#include <iostream>
Robot::Robot() : type(3), strength(10), hit(10) {}

Robot::Robot(int newType, int newStrength, int newHit, std::string newName)
{
    type = newType;
    strength = newStrength;
    hit = newHit;
    name = newName;
}
Robot::~Robot()
{
}
std::string Robot::getType()
{
    switch (type)
    {
    case 0:
        return "optimusprime";
    case 1:
        return "robocop";
    case 2:
        return "roomba";
    case 3:
        return "bulldozer";
    }
    return "unknown";
}
int Robot::getDamage()
{
    int  damage = (rand() % strength) + 1;
    return damage;
}
