#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>

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
void game(string secretNum)
{
    string user;
    int den = 0;
    int count = 0;
    int bas = 0;
    cout << "User enter:" << endl;
    cin >> user;
    while (user != secretNum && den != 1)
    {
        if (secretNum.length() != user.length())
        {
            den = 1;
            cout << "E1" << endl;
        }
        else
        {
            bas = 0;
            count = 0;
            for (int i = 0; i < secretNum.length(); i++)
            {
                for (int j = 0; j < user.length(); j++)
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
            cout << "doğru harf sayisi :" << count << endl;
            cout << "doğru basamak sayisi :" << bas << endl;
            cout << "User enter:" << endl;
            cin >> user;
            den = 0;
        }
    }
    if (den == 1)
    {
        exit(0);
    }
}

int main(int argc, char *argv[])
{
    string secret;
    srand(time(0));
    if (argc == 3)
    {
        if (strcmp(argv[1], "-r") == 0)
        {
            int digit = atoi(argv[2]);
            if (digit <= 0 || !isdigit(argv[2][0])) // Check if input is less than or equal to 0
            {
                cout << "E0" << endl;
                return 0;
            }
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

            cout << secret << endl;
            game(secret);
        }
        else if (strcmp(argv[1], "-u") == 0)
        {
            secret = argv[2];
            if (!check(secret))
            {
                return 0;
            }
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
