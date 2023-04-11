#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
class ppmImage
{
public:
    ppmImage();
    ppmImage(const string fileName);
    ppmImage(int w, int h);
    int ReadImage(const string fileName); // to read the file
    int WriteImage(const string fileName)const;     // to write the file
    void scriptImage();                   // to make grayscale
    void setPixelInfo(int w, int h, int color, int value);
    void printDimensionPpm() const;
    void setWidth(int w) { width = w; }
    void setHeigth(int h) { heigth = h; }
    int getWidth() const { return width; }
    int getHeigth() const { return heigth; }
    int getPix() const { return pix; }
    int getPixelInfo(int w, int h, int color);
    ppmImage operator+(const ppmImage &I);
    ppmImage operator-(const ppmImage &I);
    friend ostream &operator<<(ostream &out, const ppmImage &I);
    int &operator()(int w, int h, int color);

private:
    int width, heigth, pix;
    vector<vector<int> > pixel; // keeps pixel data
    string format;
};
ppmImage::ppmImage()
{
    width = 0;
    heigth = 0;
    pix = 0;
    format = "";
}

ppmImage::ppmImage(int w, int h)
{
    heigth = h;
    width = w;
}
ppmImage::ppmImage(const string fileName)
{
    int x;
    ifstream file(fileName); // read image data from a file and store it in the pixel matrix
    if (file.is_open())
    {
        file >> format;
        file >> width >> heigth >> pix;
        pixel.resize(heigth, vector<int>(width * 3)); // the pixel matrix is resized to match the width and height of the image
        for (int i = 0; i < heigth; i++)
        {
            for (int j = 0; j < width * 3; j++)
            {
                if ((file >> x))
                {
                    pixel[i][j] = x; // the pixel values are stored in row-major order in the matrix
                }
            }
        }
        file.close();
    }
    else
        cout << "File is not read!" << endl;
}

int ppmImage::ReadImage(const string fileName)
{
    const int pixelDigit = 3; // r,g,b
    int x;
    ifstream file(fileName); // read image data from a file and store it in the pixel matrix
    if (file.is_open())
    {
        file >> format;
        file >> width >> heigth >> pix;
        pixel.resize(heigth, vector<int>(width * pixelDigit)); // the pixel matrix is resized to match the width and height of the image
        for (int i = 0; i < heigth; i++)
        {
            for (int j = 0; j < width * pixelDigit; j++)
            {
                if ((file >> x))
                {
                    pixel[i][j] = x; // the pixel values are stored in row-major order in the matrix
                }
            }
        }
        file.close();
        return 1;
    }
    else
    {
        cout << "File is not read!" << endl;
        return 0;
    }
}
int ppmImage::WriteImage(const string fileName)const
{
    const int pixelDigit = 3; // r,g,b
    ofstream file(fileName);
    if (file.is_open())
    {
        // write image format (e.g. P3)
        file << format << endl;
        // write image dimensions
        file << getWidth() << " " << getHeigth() << endl;
        // write max pixel value
        file << pix << endl;
        for (int i = 0; i < getHeigth(); i++) // write pixel values in row-major order, separated by spaces
        {
            for (int j = 0; j < getWidth() * pixelDigit; j++) // write pixel values in row-major order, separated by spaces,
            {
                file << pixel[i][j];
                if (j + 1 != getWidth() * pixelDigit)
                {
                    file << " ";
                }
            }
            if (i + 1 != getHeigth()) // and start a new line after writing each row of pixels except for the last row
            {
                file << endl;
            }
        }

        file.close();
        return 1;
    }
    else
    {
        cout << "Not write txt!" << endl;
        return 0;
    }
}

void ppmImage::scriptImage()
{
    double c_r, c_g, c_b;
    bool check = true;
    while (check)
    {
        cin >> c_r >> c_g >> c_b;
        if (c_r > 0 && c_r <= 1 && c_g > 0 && c_g <= 1 && c_b > 0 && c_b <= 1) // check the  number to 0-1 arrange
        {
            check = false;
        }
        else
            cout << "Please enter number range [0,1]: ";
    }
    for (int i = 0; i < getHeigth(); i++)
    {
        for (int j = 0; j < getWidth() * 3; j += 3)
        {
            int RED = pixel[i][j];
            int GREEN = pixel[i][j + 1];
            int BLUE = pixel[i][j + 2];

            int gray = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE); // convert each pixel to grayscale using the specified color weights
            if (gray > pix)
            {
                gray = 255; // if the resulting grayscale value is greater than a threshold value "pix",set the pixel color to white (255, 255, 255)
            }
            pixel[i][j] = gray;
            pixel[i][j + 1] = gray;
            pixel[i][j + 2] = gray;
        }
    }
}
void ppmImage::printDimensionPpm() const
{
    cout << width << " " << heigth << endl;
}
ppmImage ppmImage::operator+(const ppmImage &I)
{
    if (heigth != I.heigth || width != I.width)
    {
        return ppmImage(0, 0);
    }
    ppmImage sum(width, heigth);
    sum.pixel.resize(sum.heigth, vector<int>(sum.width * 3));
    for (int i = 0; i < getHeigth(); i++)
    {
        for (int j = 0; j < getWidth() * 3; j += 3)
        {
            sum.pixel[i][j] = pixel[i][j] + I.pixel[i][j];
            sum.pixel[i][j + 1] = pixel[i][j + 1] + I.pixel[i][j + 1];
            sum.pixel[i][j + 2] = pixel[i][j + 2] + I.pixel[i][j + 2];
        }
    }
    for (int i = 0; i < getHeigth(); i++)
    {
        for (int j = 0; j < getWidth() * 3; j += 3)
        {
            if (sum.pixel[i][j] > 255)
                sum.pixel[i][j] = 255;
            if (sum.pixel[i][j + 1] > 255)
                sum.pixel[i][j + 1] = 255;
            if (sum.pixel[i][j + 2] > 255)
                sum.pixel[i][j + 2] = 255;
        }
    }
    return sum;
}
ppmImage ppmImage::operator-(const ppmImage &I)
{
    if (heigth != I.heigth || width != I.width)
    {
        return ppmImage();
    }
    ppmImage diff(width, heigth);
    diff.pixel.resize(diff.heigth, vector<int>(diff.width * 3));
    for (int i = 0; i < getHeigth(); i++)
    {
        for (int j = 0; j < getWidth() * 3; j += 3)
        {
            diff.pixel[i][j] = pixel[i][j] - I.pixel[i][j];
            diff.pixel[i][j + 1] = pixel[i][j + 1] - I.pixel[i][j + 1];
            diff.pixel[i][j + 2] = pixel[i][j + 2] - I.pixel[i][j + 2];
        }
    }
    for (int i = 0; i < getHeigth(); i++)
    {
        for (int j = 0; j < getWidth() * 3; j += 3)
        {
            if (diff.pixel[i][j] < 0)
                diff.pixel[i][j] = 0;
            if (diff.pixel[i][j + 1] < 0)
                diff.pixel[i][j + 1] = 0;
            if (diff.pixel[i][j + 2] < 0)
                diff.pixel[i][j + 2] = 0;
            ;
        }
    }
    return diff;
}
ostream &operator<<(ostream &out, const ppmImage &I)
{
    out << I.format << endl;
    out << I.width << " " << I.heigth << endl;
    out << I.pix << endl;
    for (int i = 0; i < I.getHeigth(); i++) // write pixel values in row-major order, separated by spaces
    {
        for (int j = 0; j < I.getWidth() * 3; j++) // write pixel values in row-major order, separated by spaces,
        {
            out << I.pixel[i][j];
            if (j + 1 != I.getWidth() * 3)
            {
                out << " ";
            }
        }
        if (i + 1 != I.getHeigth()) // and start a new line after writing each row of pixels except for the last row
        {
            out << endl;
        }
    }

    return out;
}
int &ppmImage::operator()(int w, int h, int color)
{
    int &result = pixel[h][w * 3 + color];
    return result;
}
// Member function to return individual pixel information
int ppmImage::getPixelInfo(int w, int h, int color)
{
    return pixel[h][w * 3 + color]; // Since each pixel has three color values (r, g, b), we multiply the width by 3 and add the color index to get the corresponding color value.
}

// Member function to change individual pixel values
void ppmImage::setPixelInfo(int w, int h, int color, int value)
{
    pixel[h][w * 3 + color] = value; // Since each pixel has three color values (r, g, b), we multiply the width by 3 and add the color index to set the corresponding color value.
}

int read_ppm(const string source_ppm_file_name, ppmImage &destination_object);
int write_ppm(const string destination_ppm_file_name, const ppmImage &source_object);
//int swap_channels(ppmImage &image_object_to_be_modified, int swap_choice);
//ppmImage single_color(const ppmImage &source, int color_choice);
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3);
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3);
int test_print(const string filename_image1);
int main()
{
		int choiceNumber;									// Argument number to execute corresponding process
		string ppmFileName1= "deneme.ppm", ppmFileName2= "test.ppm",ppmFileName3= "output.ppm";	// File names

		ppmImage readPPMImage;		// Image of read file
		ppmImage processedPPMImage;	// Image that is the result of process

		// Execute corresponding process
        cout <<     "enter the number: " ;
        cin>>choiceNumber;
        while(choiceNumber!=4)
        {
            cin>>choiceNumber;
		switch(choiceNumber){
			case 1:
				test_addition(ppmFileName1, ppmFileName2, ppmFileName3);
				break;
			case 2:
				test_subtraction(ppmFileName1, ppmFileName2, ppmFileName3);
				break;
			case 3:
				read_ppm(ppmFileName1, readPPMImage);
				write_ppm(ppmFileName2, readPPMImage);
				break;
            case 4:
				exit(0);
                break;
            default:
				cout << "Invalid choice number!\n";	// Inform if invalid choice number is entered
		}
        }
	}
int read_ppm(const string source_ppm_file_name, ppmImage &destination_object)
{
    return destination_object.ReadImage(source_ppm_file_name);
}
int write_ppm(const string destination_ppm_file_name, const ppmImage &source_object)
{
    return source_object.WriteImage(destination_ppm_file_name);
}
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3)
{
    ppmImage image1(filename_image1);
    ppmImage image2(filename_image2);
    ppmImage image3 = image1 + image2;
    return write_ppm(filename_image3,image3);
}
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3)
{
    ppmImage image1(filename_image1);
    ppmImage image2(filename_image2);
    ppmImage image3 = image1 - image2;
    return write_ppm(filename_image3,image3);
}
int test_print(const string filename_image1)
{
    ppmImage imagePrint(filename_image1);
    cout << imagePrint;
    return 1;
}