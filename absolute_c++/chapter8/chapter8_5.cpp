/*Write the definition for a class named Vector2D that stores information about a
two-dimensional vector. The class should have functions to get and set the x and
y components, where x and y are integers.
 Next, overload the * operator so that it returns the dot product of two vectors. The
dot product of two-dimensional vectors A and B is equal to
 (A x * B x ) + (A y * B y ).
 Finally, write a main subroutine that tests the * operation. */
// Vector2D
#include <iostream>
using namespace std;

class Vector2D
{
public:
    Vector2D();
    Vector2D(int a, int b);
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int a) { x = a; }
    void setY(int b) { y = b; }
    int operator*(const Vector2D &V);
    friend istream &operator>>(istream &inputStream, Vector2D &V);
    friend ostream &operator<<(ostream &outputStream, const Vector2D &V);

private:
    int x;
    int y;
};
Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}
Vector2D::Vector2D(int a, int b)
{
    x = a;
    y = b;
}
istream &operator>>(istream &inputStream, Vector2D &V)
{
    int x, y;
    inputStream >> x;
    V.setX(x);
    inputStream >> y;
    V.setY(y);
    return inputStream;
}
ostream &operator<<(ostream &outputStream, const Vector2D &V)
{
    outputStream << "(" << V.getX() << "x"
                 << " + " << V.getY() << "y"
                 << ")";
    return outputStream;
}
//(A x * B x ) + (A y * B y )
int Vector2D::operator*(const Vector2D &V)
{
    return (V.getX() * getX()) + (V.getY() * getY());
}
int main()
{
    cout << "********************TEST********************" << endl;
    Vector2D v1(2, -3);
    Vector2D v2(-4, 2);
    Vector2D a, b;
    cout << v1 << " * " << v2 << " = " << v1 * v2 << endl;
    cout << "Dot product of the two given vectors is: " << v1 * v2 << endl;
    cout << "*********************************************" << endl;
    char choise = 'y';
    while (choise == 'y')
    {
        cout << "Enter first vector x - y: ";
        cin >> a;
        cout << "Enter second vector x - y: ";
        cin >> b;
        cout << a << " * " << b << " = " << a * b << endl;
        cout << "Dot product of the two given vectors is: " << a * b << endl;
        cout <<"Did you want to again enter vector y our n: ";
        cin >> choise;
    }
}