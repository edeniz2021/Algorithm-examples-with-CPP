#include <iostream>
#include <string.h>
#include "humanic.hpp"
#include "Robot.hpp"

using namespace std;
humanic::humanic(int newStrength, int newHit, string name) : Robot(3, newStrength, newHit, name) {}
// humanic robots have a 10% chance of inflicting
//  a tactical nuke attack which is an additional 50 damage points.
int humanic::getDamage()
{
    int damage = (rand() % strength) + 1;
    int nkDamage = (rand() % 10 == 0) ? 50 : 0;
    if (nkDamage > 0)
    {
        cout << name << " launches a tactical nuke for " << nkDamage << " points!" << endl;
    }
    return damage + nkDamage;
}
string humanic::getType()
{
    return "humanic";
}
char humanic::getSymbol() const
{
    return 'H';
}