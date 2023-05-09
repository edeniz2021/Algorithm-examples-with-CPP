#include <iostream>
#include <string.h>
#include "optimusprime.hpp"
#include "humanic.hpp"

using namespace std;

optimusprime::optimusprime(int newStrength, int newHit, string name):humanic(newStrength,newHit,name){ type = 0;}
//Setting up the desired algorithm for damage
//With a %15 chance OptimusPrime robots inflict
int optimusprime::getDamage()
{
    if ((rand( ) % 100) < 15)	
    {
		cout <<"OptimusPrime special double attack" <<endl;
        return humanic::getDamage() * 2;
	}

        cout <<"OptimusPrime normal attack" <<endl;
        return humanic::getDamage();
   
}
string optimusprime::getType(){
    return "optimusprime";
}
char optimusprime::getSymbol() const {
    return 'O';
}