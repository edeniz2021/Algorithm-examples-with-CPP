#include <iostream>
#include <string.h>
#include "roomba.hpp"
#include "Robot.hpp"

using namespace std;
roomba::roomba(int newStrength, int newHit, string name) : Robot( 2, newStrength, newHit, name) {}
int roomba::getDamage()
{
    int  damage = (rand() % strength) + 1;
    std::cout << getType() << " attacks for " << damage << " points!" << std::endl;
    return damage*2;
}

string roomba::getType()
{
    return "roomba";
}
char roomba::getSymbol() const {
    return 'R';
}