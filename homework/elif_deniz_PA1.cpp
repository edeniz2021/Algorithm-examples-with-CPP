#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

bool checkRandom(char a[]);
bool check(char a[]);
void game(char secretNum[],int len);
bool my_isdigit(char c);
bool negatifCheck(char a[]);

bool negatifCheck(char a[])
{
    int number;
    number = stoi(a);
    if (number < 0) // Check if input is less than or equal to 0
    {
        cout << "E0" << endl;
        return false;
    }
    else
        return true;
}

bool my_isdigit(char c) // Returns true if the given character is a digit (0-9), false otherwise
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

bool checkRandom(char a[])
{
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++) // Compare each digit with all digits after it
        {
            if (a[i] == a[j]) // If any two digits are the same, return false
            {
                return false;
            }
        }
    }
    return true;
}

bool check(char a[])
{
    int len = strlen(a);
    if (len == 0) // Check if string is empty
    {
        cout << "E0" << endl;
        return false;
    }
    if (!negatifCheck(a))// Check if string is not negative digit
    {
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        if (!my_isdigit(a[i])) // Check if character is not a digit
        {
            cout << "E2" << endl;
            return false;
        }
    }
    if (!checkRandom(a))
    {
        cout << "E0" << endl;
        return false;
    }
    return true;
}
void game(char secretNum[],int len)
{
    char user[10]; // declare a character array to store user input
    int den = 0;
    int count = 0; // correct digit keeps correct digits
    int bas = 0;
    int gameCount = 0; // keeps track of how many times the game has been played
    cin >> user;
    gameCount++;
    int isEqual = 0;
    while (isEqual != len && den != 1 && gameCount != 100 && check(user)) // loop until user finds the secret number or game ends
    {
        int userlen = strlen(user);
        gameCount++; // increment game attempt count
        isEqual = 0;
        if (len != userlen) // check if user input length matches secret number length
        {
            den = 1;
            cout << "E1" << endl;
        }
        else
        {
            bas = 0;
            count = 0;
            for (int i = 0; i < len; i++) // compare user input with secret number
            {
                for (int j = 0; j < userlen; j++)
                {
                    if (user[i] == secretNum[j])
                    {
                        count++; // increment count if digit is correct
                    }
                }
                if (user[i] == secretNum[i]) // increment bas if digit is in the correct position
                {
                    bas++;
                }
            }
            cout << bas << " " << count - bas << endl; // print feedback to the user
            cin >> user;
            den = 0;
            for (int i = 0; i < len; i++) // two array compare for loop
            {
                if (user[i] == secretNum[i])
                {
                    isEqual++;
                }
            }
        }
    } // print outcome of the game
    if (isEqual == len)
    {
        cout << "FOUND " << gameCount << endl;
    }
    if (gameCount == 100)
    {
        cout << "FAILED " << endl;
    }
    if (den == 1)
    {
        exit(0);
    }
}

int main(int argc, char *argv[])
{
    srand(time(0));
    if (argc == 3)
    {
        if (strcmp(argv[1], "-r") == 0)
        {
            int digit = atoi(argv[2]);
            if (digit <= 0 || !my_isdigit(argv[2][0])) // Check if input is less than or equal to 0
            {
                cout << "E0" << endl;
                return 0;
            }
            else if (digit > 9)//Controls entering a value greater than 9
            {
                cout << "E0" << endl;
                return 0;
            }
            char secret[digit];
            do
            {
                for (int i = 0; i < digit; i++)
                {
                    if (i == 0)
                    {
                        secret[i] = rand() % 9 + 1 + '0'; // The first digit can't be 0
                    }
                    else
                    {
                        secret[i] = rand() % 10 + '0';
                    }
                }
            } while (!checkRandom(secret));
            game(secret,digit);
        }
        else if (strcmp(argv[1], "-u") == 0)
        {
            char secret[10];
            int len = strlen(argv[2]);
            strcpy(secret, argv[2]);
            for (int i = 0; i < strlen(argv[2]); i++)
            {
                if (!my_isdigit(argv[2][i]))
                {
                    cout << "E0" << endl;
                    return 0;
                }
                else if (!checkRandom(secret))
                {
                    cout << "E0" << endl;
                    return 0;
                }
            }
            game(secret,len);
        }
        else
        {
            cout << "E0" << endl;
            return 0;
        }
    }
    else
    {
        cout << "E0" << endl;
        return 0;
    }
    return 0;
}
