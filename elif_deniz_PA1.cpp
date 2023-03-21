#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool checkRandom(char a[]);
int length_measure(char a[]);
bool check(char a[]);
void game(char secretNum[]);
bool my_isdigit(char c);

bool my_isdigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool checkRandom(char a[])
{
    int len = 0;
    while (a[len] != '\0')
    {
        len++;
    }
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
int length_measure(char a[])
{
    int len = 0;
    while (a[len] != '\0')
    {
        len++;
    }
    return len;
}

bool check(char a[])
{
    int len = length_measure(a);
    if (len == 0) // Check if string is empty
    {
        cout << "E2" << endl;
        return false;
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
        cout << "E2" << endl;
        return false;
    }
    return true;
}
void game(char secretNum[])
{
    char user[100]; // declare a character array to store user input
    int den = 0;
    int count = 0;
    int bas = 0;
    int gameCount = 0;
    int len = length_measure(secretNum);
    cout << "User enter:" << endl;
    cin >> user;
    gameCount++;
    int isEqual = 0;
    while (isEqual != len && den != 1 && gameCount!=100 && check(user)) 
    {
        int userlen = length_measure(user);
        gameCount++;
        isEqual = 0; 
        if (len != userlen)
        {
            den = 1;
            cout << "E1" << endl;
        }
        else
        {
            bas = 0;
            count = 0;
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < userlen; j++)
                {
                    if (user[i] == secretNum[j])
                    {
                        count++;
                    }
                }
                if (user[i] == secretNum[i])
                {
                    bas++;
                }
            }
            cout << "doğru harf sayisi :" << count - bas << endl;
            cout << "doğru basamak sayisi :" << bas << endl;
            cout << "user enter:";
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
    }
    if (isEqual == len)
    {
        cout << "FOUND " << gameCount << endl;
    }
    if (gameCount == 100)
    {
        cout << "FAILED "  << endl;
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

            cout << secret << endl;
            game(secret);
        }
        else if (strcmp(argv[1], "-u") == 0)
        {
            char secret[10];
            if (!check(argv[2]))
            {
                return 0;
            }
            int len = 0;
            while (argv[2][len] != '\0')
            {
                len++;
            }
            for (int i = 0; i < len; i++)
            {
                secret[i] = argv[2][i];
            }
            secret[len] = '\0'; // Add null character to end array

            cout << secret << endl;
            game(secret);
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
