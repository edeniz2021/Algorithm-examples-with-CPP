/*One problem with dynamic arrays is that once the array is created using the new operator the size cannot be changed. For example, you might want to add or delete entries from the array similar to the behavior of a vector.
This project asks you to create a class called DynamicStringArray that includes member functions that allow it to emulate the behavior of a vector of strings.
The class should have the following:
• A private member variable called dynamicArray that references a dynamic ar- ray of type string.
• A private member variable called size that holds the number of entries in the array.
• A default constructor that sets the dynamic array to nullptr and sets size to 0.
• A function that returns size.
• A function named addEntry that takes a string as input.
The function should create a new dynamic array one element larger than dynamicArray, copy all elements from dynamicArray into the new array, add the new string onto the end of the new array, increment size, delete the old dynamicArray, and then set dynamicArray to the new array.
• A function named deleteEntry that takes a string as input. The function should search dynamicArray for the string. If not found, it returns false.
If found, it creates a new dynamic array one element smaller than dynamicArray. It should copy all elements except the input string into the new array, delete dynamicArray, decrement size, and return true.
A function named getEntry that takes an integer as input and returns the string at that index in dynamicArray. It should return nullptr if the index is out of dynamicArray’s bounds.
A copy constructor that makes a copy of the input object’s dynamic array.
Overload the assignment operator so that the dynamic array is properly copied to the target object.
A destructor that frees up the memory allocated to the dynamic array. Embed your class in a suitable test program.*/
#include <iostream>
#include <string>

using namespace std;
class DynamicStringArray
{
public:
    DynamicStringArray();
    DynamicStringArray(const DynamicStringArray &D);
    DynamicStringArray &operator=(const DynamicStringArray &D);
    int getSize() const { return size; }
    void addEntry(string input);
    bool deleteEntry(string input);
    string getEntry(int index) const;
    ~DynamicStringArray();

private:
    string *dynamicArray;
    int size;
};
DynamicStringArray::DynamicStringArray()
{
    size = 0;
    dynamicArray = nullptr;
}
DynamicStringArray::DynamicStringArray(const DynamicStringArray &D)
{
    size = D.size;
    dynamicArray = new string[size];
    for (int i = 0; i < size; i++)
    {
        dynamicArray[i] = D.dynamicArray[i];
    }
}
DynamicStringArray &DynamicStringArray::operator=(const DynamicStringArray &D)
{
    size = D.size;
    dynamicArray = new string[size];
    for (int i = 0; i < size; i++)
    {
        dynamicArray[i] = D.dynamicArray[i];
    }
    return *this;
}
string DynamicStringArray::getEntry(int index) const
{
    return dynamicArray[index];
}
DynamicStringArray::~DynamicStringArray()
{
    delete[] dynamicArray;
}
void DynamicStringArray::addEntry(string input)
{
    if (size == 0)
    {
        // If the array is empty, allocate memory for one element and store the input
        size++;
        dynamicArray = new string[size];
        dynamicArray[size - 1] = input;
    }
    // Create a temporary array to store the existing elements
    string *temp;
    temp = new string[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = dynamicArray[i];
    }
    // Deallocate memory for the existing dynamicArray
    delete[] dynamicArray;
    // Allocate memory for a new dynamicArray with increased size
    dynamicArray = new string[size + 1];
    for (int i = 0; i < size; i++)
    {
        // Copy elements from the temporary array to the new dynamicArray
        dynamicArray[i] = temp[i];
    }
    // Add the new input string to the end of the dynamicArray
    dynamicArray[size] = input;
    // Deallocate memory for the temporary array
    delete[] temp;
}

bool DynamicStringArray::deleteEntry(string input)
{
    int index = -1; // Initialize index to -1
    for (int i = 0; i < size; i++)
    {
        if (dynamicArray[i] == input)
        {
            index = i; // Store the index of the string to be deleted
            break;
        }
    }
    if (index == -1)
    {
        return false; // If input string not found, return false
    }
    else
    {
        string *temp = new string[size - 1]; // Allocate memory for temporary array
        for (int i = 0; i < index; i++)
        {
            temp[i] = dynamicArray[i]; // Copy elements before the string to be deleted
        }
        for (int i = index + 1; i < size; i++)
        {
            temp[i - 1] = dynamicArray[i]; // Copy elements after the string to be deleted
        }
        delete[] dynamicArray; // Deallocate memory for dynamicArray
        dynamicArray = temp;   // Update dynamicArray to point to the new temporary array
        size--;                // Decrease the size by 1

        return true; // Return true indicating successful deletion
    }
}
