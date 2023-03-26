/* Modify the definiti on of the class Money shown in Display8.5 so that the following are added:
a. The operators <, <=, >, and >= have each been overloaded to apply to the type Money. (Hint: See Self-Test Exercise 8.)
b.The following member function has been added to the class definition. (We show the function declaration as it should appear in the class definition. The definition of the function itself will include the qualifier Money::.)
const Money percent(int percentFigure) const;
//Returns a percentage of the money amount in the calling //object. For example, if percentFigure is 10, then the value //returned is 10% of the amount of money represented by the //calling object.
For example, if purse is an object of type Money whose value represents the amount $100.10, then the call
purse.percent(10);
returns 10% of $100.10; that is, it returns a value of type Money that represents the amount $10.01.*/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
// Class for amounts of money in U.S. currency 6
class Money
{
public:
    Money();
    Money(double amount);
    Money(int theDollars, int theCents);
    Money(int theDollars);
    double getAmount() const;
    int getDollars() const;
    int getCents() const;

    friend const Money operator+(const Money &amount1, const Money &amount2);
    friend const Money operator-(const Money &amount1, const Money &amount2);
    friend bool operator==(const Money &amount, const Money &amount2);
    friend const Money operator-(const Money &amount);
    friend bool operator<(const Money &amount1, const Money &amount2);
    friend bool operator<=(const Money &amount1, const Money &amount2);
    friend bool operator>(const Money &amount1, const Money &amount2);
    friend bool operator>=(const Money &amount1, const Money &amount2);
    friend ostream &operator<<(ostream &outputStream,const Money &amount);
    friend istream &operator>>(istream &inputStream, Money &amount);

private:
    // A negative amount is represented as negative dollars
    // and negative cents. Negative $4.50 is represented as
    //-4 and −50.
    int dollars, cents;
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
};
bool operator==(const Money &amount1, const Money &amount2)
{
    return (amount1.dollars == amount2.dollars && amount1.cents == amount2.cents);
}

const Money operator-(const Money &amount)
{
    return Money(-amount.dollars, -amount.cents);
}

bool operator<(const Money &amount1, const Money &amount2)
{
    if (amount1.dollars < amount2.dollars)
        return true;
    else if (amount1.dollars == amount2.dollars)
        return (amount1.cents < amount2.cents);
    else
        return false;
}

bool operator<=(const Money &amount1, const Money &amount2)
{
    return (amount1 < amount2 || amount1 == amount2);
}

bool operator>(const Money &amount1, const Money &amount2)
{
    return !(amount1 <= amount2);
}

bool operator>=(const Money &amount1, const Money &amount2)
{
    return !(amount1 < amount2);
}
ostream &operator<<(ostream &outputStream, const Money &amount)
{
    int absDollars = abs(amount.dollars);
    int absCents = abs(amount.cents);
    if (amount.dollars < 0 || amount.cents < 0)
        // accounts for dollars == 0 or cents == 0
        outputStream << "$-";
    else
        outputStream << '$';
    outputStream << absDollars;
    if (absCents >= 10)
        outputStream << '.' << absCents;
    else
        outputStream << '.' << '0' << absCents;
    return outputStream;
}
istream &operator>>(istream &inputStream, Money &amount)
{
    char dollarSign;
    inputStream >> dollarSign; // hopefully
    if (dollarSign != '$')
    {
        cout << "No dollar sign in Money input.\n";
        exit(1);
    }
    double amountAsDouble;
    inputStream >> amountAsDouble;
    amount.dollars = amount.dollarsPart(amountAsDouble);
    amount.cents = amount.centsPart(amountAsDouble);
    return inputStream;
}
int main()
{

    Money yourAmount, myAmount(10, 9);
    cout << "Enter an amount of money: ";
    if (yourAmount == myAmount)
        cout << "We have the same amounts.\n";
    else
        cout << "One of us is richer.\n";
    Money ourAmount = yourAmount + myAmount;
    cout << yourAmount << " + " << myAmount
         << " equals " << ourAmount << endl;
    Money diffAmount = yourAmount - myAmount;
    cout << yourAmount << " - " << myAmount
         << " equals " << diffAmount << endl;
}