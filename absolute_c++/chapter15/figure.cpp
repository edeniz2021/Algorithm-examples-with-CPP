/*Consider a graphics system that has classes for various figures—say, rectangles, squares, triangles, circles, and so on. For example, a rectangle might have data members height, width, and center point, while a square and circle might have only a center point and an edge length or radius, respectively.
In a well-designed system, these would be derived from a common class, Figure. You are to implement such a system.The class Figure is the base class. You should add only Rectangle and Triangle classes derived from Figure. Each class has stubs for member functions erase and draw.
Each of these member functions outputs a message telling what function has been called and what the class of the calling object is. Since these are just stubs, they do nothing more than output this message. The member function center calls erase and draw to erase and redraw the figure at the center.
Because you have only stubs for erase and draw, center will not do any “centering” but will call the member functions erase and draw. Also, add an output message in the member function center that announces that center is being called. The member func- tions should take no arguments. There are three parts to this project:
a. Do the class definitions using no virtual functions. Compile and test.
b. Make the base class member functions virtual. Compile and test.
c. Explain the difference in results.
For a real example, you would have to replace the definition of each of these mem- ber functions with code to do the actual drawing. You will be asked to do this in Programming Project 15.2.*/
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