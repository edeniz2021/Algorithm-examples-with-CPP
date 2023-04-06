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
#include <math.h>
using namespace std;
class Polynomial
{
private:
    double *coeff;
    int order;

public:
    int get_order() const
    {
        return order;
    }
    double get_coeff(int i)
    {
        return coeff[i];
    }
    Polynomial()
    {
        order = 0;
        coeff = new double[order + 1];
        for (int i = 0; i <= order; i++)
        {
            coeff[i] = 0;
        }
    }
    ~Polynomial();
    Polynomial(Polynomial &p);
    void get(Polynomial &p);
    double evaluate(double x);
    Polynomial &operator=(const Polynomial &p);
    friend const Polynomial operator+(const Polynomial &p1, const Polynomial &p2);
    friend const Polynomial operator-(const Polynomial &p1, const Polynomial &p2);
    friend const Polynomial operator*(const Polynomial &p1, const Polynomial &p2);
    friend istream &operator>>(istream &in, Polynomial &p);
};

void Polynomial ::get(Polynomial &p)
{
    for (int i = p.get_order() - 1; i > 0; i--)
    {
        cout << p.get_coeff(i) << "X^" << i << "+";
        if (i == 1)
        {
            cout << p.get_coeff(0);
        }
    }
}
double Polynomial ::evaluate(double x)
{
    double result = 0;
    for (int i = 0; i < order - 1; i++)
    {
        result += coeff[i] * pow(x, i);
    }

    return result;
}
istream &operator>>(istream &in, Polynomial &p)
{
    cout << "Order Poliynomial n:";
    in >> p.order;
    for (int i = 0; i < p.order; i++)
    {
        cout << "Enter coefficient X^" << i << ":";
        in >> p.coeff[i];
    }
    return in;
}
Polynomial ::Polynomial(Polynomial &p)
{
    order = p.get_order();
    coeff = new double[order + 1];
    for (int i = 0; i <= order; i++)
    {
        coeff[i] = p.get_coeff(i);
    }
}
Polynomial ::~Polynomial()
{
    delete[] coeff;
}
Polynomial &Polynomial::operator=(const Polynomial &p)
{
    if (order != p.order)
    {
        delete[] coeff;
        order = p.order;
        coeff = new double[order];
    }
    for (int i = 0; i < order; i++)
    {
        coeff[i] = p.coeff[i];
    }
    return *this;
}
const Polynomial operator+(const Polynomial &p1, const Polynomial &p2)
{
    Polynomial sum;
    if (p2.get_order() < p1.get_order())
    {
        sum.order = p1.get_order();
    }
    else
    {
        sum.order = p2.get_order();
    }
    delete[] sum.coeff;
    sum.coeff = new double[sum.order];
    for (int i = 0; i < sum.order; i++)
    {
        sum.coeff[i] = 0;
        if (i < p1.order)
        {
            sum.coeff[i] += p1.coeff[i];
        }
        if (i < p2.order)
        {
            sum.coeff[i] += p2.coeff[i];
        }
    }
    return sum;
}
const Polynomial operator-(const Polynomial &p1, const Polynomial &p2)
{
    Polynomial dif;
    if (p1.get_order() < p2.get_order())
    {
        dif.order = p2.get_order();
    }
    else
    {
        dif.order = p1.get_order();
    }
    delete[] dif.coeff;
    dif.coeff = new double[dif.order];
    for (int i = 0; i < dif.order; i++)
    {
        dif.coeff[i] = 0;
        dif.coeff[i] = p1.coeff[i] - p2.coeff[i];
    }
    return dif;
}
const Polynomial operator*(const Polynomial &p1, const Polynomial &p2)
{
    Polynomial mult;
    mult.order = p1.get_order() * p2.get_order();
    delete[] mult.coeff;
    mult.coeff = new double[mult.order];
    for (int i = 0; i < mult.order; i++)
    {
        mult.coeff[i] = 0;
    }
    for (int i = 0; i < p1.get_order(); i++)
    {

        for (int j = 0; j < p2.get_order(); j++)
        {
            mult.coeff[i + j] += p1.coeff[i] * p2.coeff[j];
        }
    }
    return mult;
}

int main()
{
    Polynomial pol1, pol2, result;
    double x;
    double res;
    cout << "*First Polynomial*" << endl;
    cin >> pol1;
    pol1.get(pol1);
    cout << endl;
    cout << "*Second Polynomial*" << endl;
    cin >> pol2;
    pol2.get(pol2);
    cout << endl;
    cout << "Enter value X: ";
    cin >> x;
    res = pol1.evaluate(x);
    cout << "First Polynmial for x value :" << res << endl;
    res = pol2.evaluate(x);
    cout << "Second Polynmial for x value :" << res << endl;
    cout << "First Polynom and second polynom addition:";
    result = pol1 + pol2;
    result.get(result);
    res = result.evaluate(x);
    cout << endl;
    cout << "First Polynom and second polynom addition for x value:" << res;
    cout << endl;
    res = result.evaluate(x);
    cout << "First Polynom and second polynom subtraction:";
    result = pol1 - pol2;
    result.get(result);
    cout << endl;
    cout << "First Polynom and second polynom subtraction for x value:" << res;
    cout << endl;
    result = pol1 * pol2;
    cout << "First Polynom and second polynom multiplication:";
    result.get(result);
    res = result.evaluate(x);
    cout << endl;
    cout << "First Polynom and second polynom multiplication for x value:" << res;
}
