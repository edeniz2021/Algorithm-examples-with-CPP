/*Your Community Supported Agriculture (CSA) farm delivers a box of fresh fruits and vegetables to your house once a week. For this Programming Project, define the class BoxOfProduce that contains exactly three bundles of fruits or vegetables. You can represent the fruits or vegetables as an array of type string. Add accessor and mutator functions to get or set the fruits or vegetables stored in the array. Also write an output function that displays the complete contents of the box on the console.
Next, write a main function that creates a BoxOfProduce with three items randomly selected from this list:
      Broccoli
      Tomato
      Kiwi
      Kale
      Tomatillo
This list should be stored in a text file that is read in by your program. For now you can assume that the list contains exactly five types of fruits or vegetables.
Do not worry if your program randomly selects duplicate produce for the three items. Next, the main function should display the contents of the box and allow the user to substitute any one of the five possible fruits or vegetables for any of the fruits or vegetables selected for the box. After the user is done with substitutions output the final contents of the box to be delivered.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;
class BoxOfProduce
{
public:
    BoxOfProduce();
    void randomBox();
    string getBox(int index) const;
    void setBox(int index, string name);
    void printBox() const;
    void readFile();

private:
    string box[3];
};
BoxOfProduce::BoxOfProduce()
{
}
string BoxOfProduce::getBox(int index) const
{
    return box[index];
}
void BoxOfProduce::setBox(int index, string name)
{
    box[index] = name;
}
void BoxOfProduce::printBox() const
{
    cout << "Box of Produce: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "  " << box[i] << endl;
    }
}
void BoxOfProduce::readFile()
{
    ifstream read("produce.txt");
    string satir = "";

    if (read.is_open())
    {
        while (getline(read, satir))
        {
            cout << satir << endl;
        }
        read.close();
    }
}
void BoxOfProduce::randomBox()
{
    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        int randomNumber = rand() % 5;
        if (randomNumber == 0)
        {
            box[i] = "Broccoli";
        }
        else if (randomNumber == 1)
        {
            box[i] = "Tomato";
        }
        else if (randomNumber == 2)
        {
            box[i] = "Kiwi";
        }
        else if (randomNumber == 3)
        {
            box[i] = "Kale";
        }
        else if (randomNumber == 4)
        {
            box[i] = "Tomatillo";
        }
    }
}
int main()
{
    BoxOfProduce b;
    b.readFile();
    b.randomBox();
    b.printBox();
    char choise = 'y';
    while (choise == 'y')
    {
        cout << "Did you changed box? y or n :";
        cin >> choise;
        int num;
        string pro;
        if (choise == 'y')
        {
            cout << "Which number? : ";
            cin >> num;
            cout << "Which produce? :";
            cin >> pro;
            cout << endl;
            b.setBox(num - 1, pro);
            b.printBox();
        }
    }
}