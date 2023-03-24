/*First, complete Programming Project 6.12. Modify the main function with a loop so that the user determines how many BoxOfProduce objects are created.
Each box should contain three bundles of fruits or vegetables selected randomly from this list: tomatillo, broccoli, tomato, kiwi, and kale.
Add a menu so the user can decide when to stop creating boxes. The menu should allow the user to make substitutions for the randomly selected items in a box.
You would like to throw in a free recipe flyer for salsa verde if the box contains tomatillos. However, there are only 5 recipe flyers.
Add a static member variable to the BoxOfProduce class that counts the number of recipe flyers remaining and initialize it to 5.
Also add a member variable that indicates whether or not the box contains a recipe flyer and modify the output function to also print “salsa verde recipe” if the box contains a recipe flyer.
Finally, add logic inside the class so that if the box contains at least one order of tomatillos then it automatically gets a recipe flyer until all of the recipe flyers are gone.
Note that a box should only get one recipe flyer even if there are multiple orders of tomatillos.
Test your class by creating boxes with tomatillos from your menu until all of the flyers are gone.*/
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
    void addRecipe();
    static void setRecipeFlyersRemaining(int num)
    {
        recipe_flyr = num;
    }

private:
    string box[3];
    static int recipe_flyr;
};
int BoxOfProduce::recipe_flyr = 5;
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
    cout << "**********************" << endl;
}
void BoxOfProduce::addRecipe()
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (box[i] == "Tomatillo" && recipe_flyr > 0 && count == 0)
        {
            box[i] = "Tomatillo (salsa verde recipe)";
            recipe_flyr--;
            count++;
        }
    }
    if (recipe_flyr == 0)
    {
        cout << "All recipe finish" << endl;
        exit(0);
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
    char chos = 'y';
    int a = 0;
    while (chos != 'n')
    {
        b.randomBox();
        b.printBox();
        a++;
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
            }
            b.addRecipe();
            cout << a << ".";
            b.printBox();
        }
        cout << "Did you new box create? y or n:";
        cin >> chos;
    }
}