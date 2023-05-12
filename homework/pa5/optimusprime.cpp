#include <iostream>
#include <string.h>
#include "optimusprime.hpp"
#include "humanic.hpp"

optimusprime::optimusprime(int creation_sequence_number)
    : humanic(100, 100, "_" + std::to_string(creation_sequence_number)) {}
// Setting up the desired algorithm for damage
// With a %15 chance OptimusPrime robots inflict
int optimusprime::getDamage()
{
    int damage=humanic::getDamage();
    if ((rand() % 100) < 15)
        damage*=2;
    std::cout << getType() << " attacks for " << damage << " points!" << std::endl;
    return damage;
}
std::string optimusprime::getType()
{
    std::string newK = "optimusprime" +name;
    return newK;
}
void optimusprime::setHitpoint(int damage)
{
    hit -=damage;
}
int optimusprime::getHit()
{
    return hit;
}
