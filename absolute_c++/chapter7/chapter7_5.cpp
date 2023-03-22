#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n; // number of suitors
    cout << "Enter the number of suitors: ";
    cin >> n;
    vector<int> suitor(n);
    int count = 0;
    cout << "İnitial List: ";
    for(int i=0;i<n;i++)
    {
        suitor[i] = i+1;
        cout <<  suitor[i] ;
    }
    cout << endl;
    while(suitor.size()>1)
    {
         for(int i = 0; i<suitor.size(); i++){
            count += 1;
            if(count == 3){// eliminate the i-th suitor
                cout << "The " << suitor[i] << " suitor is eliminated." << endl;
                suitor.erase(suitor.begin() + i);// reset the counter and the index
                count = 0;
                i--;
            }
        }
    }
    cout << "The winning suitor is " << suitor[0] << endl;
}