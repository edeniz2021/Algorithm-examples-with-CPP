#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
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
    }
    return true;
}


int main()
{
    char choise;
    cout << "Which choise r or u ?" << endl;
    cin >> choise;
    
    srand(time(0));
    switch(choise)
    {
        case 'r':
        {
            cout<<"How much digit?"<<endl;
            int digit;
            cin>> digit;
            if(!isdigit(digit))
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
            int secret;
            secret = rand()%num;
            cout << secret ;
            break;
        }
        case 'u':
        {
            cout << "enter secret number:"<< endl;
            string secNum;
            cin >> secNum;
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