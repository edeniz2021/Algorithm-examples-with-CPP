/*Define a class named MyInteger that stores an integer and has function to get and set the integer’s value.
Then, overload the [] operator so that the index returns the digit in position i, where i = 0 is the least-significant digit.
If no such digit exists then −1 should be returned.
For example, if x is of type MyInteger and is set to 418, then x[0] should return 8, x[1] should return 1, x[2] should return 4, and x[3] should return −1.*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;
class MyInteger
{
public:
    MyInteger();
    void setSize();
    void setInteger(int num);
    void setArr();
    int &operator[](int index);
    int getSize() const { return size; }
    int getInteger() const { return integer; }

private:
    int size;
    vector<int> intArr;
    int integer;
};
MyInteger::MyInteger()
{
    integer = 0;
    size = 0;
}
void MyInteger::setSize()
{
    int number = getInteger();
    while (number > 0)
    {
        number = number / 10;
        size++;
    }
}
void MyInteger::setArr()
{
    int number = getInteger();
    while (number > 0)
    {
        number = number % 10;
        intArr.push_back(number);
        number = number / 10;
    }
}
void MyInteger::setInteger(int num)
{
    integer = num;
}
int &MyInteger::operator[](int index)
{
    if (index > getSize())
    {
        cout << "Maximum size exceeded.";
        exit(1);
    }
    else
    {
        return intArr[index];
    }
}