/*Define a class named MyInteger that stores an integer and has function to get and set the integer’s value.
Then, overload the [] operator so that the index returns the digit in position i, where i = 0 is the least-significant digit.
If no such digit exists then −1 should be returned.
For example, if x is of type MyInteger and is set to 418, then x[0] should return 8, x[1] should return 1, x[2] should return 4, and x[3] should return −1.*/
#include <iostream>
#include <vector>

using namespace std;
class MyInteger
{
public:
    MyInteger();
    void setInteger(int num);
    int &operator[](int index);
    int getSize() const { return size; }
    int getInteger() const { return integer; }

private:
    int size;
    std::vector<int> intArr;
    int integer;
};

MyInteger::MyInteger()
{
    integer = 0;
    size = 0;
}
void MyInteger::setInteger(int num)
{
    integer = num;
    while (num > 0)
    {
        int digit = num % 10;
        intArr.push_back(digit);
        num = num / 10;
        size++;
    }
}
int &MyInteger::operator[](int index)
{
    if (index >= getSize())
    {
        cout << "Index out of range\n";
        exit(1);
    }
    else
    {
        return intArr[index];
    }
}
int main()
{
    cout << "*****************TEST**********************" << endl;
    MyInteger m;
    m.setInteger(9845);
    cout << "My test integer is 9845. Second index value is : ";
    cout << m[m.getSize() - 2] << endl;
    cout << "*******************************************" << endl;
    MyInteger i;
    int x, y;
    cout << "Enter value: ";
    cin >> x;
    i.setInteger(x);
    cout << "Which index do you want: ";
    cin >> y;
    cout << "Your integer is " << x << ". " << y << ". index value: " << i[i.getSize() - y] << endl;
    return 0;
}
