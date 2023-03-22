/*Define a class called Pizza that has member variables to track the type of pizza (either deep dish, hand tossed, or pan) along with the size (either small, medium, or large) and the number of pepperoni or cheese toppings. You can use constants to represent the type and size. Include mutator and accessor functions for your class. Createavoidfunction,outputDescription( ),thatoutputsatextualdescription of the pizza object. Also include a function, computePrice( ), that computes the cost of the pizza and returns it as a double according to the following rules:
Small pizza = $10 + $2 per topping Medium pizza = $14 + $2 per topping Large pizza = $17 + $2 per topping
Write a suitable test program that creates and outputs a description and price of various pizza objects.*/
#include <iostream>
using namespace std;

class Pizza
{
public:
    Pizza()
    {
        price = 0;
    }
    void outputDescription()
    {
        computePrice();
        cout << "Your pizza type : " << pizza << endl;
        cout << "Your total is " << price << " Tl"<< endl;
    }
    void computePrice()
    {
        price = price + (sos * 2);
    }
    void setPizza(char a)
    {
        if (a == 'b')
        {
            price = 17;
            pizza = "Buyuk Boy ";
        }
        else if (a == 'o')
        {
            price = 14;
            pizza = "Orta Boy ";
        }
        else if (a == 'k')
        {
            price = 10;
            pizza = "Kucuk boy ";
        }
    }
    string getPizza()const
    { 
        return pizza;
    }
    void addSos(string us)
    {
        
        pizza += us;
        sos++;
    }

private:
    int price;
    int sos = 0;
    string pizza;
};
int main()
{
    Pizza p;

    char boyut;
    char choise = 'y';
    string sec;
    cout << "Hangi pizzadan istiyosun buyuk orta kucuk? b-k-o :";
    cin >> boyut;
    p.setPizza(boyut);
    while (choise != 'h')
    {
        cout << " Sos eklemek ister misin? e - h : ";
        cin >> choise;
        if (choise == 'e')
        {
            cout << "1.Peynirli , 2.Biberli, 3.Korili" << endl;
            cin >> sec;
            p.addSos(sec);
        }
        p.outputDescription();
    }
    return 0;
}
