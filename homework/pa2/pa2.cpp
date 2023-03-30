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
    int getWidth() const { return width; }
    int getHeigth() const { return heigth; }
    int getPix() const { return pix; }

private:
    string filename, format;
    int width, heigth, pix;
    vector<vector<int> > pixel;
};
Image::Image()
{
    filename = "";
}
void Image::Menu()
{
    int button = 1;
    int buttonTwo;
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
            buttonTwo = 1;
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
            buttonTwo = 1;
            while (buttonTwo != 0)
            {
                cout << "SAVE IMAGE DATA MENU" << endl;
                cout << "0 - UP" << endl;
                cout << "1 - Enter A File Name" << endl;
                cin >> buttonTwo;
                if (buttonTwo == 1)
                {
                    saveImage();
                }
            }
        }
        else if (button == 3)
        {
            buttonTwo = 1;
            while (buttonTwo != 0)
            {
                cout << "CONVERT TO GRAYSCALE MENU" << endl;
                cout << "0 - UP" << endl;
                cout << "1 - Enter Coefficients For RED GREEN And BLUE Channels." << endl;
                cin >> buttonTwo;
                if (buttonTwo == 1)
                {
                    scriptImage();
                }
            }
        }
        else
        {
            exit(0);
        }
    }
}
void Image::openImage()
{
    const int pixelDigit = 3;
    string inputName;
    cin >> inputName;
    ifstream file(inputName);
    if (file.is_open())
    {
        getline(file, format);
        file >> width >> heigth >> pix;
        for (int i = 0; i < heigth; i++)
        {
            pixel.push_back(vector<int>());
            for (int j = 0; j < width * pixelDigit; j++)
            {
                pixel[i].push_back(0);
            }
        }
        for (int i = 0; i < heigth; i++)
        {
            for (int j = 0; j < width * pixelDigit; j++)
            {
                int x;
                if (file.good())
                {
                    file >> x;
                    pixel[i][j] = x;
                }
            }
        }
        file.close();
    }
    else cout << "File is not read!" << endl;
}

void Image::saveImage()
{
    string inputfile;
    cin >> inputfile;
    ofstream file(inputfile);
    if (file.is_open())
    {
        file << format << endl;
        file << getWidth() << " " << getHeigth() << endl;
        file << getPix() << endl;
        for (int i = 0; i < getWidth(); i++)
        {
            for (int j = 0; j < getHeigth() * 3; j++)
            {
                file << pixel[i][j] << " ";
            }
            file << endl;
        }
        file.close();
    }
    else
        cout << "Not write txt!" << endl;
}
void Image::scriptImage()
{
}
int main()
{
    Image i;
    i.Menu();
}