/*Define a class named PrimeNumber that stores a prime number.
The default con- structor should set the prime number to 1. Add another constructor that allows the caller to set the prime number.
Also, add a function to get the prime number. Finally, overload the prefix and postfix ++ and −− operators so they return a Prime- Number object that is the next largest prime number (for ++) and the next smallest prime number (for −−).
For example, if the object’s prime number is set to 13, then invoking ++ should return a PrimeNumber object whose prime number is set to 17. Create an appropriate test program for the class.*/
#include <iostream>

using namespace std;

class PrimeNumber
{
public:
    PrimeNumber() : prime(1) {}
    PrimeNumber(int n) : prime(n) {}
    int get() const { return prime; }
    PrimeNumber &operator++();
    PrimeNumber operator++(int);
    PrimeNumber &operator--();
    PrimeNumber operator--(int);

private:
    int prime;
    bool isPrime(int n);
    int nextPrime;
};

bool PrimeNumber::isPrime(int n)//check the prime number
{
    if (n < 2)
        return false;

    for (int i = 2; i <n/2; ++i)
        if (n % i == 0)
            return false;

    return true;
}
PrimeNumber& PrimeNumber::operator++()//postfix increment
{
    prime++;
    while (!isPrime(prime)) {
        prime++;
    }
    return (*this);
}

PrimeNumber PrimeNumber::operator++(int)//prefix increment
{
    PrimeNumber temp(*this);
    prime++;
    while (!isPrime(prime)) {
        prime++;
    }
    return temp;
}

PrimeNumber& PrimeNumber::operator--()//postfix decrement
{
    prime--;
    while (!isPrime(prime)) {
        prime--;
    }
    return (*this);
}

PrimeNumber PrimeNumber::operator--(int)//postfix increment
{
    PrimeNumber temp(*this);
    prime--;
    while (!isPrime(prime)) {
        prime--;
    }
    return temp;
}

int main()
{
    PrimeNumber p1, p2(13);

    cout << "p1 = " << p1.get() << endl;
    cout << "p2 = " << p2.get() << endl;

    ++p2;
    cout << "p2 = " << p2.get() << endl;

    p2++;
    cout << "p2 = " << p2.get() << endl;

    --p2;
    cout << "p2 = " << p2.get() << endl;

    p2--;
    cout << "p2 = " << p2.get() << endl;

    return 0;
}
