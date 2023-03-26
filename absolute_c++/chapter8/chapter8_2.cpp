/*Define a class for rational numbers. A rational number is a number that can be represented as the quotient of two integers. For example, 1/2, 3/4, 64/2, and so forth are all rational numbers.
(By 1/2 and so on we mean the everyday fraction, not the integer division this expression would produce in a C++ program.)
Represent rational numbers as two values of type int, one for the numerator and one for the denominator. Call the class Rational.
Include a constructor with two arguments that can be used to set the member variables of an object to any legitimate values.
Also include a constructor that has only a single parameter of type int; call this single parameter wholeNumber and define the constructor so that the object will be initialized to the rational number wholeNumber/1.
Include a default constructor that initializes an object to 0 (that is, to 0/1).
Overload the input and output operators >> and <<. Numbers are to be input and output in the form 1/2, 15/32, 300/401, and so forth. Note that the numerator, the denominator, or both may contain a minus sign, so −1/2, 15/−32, and −300/−401 are also possible inputs.
Overload all the following operators so that they correctly apply to the type Rational: ==, <, <=, >, >=, +, −, *, and /. Write a test program to test your class.
Hints: Two rational numbers a/b and c/d are equal if a*d equals c*b. If b and d are positive rational numbers, a/b is less than c/d provided a*d is less than c*b.
You should include a function to normalize the values stored so that, after normalization, the denominator is positive and the numerator and denominator are as small as possible.
For example, after normalization 4/-8 would be represented the same as −1/2.*/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Rational
{
public:
    Rational();
    Rational(int n, int d);
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int n);
    void setDenominator(int d);
    const Rational operator+(const Rational &R);
    const Rational operator-(const Rational &R);
    const Rational operator*(const Rational &R);
    const Rational operator/(const Rational &R);
    bool operator<(const Rational &R) const;
    bool operator==(const Rational &R) const;
    void normalize();
    void printRational() const;
    friend ostream &operator<<(ostream &outputStream,const Rational & R);

private:
    int numerator;
    int denominator;
};

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int n, int d)
{
    numerator = n;
    denominator = d;
    normalize();
}

void Rational::setDenominator(int d)
{
    denominator = d;
    normalize();
}

void Rational::setNumerator(int n)
{
    numerator = n;
    normalize();
}

int Rational::getDenominator() const
{
    return denominator;
}

int Rational::getNumerator() const
{
    return numerator;
}

const Rational Rational::operator+(const Rational &R)
{
    Rational sum;
    sum.numerator = R.getNumerator() * denominator + numerator * R.getDenominator();
    sum.denominator = R.getDenominator() * denominator;
    sum.normalize();
    return sum;
}

const Rational Rational::operator-(const Rational &R)
{
    Rational diff;
    diff.numerator = R.getNumerator() * denominator - numerator * R.getDenominator();
    diff.denominator = R.getDenominator() * denominator;
    diff.normalize();
    return diff;
}

const Rational Rational::operator*(const Rational &R)
{
    Rational prod;
    prod.numerator = R.getNumerator() * numerator;
    prod.denominator = R.getDenominator() * denominator;
    prod.normalize();
    return prod;
}

const Rational Rational::operator/(const Rational &R)
{
    Rational quot;
    quot.numerator = R.getDenominator() * numerator;
    quot.denominator = R.getNumerator() * denominator;
    quot.normalize();
    return quot;
}

bool Rational::operator<(const Rational &R) const
{
    return numerator * R.getDenominator() < R.getNumerator() * denominator;
}

bool Rational::operator==(const Rational &R) const
{
    return numerator * R.getDenominator() == R.getNumerator() * denominator;
}

void Rational::normalize()
{
    if (denominator == 0)
    {
        cerr << "Error: denominator cannot be zero." << endl;
        exit(1);
    }
    if (numerator == 0)
    {
        denominator = 1;
    }
    else
    {
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
}
void Rational::printRational() const
{
    cout << getNumerator() << "/" << getDenominator();
}
int main()
{
    Rational R(1, 2);
    Rational S(3, 5);
    Rational result;
    result = R + S;
    cout << R.printRational() << " + " << S.printRational() << " = " << result.printRational() << endl;
    result = R - S;
    cout << R.printRational() << " - " << S.printRational() << " = " << result.printRational() << endl;
    result = R * S;
    cout << R.printRational() << " * " << S.printRational() << " = " << result.printRational() << endl;
    result = R / S;
    cout << R.printRational() << " / " << S.printRational() << " = " << result.printRational() << endl;
}