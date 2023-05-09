#include <iostream>
#include <string.h>
#include "robocop.hpp"
#include "humanic.hpp"

using namespace std;

robocop::robocop(int newStrength, int newHit, string name):humanic(newStrength,newHit,name){ type = 0;}
//Setting up the desired algorithm for damage
//With a %15 chance OptimusPrime robots inflict
int robocop::getDamage()
{
    if ((rand( ) % 100) < 15)	
    {
		cout <<"robocop special double attack" <<endl;
        return humanic::getDamage() * 2;
	}

        cout <<"robocop normal attack" <<endl;
        return humanic::getDamage();
   
}
string robocop::getType(){
    return "robocop";
}
char robocop::getSymbol() const {
    return 'C';
}