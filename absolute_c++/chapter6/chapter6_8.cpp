/*Define a class named Money that stores a monetary amount. The class should have two private integer variables, one to store the number of dollars and another to store the number of cents.
Add accessor and mutator functions to read and set both member variables. Add another function that returns the monetary amount as a double.
Write a program that tests all of your functions with at least two different Money objects.*/
#include <iostream>
using namespace std;

class Money
{
public:
    Money();
    Money(int c, int d);
    void setCent(int c);
    void setDollar(int d);
    int getCent() const;
    int getDollar() const;
    double totalMoney();
    void addMoney(double m);

private:
    int cent;
    int dollar;
};
Money::Money()
{
    cent = 0;
    dollar = 0;
}
Money::Money(int d, int c)
{
    cent = c;
    dollar = d;
}
void Money::setCent(int c)
{
    cent = c;
}
void Money::setDollar(int d)
{
    dollar = d;
}
int Money::getCent() const
{
    return cent;
}
int Money::getDollar() const
{
    return dollar;
}
double Money::totalMoney()
{
    double sonuc = dollar + (cent / 100.0);
    return sonuc;
}
void Money::addMoney(double m)
{
    double a;
    a = totalMoney();
    double result;
    result = a + m;
    cout << a << " + " << m << " = " << result << endl;
}
int main()
{
    cout << "*********TEST********" << endl;
    Money m(20, 133);
    m.addMoney(18.23);
    cout << "*********************" << endl;
    Money m1;
    int x, y;
    double k;
    char choise = 'y';
    cout << "Enter dollar value : ";
    cin >> x;
    m1.setDollar(x);
    cout << "Enter cent value : ";
    cin >> y;
    m1.setCent(y);
    cout << "Did you want to add double money?y or n: ";
    cin >> choise;
    if (choise == 'y')
    {
        cout << "Enter the double value you want to add: ";
        cin >> k;
        m1.addMoney(k);
    }

    return 0;
}