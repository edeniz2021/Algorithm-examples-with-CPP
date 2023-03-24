/*My mother always took a little red counter to the grocery store. The counter was used to keep tally of the amount of money she would have spent so far on that visit to the store if she bought everything in the basket.
The counter had a four-digit display, increment buttons for each digit, and a reset button. An overflow indicator came up red if more money was entered than the $99.99 it would register. (This was a long time ago.)
Write and implement the member functions of a class Counter that simulates and slightly generalizes the behavior of this grocery store counter.
The constructor should create a Counter object that can count up to the constructor’s argument.
That is, Counter(9999) should provide a counter that can count up to 9999. A newly con- structed counter displays a reading of 0.
The member function void reset( ); sets the counter’s number to 0. The member function void incr1( ); increments the units digits by 1, void incr10( ); increments the tens digit by 1, and void incr100( ); and void incr1000( ); increment the next two digits, respectively.
Accounting for any carrying when you increment should require no further action than adding an appropriate number to the private data member. A member function bool overflow( );detectsoverflow.(Overflowistheresultofincrementingthecounter’s private data member beyond the maximum entered at counter construction.)
Use this class to provide a simulation of my mother’s little red clicker. Even though the display is an integer, in the simulation, the rightmost (lower order) two digits are always thought of as cents and tens of cents, the next digit is dollars, and the fourth digit is tens of dollars.
Provide keys for cents, dimes, dollars, and tens of dollars. Unfortunately, no choice of keys seems particularly mnemonic.
One choice is to use the keys asdfo: a for cents, followed by a digit 1 to 9; s for dimes, followed by a digit 1 to 9; d for dollars, followed by a digit 1 to 9; and f for tens of dollars, again followed by a digit 1 to 9. Each entry (one of asdf followed by 1 to 9) is followed by pressing the Return key. Any overflow is reported after each operation.
Overflow can be requested by pressing the o key.*/
#include <iostream>
using namespace std;
class Counter
{
public:
    Counter(int num);
    Counter();
    void reset();
    void incr1(int number);
    void incr10(int number);
    void incr100(int number);
    void incr1000(int number);
    bool overflow();
    void setMax(int num);
    int getMax() const;
    void printCounter();

private:
    int max;
    int counter;
};

Counter::Counter(int num)
{
    max = num;
    counter = 0;
}
Counter::Counter()
{
    max = 0;
    counter = 0;
}

void Counter::reset()
{
    counter = 0;
    printCounter();
}
void Counter::setMax(int num)
{
    max = num;
}
int Counter::getMax() const
{
    return max;
}
bool Counter::overflow()
{
    if (max > counter)
    {
        return false;
    }
    else
        return true;
}
void Counter::incr1(int number)
{
    if (number > 0 && number <= 9)
    {
        counter += number;
        if (overflow())
        {
            cout << "Overflow." << endl;
        }
        else
            printCounter();
    }
    else
        cout << "Illegal number." << endl;
}
void Counter::incr10(int number)
{
    if (number > 0 && number <= 9)
    {
        number = number * 10;
        counter += number;
        if (overflow())
        {
            cout << "Overflow." << endl;
        }
        else
            printCounter();
    }
    else
        cout << "Illegal number." << endl;
}
void Counter::incr100(int number)
{
    if (number > 0 && number <= 9)
    {
        number = number * 100;
        counter += number;
        if (overflow())
        {
            cout << "Overflow." << endl;
        }
        else
            printCounter();
    }
    else
        cout << "Illegal number." << endl;
}
void Counter::incr1000(int number)
{
    if (number > 0 && number <= 9)
    {
        number = number * 1000;
        counter += number;
        if (overflow())
        {
            cout << "Overflow." << endl;
        }
        else
            printCounter();
    }
    else
        cout << "Illegal number." << endl;
}
void Counter::printCounter()
{
    cout << "Your counter is " << counter << " . Max limit is " << max << endl;
    cout << endl;
}
int main()
{
    cout << "***********TEST************"<< endl;
    Counter c(2345);
    c.incr1(1);
    c.incr10(4);
    c.incr100(8);
    c.incr1000(2);
    cout << "***************************" << endl;
    Counter c2;
    int x;
    char k;
    do
    {
        cout << "Enter max value (1-9999): ";
        cin >> x;
    } while (x > 9999);
    c2.setMax(x);
    while (k != 'q')
    {
        cout << "To increase the ones digit a" << endl;
        cout << "To increase the tens digit b" << endl;
        cout << "To increase the hunders digit c" << endl;
        cout << "To increase the thousands digit d" << endl;
        cout << "To reset the counter r" << endl;
        cout << "To see the counter p" << endl;
        cout << "To change the max value m" << endl;
        cout << "To exit q" << endl;
        cin >> k;
        if (k == 'a')
        {
            cout << "Enter(1 - 9) to increment : ";
            cin >> x;
            if (x <= 0)
            {
                cout << "Enter(1 - 9) to increment : ";
                cin >> x;
            }
            else
                c2.incr1(x);
        }
        else if (k == 'b')
        {
            cout << "Enter(1 - 9) to increment : ";
            cin >> x;
            if (x <= 0)
            {
                cout << "Enter(1 - 9) to increment : ";
                cin >> x;
            }
            else
                c2.incr10(x);
        }
        else if (k == 'c')
        {
            cout << "Enter(1 - 9) to increment : ";
            cin >> x;
            if (x <= 0)
            {
                cout << "Enter(1 - 9) to increment : ";
                cin >> x;
            }
            else
                c2.incr100(x);
        }
        else if (k == 'd')
        {
            cout << "Enter(1 - 9) to increment : ";
            cin >> x;
            if (x <= 0)
            {
                cout << "Enter(1 - 9) to increment : ";
                cin >> x;
            }
            else
                c2.incr1000(x);
        }
        else if (k == 'r')
        {
            c2.reset();
        }
        else if (k == 'p')
        {
            c2.printCounter();
        }
        else if (k == 'm')
        {
            do
            {
                cout << "Enter max value (1-9999): ";
                cin >> x;
            } while (x > 9999);
            c2.setMax(x);
        }
        else if (k == 'q')
        {
            exit(1);
        }
    }
}