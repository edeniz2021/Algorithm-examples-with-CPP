/*Define a class named PrimeNumber that stores a prime number. 
The default con- structor should set the prime number to 1. Add another constructor that allows the caller to set the prime number. 
Also, add a function to get the prime number. Finally, overload the prefix and postfix ++ and −− operators so they return a Prime- Number object that is the next largest prime number (for ++) and the next smallest prime number (for −−). 
For example, if the object’s prime number is set to 13, then invoking ++ should return a PrimeNumber object whose prime number is set to 17. Create an appropriate test program for the class.*/
#include <iostream>
using namespace std;

class PrimeNumber
{
    public:
    PrimeNumber();
    PrimeNumber(int num);
    void setPrime(int num);
    int getPrime()const{ return prime; }
    private:
    int prime;
};
PrimeNumber::PrimeNumber()
{
    prime = 0;
}
PrimeNumber::PrimeNumber(int num)
{
    prime = num;
}
void PrimeNumber::setPrime(int num)
{
    prime = num;
}


