#include <iostream>
#include <string.h>
#include "humanic.hpp"
#include "Robot.hpp"

humanic::humanic(){}
humanic::humanic(int newStrength, int newHit, std::string name) : Robot(3, newStrength, newHit, name) {}
// humanic robots have a 10% chance of inflicting
//  a tactical nuke attack which is an additional 50 damage points.
int humanic::getDamage()
{
    int damage = Robot::getDamage();
    if(rand() % 10 < 10) 
    {   
        return damage + 50;
    }
    else 
    return damage;
}