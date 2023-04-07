/*Create a class named Student that has three member variables:
name
numClasses
classList
– A string that stores the name of the student
– An integer that tracks how many courses the student is cur- rently enrolled in
– A dynamic array of strings used to store the names of the classes that the student is enrolled in
Write appropriate constructor(s), mutator, and accessor functions for the class
along with the following:
• A function that inputs all values from the user, including the list of class names. This function will have to support input for an arbitrary number of classes.
• A function that outputs the name and list of all courses.
• A function that resets the number of classes to 0 and the classList to an
empty list.
• An overloaded assignment operator that correctly makes a new copy of the list of courses.
• A destructor that releases all memory that has been allocated.
Write a main function that tests all of your functions.*/

#include <iostream>
#include <string>

using namespace std;
class Student
{
public:
    Student();
    ~Student();
    void setName(string n) { name = n; }
    string getName() const { return name; }
    void setNum(int a) { numClasses = a; }
    int getNum() const { return numClasses; }
    void inputData();
    void outputData() const;

private:
    string name;
    int numClasses;
    string *classList;
};
Student::Student()
{
    name = "";
    numClasses = 0;
    classList = nullptr;
}
Student::~Student()
{
    delete[] classList;
}
void Student::inputData()
{

    classList = new string[numClasses];
    for (int i = 0; i < numClasses; i++)
    {
        cout << "Enter your course name: ";
        cin >> classList[i];
    }
}
void Student::outputData() const
{
    cout << endl;
    cout << name << " course: ";
    for (int i = 0; i < numClasses; i++)
    {
        cout << classList[i];
        if (i != numClasses - 1)
        {
            cout << ", ";
        }
    }
}
int main()
{
    Student S;
    string n;
    int c;
    char choice = 'y';
    while (choice == 'y')
    {
        cout << "Enter Student Name: ";
        cin >> n;
        S.setName(n);
        cout << "How many course name enter? ";
        cin >> c;
        S.setNum(c);
        S.inputData();
        S.outputData();
        cout << endl;
        cout << "Did you want enter new student? y/n:";
        cin>>choice;
    }
}