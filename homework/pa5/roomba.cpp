#include <iostream>
#include <string.h>
#include "roomba.hpp"
#include "Robot.hpp"

roomba::roomba(int creation_sequence_number)
    : Robot(2, 3, 10, "_" + std::to_string(creation_sequence_number)){}
int roomba::getDamage()
{
    int  damage = Robot::getDamage();
    std::cout << getType() << " attacks for " << damage << " points!" << std::endl;
    int damage_2=Robot::getDamage();
    std::cout << getType() << " attacks for " << damage_2 << " points!" << std::endl;
    return damage+damage_2;
}
std::string roomba::getType()
{
    std::string newK = "roomba" +name;
    return newK;
}
void roomba::setHitpoint(int damage)
{
    hit -=damage;
}
int roomba::getHit()
{
    return hit;
}