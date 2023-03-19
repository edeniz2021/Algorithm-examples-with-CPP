#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
bool isValid(int a)
{

    if(a>0 && a<10)
    {
        return true;
    }else return false;
}

int main()
{
    char choise;
    int secret;
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
            if(!isValid(digit))
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
            secret = rand()%num;
            cout << secret ;
            break;
        }
        case 'u':
        {
            cout << "enter secret number:"<< endl;
            cin >> secret;
            break;
        }
        default:
            break;
    }
}