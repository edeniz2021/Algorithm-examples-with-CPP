#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

bool checkRandom(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = i + 1; j < a.length(); j++) // Compare each digit with all digits after it
        {
            if (a[i] == a[j]) // If any two digits are the same, return false
            {
                return false;
            }
        }
    }
    return true;
}

bool check(string a)
{
    if (a.empty()) // Check if string is empty
    {
        cout << "E2" << endl;
        return false;
    }
    for (char c : a)
    {
        if (!isdigit(c)) // Check if character is not a digit
        {
            cout << "E2" << endl;
            return false;
        }
    }
    if (!checkRandom(a))
    {
        cout << "E2" << endl;
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    srand(time(0));
    if (argc == 3)
    {
        if (strcmp(argv[1], "-r") == 0)
        {
            int digit = atoi(argv[2]);
            if (digit <= 0 || !isdigit(argv[2][0])) // Check if input is less than or equal to 0
            {
                cout << "E2" << endl;
                return 0;
            }
            string secret;
            do
            {
                secret.clear();
                for (int i = 0; i < digit; i++)
                {
                    if (i == 0)
                    {
                        secret += to_string(rand() % 9 + 1); // The first digit can't be 0
                    }
                    else
                    {
                        secret += to_string(rand() % 10);
                    }
                }
            } while (!checkRandom(secret));

            cout << secret;
        }
        else if (strcmp(argv[1], "-u") == 0)
        {
            string secNum = argv[2];
            if (!check(secNum))
            {
                return 0;
            }
            cout << secNum;
        }
    }
    return 0;
}
