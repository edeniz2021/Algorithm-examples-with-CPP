/*Flesh out Programming Problem 15.1. Give new definitions for the various constructors and member functions Figure::center, Figure::draw, Figure::erase, Triangle::draw, Triangle::erase, Rectangle::draw, and
Rectangle::erase so that the draw functions actually draw figures on the screen by placing the character '*' at suitable locations on the screen.
For the erase functions, you can simply clear the screen (by outputting blank lines or by doing something more sophisticated).
There are a lot of details in this and you will have to decide on some of them on your own.*/
#include <iostream>
#include <math.h>

using namespace std;

class Figure
{
public:
    virtual void erase(){};
    virtual void draw(){};
    virtual void center(){};
};
class Rectangle : Figure
{
public:
    void erase()
    {
        cout << "In erase function of Rectangle class." << endl;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }
    void draw()
    {
        cout << "In draw function of Rectangle class." << endl;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    void center()
    {
        cout << "In center function of Rectangle class." << endl;
    }
};
class Triangle : public Figure
{
public:
    void erase()
    {
        cout << "In erase function of Triangle class." << endl;
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 6 - i; j++)
            {
                cout << " ";
            }
            for (int k = 1; k <= 2 * i - 1; k++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }
    void draw()
    {
        cout << "In draw function of Triangle class." << endl;
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 6 - i; j++)
            {
                cout << " ";
            }
            for (int k = 1; k <= 2 * i - 1; k++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    void center()
    {
        cout << "In center function of Triangle class." << endl;
    }
};
class Square : Figure
{
public:
    void erase()
    {
        cout << "In erase function of Square class." << endl;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }
    void draw()
    {
        cout << "In draw function of Square class." << endl;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << " *";
            }
            cout << endl;
        }
    }
    void center()
    {
        cout << "In center function of Square class." << endl;
    }
};
int main()
{
    Triangle tri;
    tri.draw();
    cout << "\nDerived class Triangle object calling center( ).\n";
    tri.center(); // Calls draw and center
    tri.erase();
    Rectangle rect;
    rect.draw();
    cout << "\nDerived class Rectangle object calling center( ).\n";
    rect.center(); // Calls draw and center
    rect.erase();
    Square squ;
    squ.draw();
    cout << "\nDerived class Square object calling center( ).\n";
    squ.center(); // Calls draw and center
    squ.erase();
    return 0;
}