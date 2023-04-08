/*Reread the code in Display 10.9. Then, write a class TwoD that implements the two-dimensional dynamic array of doubles using ideas from this display in its constructors.
You should have a private member of type pointer to double to point to the dynamicarray,and two int(or unsigned int)values that are MaxRows and MaxCols.
You should supply a default constructor for which you are to choose a default maximum row and column sizes and a parameterized constructor that allows the programmer to set maximum row and column sizes.
Further, you should provide a void member function that allows setting a particu- lar row and column entry and a member function that returns a particular row and column entry as a value of type double.
Remark: It is difficult or impossible (depending on the details) to overload [ ] so it works as you would like for two-dimensional arrays. So simply use accessor and mutator functions using ordinary function notation.
Overload the + operator as a friend function to add two two-dimensional arrays. This function should return the TwoD object whose ith row, jth column element is the sum of the ith row,
jth column element of the left-hand operand TwoD object and the ith row, jth column element of the right-hand operand TwoD object.
Provide a copy constructor, an overloaded operator =, and a destructor.
Declare class member functions that do not change the data as const members*/
#include <iostream>
#include <string>

using namespace std;

class TwoD
{
public:
    // Constructors
    TwoD();
    TwoD(const TwoD &T);
    TwoD(int Row, int Column);
    // Destructor
    ~TwoD();
    // Member functions
    void set(int Rows, int Colums, double value);
    double getArray(int Rows, int Columns) const { return dynamicArray[Rows][Columns]; }
    TwoD &operator=(const TwoD &T);
    friend const TwoD operator+(const TwoD &T, const TwoD &D);

private:
    double **dynamicArray;
    int MaxRows, MaxColumns;
};

// Default constructor
TwoD::TwoD()
{
    MaxRows = 0;
    MaxColumns = 0;
    dynamicArray = nullptr;
}

// Copy constructor
TwoD::TwoD(const TwoD &T)
{
    MaxColumns = T.MaxColumns;
    MaxRows = T.MaxRows;
    dynamicArray = new double *[MaxRows];
    for (int i = 0; i < MaxRows; i++)
    {
        dynamicArray[i] = new double[MaxColumns];
        for (int j = 0; j < MaxColumns; j++)
        {
            dynamicArray[i][j] = T.dynamicArray[i][j];
        }
    }
}

// Parameterized constructor
TwoD::TwoD(int Row, int Column)
{
    MaxColumns = Column;
    MaxRows = Row;
    dynamicArray = new double *[Row];
    for (int i = 0; i < Row; i++)
    {
        dynamicArray[i] = new double[Column];
    }
}

// Function to set a value at a specific row and column
void TwoD::set(int Rows, int Colums, double value)
{
    dynamicArray[Rows][Colums] = value;
}

// Overloaded assignment operator
TwoD &TwoD::operator=(const TwoD &T)
{
    if (this == &T)
    {
        return *this;
    }

    // Deallocate memory for the dynamic array of this object
    for (int i = 0; i < MaxRows; i++)
    {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;

    MaxRows = T.MaxRows;
    MaxColumns = T.MaxColumns;

    // Allocate memory for the dynamic array
    dynamicArray = new double *[MaxRows];
    for (int i = 0; i < MaxRows; i++)
    {
        dynamicArray[i] = new double[MaxColumns];
        // Copy the values from the other object to this object
        for (int j = 0; j < MaxColumns; j++)
        {
            dynamicArray[i][j] = T.dynamicArray[i][j];
        }
    }

    return *this;
}
// Overloaded + operator as a friend function
const TwoD operator+(const TwoD &T, const TwoD &D)
{
    int minRow = min(T.MaxRows, D.MaxRows);
    int minColumns = min(T.MaxColumns, D.MaxColumns);

    TwoD result(minRow, minColumns);

    for (int i = 0; i < minRow; i++)
    {
        for (int j = 0; j < minColumns; j++)
        {
            result.dynamicArray[i][j] = T.dynamicArray[i][j] + D.dynamicArray[i][j];
        }
    }

    return result;
}
TwoD::~TwoD()
{
    for (int i = 0; i < MaxRows; i++)
    {
        delete[] dynamicArray[i];
    }
    delete dynamicArray;
}
int main()
{
    TwoD D(2,2);
    cout << "*************TEST************"<<endl;
    D.set(0,0,2.5);
    D.set(1,0,3.2);
    D.set(0,1,1.5);
    D.set(1,1,5.4);
    cout << "Dynamic Array 1: " << endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout << D.getArray(i,j)<<endl;
        }
    }
    TwoD T(2,2);
    T.set(1,0,4.5);
    T.set(1,1,3.5);
    T.set(0,1,1.5);
    T.set(0,0,2.0);
    cout << "Dynamic Array 2: " << endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout << T.getArray(i,j)<<endl;
        }
    }
    TwoD Sum;
    Sum = T + D;
    cout << "Dynamic Array1 and Dynamic Array2 Sum: " << endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout << Sum.getArray(i,j)<<endl;
        }
    }
    cout << "*****************************"<<endl;
}