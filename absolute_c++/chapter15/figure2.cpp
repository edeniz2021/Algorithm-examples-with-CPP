/*Flesh out Programming Problem 15.1. Give new definitions for the various constructors and member functions Figure::center, Figure::draw, Figure::erase, Triangle::draw, Triangle::erase, Rectangle::draw, and
Rectangle::erase so that the draw functions actually draw figures on the screen by placing the character '*' at suitable locations on the screen. 
For the erase functions, you can simply clear the screen (by outputting blank lines or by doing something more sophisticated). 
There are a lot of details in this and you will have to decide on some of them on your own.*/
#include <iostream>

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
    }
    void draw()
    {
        cout << "In draw function of Rectangle class." << endl;
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
    }
    void draw()
    {
        cout << "In draw function of Triangle class." << endl;
    }
    void center()
    {
        cout << "In center function of Triangle class." << endl;
    }
};
int main()
{
    Triangle tri;
    tri.draw();
    cout << "\nDerived class Triangle object calling center( ).\n";
    tri.center(); // Calls draw and center
    Rectangle rect;
    rect.draw();
    cout << "\nDerived class Rectangle object calling center( ).\n";
    rect.center(); // Calls draw and center
    return 0;
}