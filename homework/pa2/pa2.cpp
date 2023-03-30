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
    string format;
    int width, heigth, pix;
    vector<vector<int> > pixel;
};
Image::Image()
{
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
    string fileName;
    cin >> fileName;
    int x;
    ifstream file(fileName);
    if (file.is_open())
    {
        getline(file, format);
        file >> width >> heigth >> pix;
        pixel.resize(heigth, vector<int>(width * pixelDigit));
        for (int i = 0; i < heigth; i++)
        {
            for (int j = 0; j < width * pixelDigit; j++)
            {
                if ((file >> x))
                {
                    pixel[i][j] = x;
                }
                else
                    cout << "****";
            }
        }

        file.close();
    }
    else
        cout << "File is not read!" << endl;
}

void Image::saveImage()
{
    const int pixelDigit = 3;
    string fileName;
    cin >> fileName;
    ofstream file(fileName);
    if (file.is_open())
    {
        file << format << endl;
        file << getWidth() << " " << getHeigth() << endl;
        file << getPix() << endl;
        for (int i = 0; i < heigth; i++)
        {
            for (int j = 0; j < width * 3; j++)
            {
                file << pixel[i][j];
                if (j + 1 != width * 3)
                {
                    file << " ";
                }
            }
            if (i + 1 != heigth)
            {
                file << endl;
            }
        }
        file.close();
    }
    else
        cout << "Not write txt!" << endl;
}

void Image::scriptImage()
{
    double c_r, c_g, c_b;
    bool check = true;
    while (check)
    {
        cin >> c_r >> c_g >> c_b;
        if (c_r > 0 && c_r <= 1 && c_g > 0 && c_g <= 1 && c_b > 0 && c_b <= 1)
        {
            check = false;
        }
    }

    for (int i = 0; i < getHeigth(); i++)
    {
        for (int j = 0; j < getWidth() * 3; j += 3)
        {
            int RED = pixel[i][j];
            int GREEN = pixel[i][j + 1];
            int BLUE = pixel[i][j + 2];

            int gray = c_r * RED + c_g * GREEN + c_b * BLUE;
            if (gray > 255)
            {
                gray = 255;
            }
            pixel[i][j] = gray;
            pixel[i][j + 1] = gray;
            pixel[i][j + 2] = gray;
        }
    }
}
int main()
{
    Image i;
    i.Menu();
}