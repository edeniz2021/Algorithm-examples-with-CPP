#include <iostream>
#include <string.h>
#include "bulldozer.hpp"
#include "Robot.hpp"

using namespace std;
bulldozer::bulldozer(int newStrength, int newHit,string newName):Robot( 3, newStrength, newHit, newName){}
int bulldozer::getDamage()
{
    int  damage = (rand() % strength) + 1;
    std::cout << getType() << " attacks for " << damage << " points!" << std::endl;
    return damage;
}
string bulldozer::getType(){
    return "bulldozer";
}
char bulldozer::getSymbol() const {
    return 'B';
}