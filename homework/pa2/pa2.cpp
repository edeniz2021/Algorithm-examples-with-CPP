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
    void openImage();//to read the file
    void saveImage();//to write the file
    void scriptImage();//to make grayscale
    int getWidth() const { return width; }
    int getHeigth() const { return heigth; }
    int getPix() const { return pix; }

private:
    int width, heigth, pix;
    vector<vector<int> > pixel;//keeps pixel data
    string format;
};
Image::Image()
{
    width = 0;
    heigth = 0;
    pix = 0;
    format = "";
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
        if (button == 1)//If it chooses 1, it will go to the menu again
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
    ifstream file(fileName);// read image data from a file and store it in the pixel matrix
    if (file.is_open())
    {
        file >> format;
        file >> width >> heigth >> pix;
        pixel.resize(heigth, vector<int>(width * pixelDigit));// the pixel matrix is resized to match the width and height of the image
        for (int i = 0; i < heigth; i++)
        {
            for (int j = 0; j < width * pixelDigit; j++)
            {
                if ((file >> x))
                {
                    pixel[i][j] = x;// the pixel values are stored in row-major order in the matrix
                }
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
        // write image format (e.g. P3)
        file << format << endl;
        // write image dimensions
        file << getWidth() << " " << getHeigth() << endl;
        // write max pixel value
        file << pix << endl;
        for (int i = 0; i < getHeigth(); i++)// write pixel values in row-major order, separated by spaces
        {
            for (int j = 0; j < getWidth() * pixelDigit; j++)// write pixel values in row-major order, separated by spaces,
            {
                file << pixel[i][j];
                if (j + 1 != getWidth() * pixelDigit)
                {
                    file << " ";        
                }
            }
            if (i + 1 != getHeigth())        // and start a new line after writing each row of pixels except for the last row
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

            int gray = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE);  // convert each pixel to grayscale using the specified color weights
            if (gray > pix)
            {
                gray = 255;  // if the resulting grayscale value is greater than a threshold value "pix",set the pixel color to white (255, 255, 255)
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