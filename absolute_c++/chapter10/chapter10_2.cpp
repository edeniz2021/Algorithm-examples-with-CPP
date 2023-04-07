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
    friend const Polynomial operator+(const Polynomial &P, const Polynomial &O);
    Polynomial &operator=(const Polynomial &P);
    friend const Polynomial operator-(const Polynomial &P, const Polynomial &O);
    friend const Polynomial operator*(const Polynomial &P, const Polynomial &O);
    friend istream &operator>>(istream &in, Polynomial &P);
    double &operator[](int index);
    int getNum() const { return num; }
    double evaluate(double x);
    void print() const;

private:
    double *coeff;
    int num;
};
Polynomial::Polynomial()
{
    num = 0;
    coeff = new double[num];
    for (int i = 0; i <= num; i++)
    {
        coeff[i] = 0;
    }
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
const Polynomial operator+(const Polynomial &P, const Polynomial &O)
{
    Polynomial sum;
    if (O.num > P.num)
    {
        sum.num = O.num;
    }
    else
        sum.num = P.num;
    sum.coeff = new double[sum.num];
    for (int i = 0; i <= sum.num; i++)
    {
        if (i < O.num)
        {
            sum.coeff[i] += O.coeff[i];
        }
        if (i < P.num)
        {
            sum.coeff[i] += P.coeff[i];
        }
    }
    return sum;
}

const Polynomial operator-(const Polynomial &P, const Polynomial &O)
{
    Polynomial diff;
    if (O.num > P.num)
    {
        diff.num = O.num;
    }
    else
        diff.num = P.num;

    diff.coeff = new double[diff.num +1]; 
    for (int i = 0; i <= diff.num; i++)
    {
        diff.coeff[i] = 0;
        if (i < O.num)
        {
            diff.coeff[i] += P.coeff[i];

        }
        if (i < P.num)
        {
            diff.coeff[i] -= O.coeff[i];
        }
    }
    return diff;
}

const Polynomial operator*(const Polynomial &P, const Polynomial &O)
{
    Polynomial mult;
    mult.num = P.num + O.num;
    mult.coeff = new double[mult.num];
    for (int i = 0; i <= mult.num; i++)
    {
        mult.coeff[i] = 0;
    }
    for (int i = 0; i < P.num; i++)
    {
        for (int j = 0; j < O.num; j++)
        {
            mult.coeff[i + j] += P.coeff[i] * O.coeff[j];
        }
    }
    return mult;
}

Polynomial::~Polynomial()
{
    delete[] coeff;
}
Polynomial &Polynomial::operator=(const Polynomial &P)
{
    if (num != P.num)
    {
        num = P.num;
        coeff = new double[num];
    }
    for (int i = 0; i < num; i++)
    {
        coeff[i] = P.coeff[i];
    }
    return *this;
}

double Polynomial::evaluate(double x)
{
    double result = 0;
    for (int i = 0; i < num; i++)
    {
        result += coeff[i] * pow(x, i);
    }
    return result;
}
void Polynomial::print() const
{
    for (int i = 0; i < num; i++)
    {
        cout << coeff[i] << "x^" << i;
        if (i < num - 1)
        {
            cout << "+ ";
        }
    }
}
istream &operator>>(istream &in, Polynomial &P)
{
    cout << "Pow the Plynomial enter n:";
    in >> P.num;
    for (int i = 0; i < P.num; i++)
    {
        cout << "Enter X^" << i << " : ";
        in >> P.coeff[i];
    }
    return in;
}
int main()
{
    Polynomial p1, p2, p3,p4,p5;
    int a;
    double res = 0;
    cout << "First Polynomial" << endl;
    cin >> p1;
    p1.print();
    cout << endl;
    cout << "Second Polynomial" << endl;
    cin >> p2;
    p2.print();
    cout << endl;
    cout << "Enter value X: " << endl;
    cin >> a;
    p3 = p1 + p2;
    res = p3.evaluate(a);
    cout << "p1 + p2 = " << res << endl;
    p4 = p1 - p2;
    res = p4.evaluate(a);
    cout << "p1 - p2 = " << res << endl;
    p5 = p1 * p2;
    res = p5.evaluate(a);
    cout << "p1 * p2 = " << res << endl;
}