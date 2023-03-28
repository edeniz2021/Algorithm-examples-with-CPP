#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Image
{
public:
    Image();
    void Menu();
    void openImage();
    void saveImage();
    void scriptImage();

private:
    string filename;
    int width, heigth;
};
Image::Image()
{
    filename = "";
}
void Image::Menu()
{
    int button = 1;
    int buttonTwo = 1;
    int choise;
    while (button != 0)
    {
        cout << "MAIN MENU" << endl;
        cout << "0 - Exit" << endl;
        cout << "1 - Open An Image(D)" << endl;
        cout << "2 - Save Image Data(D)" << endl;
        cout << "3 - Scripts(D)" << endl;
        cin >> button;
        if (button == 1)
        {
            while (buttonTwo != 0)
            {
                cout << "OPEN AN IMAGE MENU" << endl;
                cout << "0 - UP" << endl;
                cout << "1 - Enter The Name Of The Image File" << endl;
                cin >> buttonTwo;
                if (buttonTwo == 1)
                {
                    openImage();
                }
            }
        }
        else if (button == 2)
        {
            while (buttonTwo != 0)
            {
                cout << "SAVE IMAGE DATA MENU" << endl;
                cout << "0 - UP" << endl;
                cout << "1 - Enter A File Name" << endl;
                if (buttonTwo == 1)
                {
                    saveImage();
                }
            }
        }
        else if (button == 3)
        {
            while (buttonTwo != 0)
            {
                cout << "CONVERT TO GRAYSCALE MENU" << endl;
                cout << "0 - UP" << endl;
                cout << "1 - Enter Coefficients For RED GREEN And BLUE Channels." << endl;
                if (buttonTwo == 1)
                {
                    scriptImage();
                }
            }
        }
        else
            exit(0);
    }
}
void Image::openImage()
{
    string inputName;
    cin>> inputName;
    ifstream file(inputName);
    if(file.is_open())
    {

    }

}
void Image::saveImage()
{
}
void Image::scriptImage()
{
}
int main()
{
    Image i;
    i.Menu();
}