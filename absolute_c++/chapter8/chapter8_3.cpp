/*Define a class for complex numbers. A complex number is a number of the form
a + b*i
 where for our purposes, a and b are numbers of type double , and i is a number
that represents the quantity root(-1) . Represent a complex number as two values of type double . Name the member variables real and imaginary . (The variable
for the number that is multiplied by i is the one called imaginary .) Call
the class Complex . Include a constructor with two parameters of type double
that can be used to set the member variables of an object to any values. Include a
constructor that has only a single parameter of type double ; call this parameter
realPart and define the constructor so that the object will be initialized to
realPart + 0*i . Include a default constructor that initializes an object to 0 (that is, to
0 + 0*i ). Overload all the following operators so that they correctly apply to the
type Complex : == , + , - , * , >> , and << . You should also write a test program to test
your class. Hints: To add or subtract two complex numbers, add or subtract the
two member variables of type double . The product of two complex numbers is
given by the following formula:
(a + b*i)*(c + d*i) = = (a*c - b*d) + (a*d + b*c)*i
In the interface file, you should define a constant i as follows:
const Complex i(0, 1);
This defined constant i will be the same as the i discussed above. */

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Complex
{
public:
    Complex();
    Complex(double r, double i);
    Complex operator+(const Complex &C);
    Complex operator-(const Complex &C);
    Complex operator*(const Complex &C);
    bool operator==(const Complex &C);
    double getReal() const { return real; }
    double getImagine() const { return imaginary; }
    void setReal(double r) { real = r; }
    void setImagine(double i) { imaginary = i; }
    friend ostream &operator<<(ostream &outputStream, const Complex &C);
    friend istream &operator<<(istream &inputStream, Complex &C);

private:
    double real;
    double imaginary;
};
const Complex i(0, 1);
Complex::Complex()
{
    real = 0;
    imaginary = 0;
}
Complex::Complex(double r, double i)
{
    real = r;
    imaginary = i;
}
Complex Complex::operator+(const Complex &C)
{
    Complex sum;
    sum.real = C.getReal() + getReal();
    sum.imaginary = C.getImagine() + getImagine();
    return sum;
}
Complex Complex::operator-(const Complex &C)
{
    Complex diff;
    diff.real = getReal() - C.getReal();
    diff.imaginary = getImagine() - C.getImagine();
    return diff;
}
// (a+b*i) * (c+d*i) == (a*c - b*d) + (a*d + b*c)*i
Complex Complex::operator*(const Complex &C)
{
    Complex mul;
    mul.real = getReal() * C.getReal() - getImagine() * C.getImagine();
    mul.imaginary = getReal() * C.getImagine() + getImagine() * C.getReal();
    return mul;
}
bool Complex::operator==(const Complex &C)
{
    return (getReal() == C.getReal() && getImagine() == C.getImagine());
}
ostream &operator<<(ostream &outputStream, const Complex &C)
{
    outputStream << "(" << C.getReal() << " + " << C.getImagine() << "i"
                 << ")";
    return outputStream;
}
istream &operator>>(istream &inputStream, Complex &C)
{
    double x;
    inputStream >> x;
    C.setReal(x);
    inputStream >> x;
    C.setImagine(x);
    return inputStream;
}
int main()
{
    cout << "*******************TEST********************" << endl;
    Complex c(1, 2);
    Complex c1(1, 2);
    Complex result;
    result = c1 + c;
    cout << "1." << c1 << endl;
    cout << "2." << c << endl;
    cout << c1 << " + " << c << " = " << result << endl;
    result = c1 - c;
    cout << c1 << " - " << c << " = " << result << endl;
    result = c1 * c;
    cout << c1 << " * " << c << " = " << result << endl;
    if (c1 == c)
    {
        cout << "The entered values are equal to each other." << endl;
    }
    else
    {
        cout << "The entered values are not equal to each other." << endl;
    }
    cout << "*******************************************" << endl;
    char choise = 'y';
    Complex c2, c3, c4;
    while (choise == 'y')
    {
        cout << "Enter first complex number: ";
        cin >> c2;
        cout << "Enter second complex number: ";
        cin >> c3;
        cout << c2 << " + " << c3 << " = " << c4 << endl;
        c4 = c2 - c3;
        cout << c2 << " - " << c3 << " = " << c4 << endl;
        c4 = c2 * c3;
        cout << c2 << " * " << c3 << " = " << c4 << endl;
        cout << "Did you want to contunie? y or n: ";
        cin>>choise;
    }
}