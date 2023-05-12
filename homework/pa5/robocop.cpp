#include <iostream>
#include <string.h>
#include "robocop.hpp"
#include "humanic.hpp"

robocop::robocop(int creation_sequence_number)
    : humanic(30, 40, "_" + std::to_string(creation_sequence_number)) {}
//Setting up the desired algorithm for damage
//With a %15 chance OptimusPrime robots inflict
int robocop::getDamage()
{
    int damage = humanic::getDamage();
    std::cout << getType() << " attacks for " << damage << " points!" << std::endl;
    return damage;  
}
std::string robocop::getType(){
    std::string newK = "robocop" +name;
    return newK;
}
void robocop::setHitpoint(int damage)
{
    hit -=damage;
}
int robocop::getHit()
{
    return hit;
}