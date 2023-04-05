/* Write a program that reads a person’s name in the following format: first name, then middle name or initial, and then last name. The program then outputs the name in the following format:
Last_Name, First_Name, Middle_Initial.
For example, the input
Mary Average User
should produce the output
User, Mary A.
The input
Mary A. User
should also produce the output
User, Mary A.
Your program should place a period after the middle initial even if the input did not contain a period. Your program should allow for users who give no middle name or middle initial. In that case, the output, of course, contains no middle name or initial. For example, the input
Mary User
should produce the output
User, Mary
If you are using C-strings, assume that each name is at most 20 characters long. Alternatively, use the class string. (Hint: You may want to use three string vari- ables rather than one large string variable for the input. You may find it easier to not use getline.)*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string first, middle, initial = "";

    // Read the first and middle names from input
    cin >> first >> middle;

    // Check if there is more input (i.e., a third name)
    if (!cin.eof())
    {
        // If there is a third name, read it as the initial
        cin >> initial;
        char c = middle[0];
        c = toupper(c);
        initial[0]= toupper(initial[0]);
        first[0] = toupper(first[0]);
        cout << initial << ", " << first << " " << c << "." << endl;
    }
    else
    {
        // If there is no third name, use the middle name as the initial
        initial = middle;
        initial[0]= toupper(initial[0]);
        first[0] = toupper(first[0]);
        cout << initial << ", " << first << endl;
    }
}
