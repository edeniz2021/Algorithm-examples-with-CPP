/*
Discussion: A variable in a polynomial does nothing but act as a placeholder for
the coefficients. Hence, the only interesting thing about polynomials is the array
of coefficients and the corresponding exponent. Think about the polynomial
         x*x*x + x + 1
         Where is the term in x*x ? One simple way to implement the polynomial class is to
use an array of type double to store the coefficients. The index of the array is the
exponent of the corresponding term. If a term is missing, then it simply has a zero
coefficient.
         There are techniques for representing polynomials of high degree with many miss-
ing terms. These use so-called sparse matrix techniques. Unless you already know
these techniques, or learn very quickly, do not use these techniques.
         Provide a default constructor, a copy constructor, and a parameterized constructor
that enables an arbitrary polynomial to be constructed.
         Supply an overloaded operator = and a destructor.
         Provide these operations:
polynomial + polynomial, constant + polynomial, polynomial + constant,
polynomial - polynomial, constant - polynomial, polynomial - constant.
polynomial * polynomial, constant * polynomial, polynomial * constant,
         Supply functions to assign and extract coefficients, indexed by exponent.
         Supply a function to evaluate the polynomial at a value of type double .
         You should decide whether to implement these functions as members, friends, or
standalone functions.*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Polynomial
{
public:
    Polynomial();
    Polynomial(const Polynomial &P);
    Polynomial(int n);
    ~Polynomial();
    Polynomial &operator+(const Polynomial &P);
    Polynomial &operator=(const Polynomial &P);
    Polynomial &operator-(const Polynomial &P);
    Polynomial &operator*(const Polynomial &P);
    double &operator[](int index);
    int getNum() const { return num; }

private:
    double *coeff;
    int num;
};
Polynomial::Polynomial()
{
    num = 0;
    coeff = new double[num];
}
Polynomial::Polynomial(int n)
{
    num = n;
    coeff = new double[num];
}
Polynomial::Polynomial(const Polynomial &P)
{
    num = P.num;
    coeff = new double[num];
    for (int i = 0; i < num; i++)
    {
        coeff[i] = P.coeff[i];
    }
}
double &Polynomial::operator[](int index)
{
    return coeff[index];
}
Polynomial &Polynomial::operator+(const Polynomial &P)
{
    Polynomial sum;
    if (num > P.num)
    {
        sum.num = num;
    }
    else
        sum.num = P.num;
    sum.coeff = new double[sum.num];
    for (int i = 0; i < sum.num; i++)
    {
        if (i < num)
        {
            sum.coeff[i] += coeff[i];
        }
        if (i < P.num)
        {
            sum.coeff[i] += coeff[i];
        }
    }
    return sum;
}
Polynomial &Polynomial::operator-(const Polynomial &P)
{
    Polynomial diff;
    if (num > P.num)
    {
        diff.num = num;
    }
    else
        diff.num = P.num;
    diff.coeff = new double[diff.num];
    for (int i = 0; i < diff.num; i++)
    {
        diff.coeff[i] = 0;
        diff.coeff[i] = P.coeff[i] - coeff[i];
    }
    return diff;
}
Polynomial &Polynomial::operator*(const Polynomial &P)
{
    Polynomial mult;
    mult.num = P.num + num;
    mult.coeff = new double[mult.num];
    for(int i=0;i<mult.num;i++)
    {
        mult.coeff[i] = 0;
    }
    for(int i=0;i<P.num;i++)
    {
        for(int j=0;j<num;j++)
        {
            mult.coeff[i+j] += P.coeff[i]*coeff[j];
        }
    }
    return mult;
}