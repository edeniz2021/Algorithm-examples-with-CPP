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
    int ReadImage(const string fileName);        // to read the file
    int WriteImage(const string fileName) const; // to write the file
    void setPixelInfo(int w, int h, int color, int value);
    void printDimensionPpm() const;
    void setWidth(int w) { width = w; }
    void setHeigth(int h) { heigth = h; }
    int getWidth() const { return width; }
    int getHeigth() const { return heigth; }
    int getPix() const { return pix; }
    int getPixelInfo(int w, int h, int color);
    void swap(int &a, int &b);
    ppmImage operator+(const ppmImage &I);
    ppmImage operator-(const ppmImage &I);
    friend ostream &operator<<(ostream &out, const ppmImage &I);
    int &operator()(int w, int h, int color);
    const int &operator()(int w, int h, int color) const;

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
    pixel.resize(heigth, vector<int>(width * 3));
    pix = 255;
    format = "P3";
}
ppmImage::ppmImage(const string fileName)
{
    ReadImage(fileName);
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
int ppmImage::WriteImage(const string fileName) const
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
void ppmImage::printDimensionPpm() const
{
    cout << width << " " << heigth << endl;
}
// Operator overloading for addition of two ppmImage objects.
ppmImage ppmImage::operator+(const ppmImage &I)
{
    if (heigth != I.heigth || width != I.width) // Check if the heights and widths of the two images are the same.
    {
        return ppmImage(0, 0); // If not, return a default ppmImage object with height and width set to 0.
    }
    ppmImage sum(width, heigth);                              // Create a new ppmImage object to store the sum with the same height and width as the original images.
    sum.pixel.resize(sum.heigth, vector<int>(sum.width * 3)); // Resize the pixel matrix of the sum image to match the height and width.

    sum.pix = I.pix + pix; // Add the pixel values of the two images and store the result in the sum image.
    if (sum.pix > 255)     // Clamp the pixel values to the maximum of 255.
        sum.pix = 255;

    for (int i = 0; i < getHeigth(); i++) // Loop through each row of the images.
    {
        for (int j = 0; j < getWidth() * 3; j += 3) // Loop through each pixel in the row.
        {
            // Add the pixel values of the corresponding pixels in the two images and store the result in the sum image's pixel matrix.
            sum.pixel[i][j] = max(255,pixel[i][j] + I.pixel[i][j]);
            sum.pixel[i][j + 1] = max(255,pixel[i][j + 1] + I.pixel[i][j + 1]);
            sum.pixel[i][j + 2] = max(255,pixel[i][j + 2] + I.pixel[i][j + 2]);
        }
    }
    return sum; // Return the sum image.
}
ppmImage ppmImage::operator-(const ppmImage &I)
{
    if (heigth != I.heigth || width != I.width)
    {
        return ppmImage();
    }
    ppmImage diff(width, heigth);
    diff.pixel.resize(diff.heigth, vector<int>(diff.width * 3));
    diff.pix = 255;
    for (int i = 0; i < getHeigth(); i++)
    {
        for (int j = 0; j < getWidth() * 3; j += 3)
        {
            diff.pixel[i][j] = min(0,pixel[i][j] - I.pixel[i][j]);
            diff.pixel[i][j + 1] = min(0,pixel[i][j + 1] - I.pixel[i][j + 1]);
            diff.pixel[i][j + 2] = min(0,pixel[i][j + 2] - I.pixel[i][j + 2]);
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
    int &result = pixel[h][w * 3 + color-1];
    return result;
}
const int &ppmImage::operator()(int w, int h, int color) const
{
    const int &result = pixel[h][w * 3 + color-1];
    return result;
}
// Member function to return individual pixel information
int ppmImage::getPixelInfo(int w, int h, int color)
{
    return pixel[h][w * 3 + color-1]; // Since each pixel has three color values (r, g, b), we multiply the width by 3 and add the color index to get the corresponding color value.
}

// Member function to change individual pixel values
void ppmImage::setPixelInfo(int w, int h, int color, int value)
{
    pixel[h][w * 3 + color-1] = value; // Since each pixel has three color values (r, g, b), we multiply the width by 3 and add the color index to set the corresponding color value.
}
void ppmImage::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int read_ppm(const string source_ppm_file_name, ppmImage &destination_object);
int write_ppm(const string destination_ppm_file_name, const ppmImage &source_object);
int swap_channels(ppmImage &image_object_to_be_modified, int swap_choice);
ppmImage single_color(const ppmImage &source, int color_choice);
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3);
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3);
int test_print(const string filename_image1);

int main(int argc, char **argv)
{
    // Check for number of command line arguments
    // The first argument is the choice number
    // The second argument is ppm_file_name1
    // The third argument is ppm_file_name2 (optional)
    // The fourth argument is ppm_file_name3 (optional)
    if (argc < 4 || argc > 5)
    {
        cout << "Invalid number of arguments!" << endl;
        return 0;
    }

    int choiceNumber = stoi(argv[1]); // Convert argument to integer
    string ppm_file_name1(argv[2]);   // File name for ppm_file_name1
    string ppm_file_name2;            // File name for ppm_file_name2
    string ppm_file_name3;            // File name for ppm_file_name3

    if (argc == 4)
    {
        ppm_file_name2 = string(argv[3]); // File name for ppm_file_name2
    }
    if (argc == 5)
    {
        ppm_file_name2 = string(argv[3]); // File name for ppm_file_name2
        ppm_file_name3 = string(argv[4]); // File name for ppm_file_name3
    }

    ppmImage readImage;      // Image of read file
    ppmImage processedImage; // Image that is the result of process

    // Execute corresponding process based on choice number
    switch (choiceNumber)
    {
    case 1:
        if (argc != 5)
        {
            cout << "Invalid number of arguments!" << endl;
            return 0;
        }
        test_addition(ppm_file_name1, ppm_file_name2, ppm_file_name3);
        break;
    case 2:
        if (argc != 5)
        {
            cout << "Invalid number of arguments!" << endl;
            return 0;
        }
        test_subtraction(ppm_file_name1, ppm_file_name2, ppm_file_name3);
        break;
    case 3:
        read_ppm(ppm_file_name1, readImage);
        swap_channels(readImage, 2);
        write_ppm(ppm_file_name2, readImage);
        break;
    case 4:
        read_ppm(ppm_file_name1, readImage);
        swap_channels(readImage, 3);
        write_ppm(ppm_file_name2, readImage);
        break;
    case 5:
        read_ppm(ppm_file_name1, readImage);
        processedImage = single_color(readImage, 1);
        write_ppm(ppm_file_name2, processedImage);
        break;
    case 6:
        read_ppm(ppm_file_name1, readImage);
        processedImage = single_color(readImage, 2);
        write_ppm(ppm_file_name2, processedImage);
        break;
    case 7:
        read_ppm(ppm_file_name1, readImage);
        processedImage = single_color(readImage, 3);
        write_ppm(ppm_file_name2, processedImage);
        break;
    default:
        cout << "Invalid choice number!" << endl; // Inform if invalid choice number is entered
        exit(0);
    }
    return 0;
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
    return write_ppm(filename_image3, image3);
}
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3)
{
    ppmImage image1(filename_image1);
    ppmImage image2(filename_image2);
    ppmImage image3 = image1 - image2;
    return write_ppm(filename_image3, image3);
}
int test_print(const string filename_image1)
{
    ppmImage imagePrint(filename_image1);
    cout << imagePrint;
    return 1;
}
ppmImage single_color(const ppmImage &source, int color_choice)
{
    ppmImage temp(source.getWidth(), source.getHeigth());

    for (int i = 0; i < source.getHeigth(); i++)
    {
        for (int j = 0; j < source.getWidth(); j++)
        {
            // Copy only the selected color channel and set other channels to zero
            switch (color_choice)
            {
            case 1:                              // Red channel is preserved
                temp(i, j, 1) = source(i, j, 1); // Red channel
                temp(i, j, 2) = 0;               // Green channel
                temp(i, j, 3) = 0;               // Blue channel
                break;
            case 2:                              // Green channel is preserved
                temp(i, j, 1) = 0;               // Red channel
                temp(i, j, 2) = source(i, j, 2); // Green channel
                temp(i, j, 3) = 0;               // Blue channel
                break;
            case 3:                              // Blue channel is preserved
                temp(i, j, 1) = 0;               // Red channel
                temp(i, j, 2) = 0;               // Green channel
                temp(i, j, 3) = source(i, j, 3); // Blue channel
                break;
            }
        }
    }
    return temp;
}
int swap_channels(ppmImage &image_object_to_be_modified, int swap_choice)
{
    int width = image_object_to_be_modified.getWidth();
    int height = image_object_to_be_modified.getHeigth();
    int result = 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Copy only the selected color channel and set other channels to zero
            switch (swap_choice)
            {
            case 1:                                                                               // Red  and green swap
                swap(image_object_to_be_modified(i, j, 1), image_object_to_be_modified(i, j, 2)); // Swap red and green channels
                break;
            case 2:                                                                               // Red and blue swap
                swap(image_object_to_be_modified(i, j, 1), image_object_to_be_modified(i, j, 3)); // Swap red and blue channels
                break;
            case 3:                                                                               // green and blue swap
                swap(image_object_to_be_modified(i, j, 2), image_object_to_be_modified(i, j, 3)); // Swap green and blue channels
                break;
            default: // No swaps
                result = 0;
                break;
            }
        }
    }
    return result; // Operation is successful
}
