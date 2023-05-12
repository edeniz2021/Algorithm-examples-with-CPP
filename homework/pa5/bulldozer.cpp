#include <iostream>
#include <string.h>
#include "bulldozer.hpp"
#include "Robot.hpp"

bulldozer::bulldozer(int creation_sequence_number)
    : Robot(3, 50, 200, "_" + std::to_string(creation_sequence_number)){}
int bulldozer::getDamage()
{
    int damage=Robot::getDamage();
    std::cout << getType() << " attacks for " << damage << " points!" << std::endl;
    return damage;
}
std::string bulldozer::getType(){
    std::string newK = "bulldozer" +name;
    return newK;
}
void bulldozer::setHitpoint(int damage)
{
    hit -=damage;
}
int bulldozer::getHit()
{
    return hit;
}