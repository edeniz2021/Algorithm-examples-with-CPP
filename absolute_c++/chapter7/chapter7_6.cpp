/*ThisProgrammingProjectrequiresyoutofirstcompleteProgrammingProject6.7 from Chapter 6, which is an implementation of a Pizza class.
Add an Order class that contains a private vector of type Pizza. This class represents a customer’s entire order, where the order may consist of multiple pizzas.
Include appropriate functions so that a user of the Order class can add pizzas to the order (type is deep dish, hand tossed, or pan; size is small, medium, or large; number of pepperoni or cheese toppings).
You can use constants to represent the type and size. Also write a function that outputs everything in the order along with the total price.
Write a suitable test program that adds multiple pizzas to an order(s).*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pizza
{
public:
    Pizza();
    Pizza(char t, char sz, char s);
    void outputDescription();
    double computePrice();
    void setPizzaType(char t);
    void setPizzaSize(char sz);
    void setPizzaSos(char s);
    string getPizzaType() const;
    string getPizzaSize() const;
    string getPizzaSos() const;

private:
    string type;
    string size;
    string sos;
    double price;
};
Pizza::Pizza()
{
    type = "";
    size = "";
    sos = "";
    price = 0;
}
Pizza::Pizza(char t, char sz, char s)
{
    type = t;
    size = sz;
    sos = s;
    setPizzaSize(sz);
    setPizzaSos(s);
    setPizzaType(t);
}
void Pizza::outputDescription()
{
    cout << "Pizza Type: " << type << endl;
    cout << "Pizza Size: " << size << endl;
    cout << "Pizza Sos: " << sos << endl;
    cout << "Total Price: " << price << "$" << endl;
}
void Pizza::setPizzaSize(char sz)
{
    if (sz == 'l')
    {
        size = " Large ";
        price += 17.0;
    }
    else if (sz == 'm')
    {
        size = " Middle ";
        price += 14.0;
    }
    else if (sz == 's')
    {
        size = " Small ";
        price += 10.0;
    }
}
void Pizza::setPizzaType(char t)
{
    if (t == 'd')
    {
        type = " Deep Dish ";
    }
    else if (t == 'h')
    {
        type = "Hand Tossed";
    }
    else if (t == 'p')
    {
        type = "Pan";
    }
}
void Pizza::setPizzaSos(char s)
{
    if (s == 'p')
    {
        sos = " Pepperoni ";
        price += 2;
    }
    else if (s == 'c')
    {
        sos += "Cheese ";
        price += 2;
    }
}
string Pizza::getPizzaType() const
{
    return type;
}
string Pizza::getPizzaSize() const
{
    return size;
}
string Pizza::getPizzaSos() const
{
    return sos;
}
double Pizza::computePrice()
{
    return price;
}
class Order
{
private:
    vector<Pizza> pizzas;

public:
    void addPizza(Pizza pizza)
    {
        pizzas.push_back(pizza);
        cout << "Added pizza to order: " << endl;
        pizza.outputDescription();
    }

    void outputOrder()
    {
        double totalPrice = 0;
        cout << "Order Details: " << endl;
        for (int i = 0; i < pizzas.size(); i++)
        {
            cout << "Pizza " << i + 1 << ":" << endl;
            pizzas[i].outputDescription();
            totalPrice += pizzas[i].computePrice();
        }
        cout << "Total Price: " << totalPrice << "$" << endl;
    }
};

int main()
{
    char t, sz, s;
    Order order1;
    char choise ='y';
    while (choise != 'n')
    {
        cout << "Which size Small(s)/Medium(m)/Large(l)";
        cin >> sz;
        cout << "Which type Deep Dish(d)/Hand Tossed(h)/Pan(p): ";
        cin >> t;
        cout << "Which sos Pepperoni(p)/Cheese(c): ";
        cin >> s;
        Pizza p(t, sz, s);
        order1.addPizza(p);
        cout << "Do you want to new order? y / n :" ;
        cin>> choise;
    }
}