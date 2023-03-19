#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isValidDigit(int a)
{
    if (a >= 0 && a <= 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check(string a)
{
    if (a.empty()) // Check if string is empty
    {
        return false;
    }
    for (char c : a)
    {
        if (!isdigit(c)) // Check if character is not a digit
        {
            return false;
        }

        int digit = c - '0';
        if (!isValidDigit(digit)) // Check if digit is in the range of 0 to 9
        {
            return false;
        }
    }
    for(int i=0;i<a.length();i++)
    {
        for(int j=i+1;j<a.length();j++) // Compare each digit with all digits after it
        {
            if(a[i]==a[j]) // If any two digits are the same, return false
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    char choise;
    cout << "Which choice r or u ?" << endl;
    cin >> choise;
    
    srand(time(0));
    switch(choise)
    {
        case 'r':
        {
            cout<<"How many digits?"<<endl;
            int digit;
            cin>> digit;
            if(!isValidDigit(digit))
            {
                cout << "E0" << endl;
                break;
            }
            int num=1;//Generates a random number with the number of digits entered
            for(int i=1;i<=digit;i++)
            {
                num =num*10;
            }
            num = num-1;
            string secret;
            secret = to_string(rand()%num);
            while(!check(secret))
            {
                secret = to_string(rand()%num);
            }
            cout << secret ;
            break;
        }
        case 'u':
        {
            cout << "Enter secret number:"<< endl;
            string secNum;
            getline(cin, secNum);
            if(check(secNum))
            {
                cout << secNum ; 
            }
            break;
        }
        default:
            break;
    }
}
