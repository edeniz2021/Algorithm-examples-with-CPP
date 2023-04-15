#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
struct Pixel
{
    int red;
    int blue;
    int green;
};
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
    int getPixelInfo(int w, int h, int color)const;
    ppmImage operator+(const ppmImage &I);
    ppmImage operator-(const ppmImage &I);
    friend ostream &operator<<(ostream &out, const ppmImage &I);
    int operator()(int w, int h, int color);
    const int operator()(int w, int h, int color) const;

private:
    int width, heigth, pix;
    vector<vector<Pixel> > pixel; // keeps pixel data
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
    pixel.resize(heigth, vector<Pixel>(width));
    pix = 255;
    format = "P3";
}
ppmImage::ppmImage(const string fileName)
{
    ReadImage(fileName);
}

int ppmImage::ReadImage(const string fileName)
{
    int x;
    ifstream file(fileName); // read image data from a file and store it in the pixel matrix
    if (file.is_open())
    {
        file >> format;
        file >> width >> heigth >> pix;
        pixel.resize(heigth, vector<Pixel>(width)); // the pixel matrix is resized to match the width and height of the image
        for (int i = 0; i < heigth; i++)
        {
            for (int j = 0; j < width; j++)
            {
                file >> pixel[i][j].red >> pixel[i][j].green >> pixel[i][j].blue;
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
        for (int h = 0; h < heigth; h++)
        {
            for (int w = 0; w < width; w++)
            {
                file << pixel[h][w].red << " " << pixel[h][w].green << " " << pixel[h][w].blue << " ";
            }
            file << endl;
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
    cout << "Format: " << format << endl;
    cout << "Width: " << width << endl;
    cout << "Height: " << heigth << endl;
    cout << "Max Value: " << pix << endl;
}
int ppmImage::getPixelInfo(int w, int h, int color)const
{
    if (w >= 0 && w < width && h >= 0 && h < heigth)
    {
        if (color == 1)
            return pixel[h][w].red;
        else if (color == 2)
            return pixel[h][w].green;
        else if (color == 3)
            return pixel[h][w].blue;
        else
        {
            cout << "Error: Invalid color channel! (1 for red, 2 for green, 3 for blue)" << endl;
            return 0;
        }
    }
    else
    {
        cout << "Error: Invalid pixel index!" << endl;
        return 0;
    }
}
void ppmImage::setPixelInfo(int w, int h, int color, int value)
{
    if (w >= 0 && w < width && h >= 0 && h < heigth)
    {
        if (color == 1)
            pixel[h][w].red = value;
        else if (color == 2)
            pixel[h][w].green = value;
        else if (color == 3)
            pixel[h][w].blue = value;
        else
            cout << "Error: Invalid color channel! (1 for red, 2 for green, 3 for blue)" << endl;
    }
    else
        cout << "Error: Invalid pixel index!" << endl;
}
// Operator overloading for addition of two ppmImage objects.
ppmImage ppmImage::operator+(const ppmImage &I)
{
    if (heigth != I.heigth || width != I.width) // Check if the heights and widths of the two images are the same.
    {
        return ppmImage(0, 0); // If not, return a default ppmImage object with height and width set to 0.
    }
    ppmImage sum(width, heigth);                    // Create a new ppmImage object to store the sum with the same height and width as the original images.
    sum.pixel.resize(heigth, vector<Pixel>(width)); // Resize the pixel matrix of the sum image to match the height and width.

    sum.pix = I.pix + pix; // Add the pixel values of the two images and store the result in the sum image.
    if (sum.pix > 255)     // Clamp the pixel values to the maximum of 255.
        sum.pix = 255;

    for (int i = 0; i < getHeigth(); i++) // Loop through each row of the images.
    {
        for (int j = 0; j < getWidth(); j++) // Loop through each pixel in the row.
        {
            // Add the pixel values of the corresponding pixels in the two images and store the result in the sum image's pixel matrix.
            sum.pixel[i][j].red = min(255, pixel[i][j].red + I.pixel[i][j].red);
            sum.pixel[i][j].green = min(255, pixel[i][j].green + I.pixel[i][j].green);
            sum.pixel[i][j].blue = min(255, pixel[i][j].blue + I.pixel[i][j].blue);
        }
    }
    return sum; // Return the sum image.
}
ppmImage ppmImage::operator-(const ppmImage &I)
{
    if (heigth != I.heigth || width != I.width)
    {
        // Return an empty ppmImage object if the images have different dimensions
        return ppmImage();
    }

    ppmImage diff(width, heigth);
    diff.pixel.resize(heigth, vector<Pixel>(width));

    for (int h = 0; h < heigth; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Subtract pixel values and clamp to minimum of 0
            diff.pixel[h][w].red = max(0, pixel[h][w].red - I.pixel[h][w].red);
            diff.pixel[h][w].green = max(0, pixel[h][w].green - I.pixel[h][w].green);
            diff.pixel[h][w].blue = max(0, pixel[h][w].blue - I.pixel[h][w].blue);
        }
    }

    return diff;
}

ostream &operator<<(ostream &out, const ppmImage &I)
{
    // Output the image format, width, height, and max pixel value
    out << "Format: " << I.format << endl;
    out << "Width: " << I.width << endl;
    out << "Height: " << I.heigth << endl;
    out << "Max Value: " << I.pix << endl;

    // Output the pixel data
    for (int h = 0; h < I.heigth; h++)
    {
        for (int w = 0; w < I.width; w++)
        {
            out << I.pixel[h][w].red << " "
                << I.pixel[h][w].green << " "
                << I.pixel[h][w].blue << endl;
        }
    }
    return out;
}
// operator() overload for ppmImage class
int ppmImage::operator()(int w, int h, int color)
{
    // Check if the given coordinates are within the image boundaries
    if (w >= 0 && w < width && h >= 0 && h < heigth)
    {
        // Check the color value (0 for red, 1 for green, 2 for blue)
        if (color == 1)
        {
            // Return the red component of the pixel at the given coordinates
            return pixel[h][w].red;
        }
        else if (color == 2)
        {
            // Return the green component of the pixel at the given coordinates
            return pixel[h][w].green;
        }
        else if (color == 3)
        {
            // Return the blue component of the pixel at the given coordinates
            return pixel[h][w].blue;
        }
        else
        {
            // Invalid color value
            cout << "Error: Invalid color value. Valid values are 0, 1, or 2." << endl;
            return -1; // or throw an exception, depending on your implementation
        }
    }
    else
    {
        // Invalid coordinates
        cout << "Error: Invalid coordinates." << endl;
        return -1; // or throw an exception, depending on your implementation
    }
}

const int ppmImage::operator()(int w, int h, int color) const
{
    if (w >= 0 && w < width && h >= 0 && h < heigth)
    {
        // Check the color value (0 for red, 1 for green, 2 for blue)
        if (color == 1)
        {
            // Return the red component of the pixel at the given coordinates
            return pixel[h][w].red;
        }
        else if (color == 2)
        {
            // Return the green component of the pixel at the given coordinates
            return pixel[h][w].green;
        }
        else if (color == 3)
        {
            // Return the blue component of the pixel at the given coordinates
            return pixel[h][w].blue;
        }
        else
        {
            // Invalid color value
            cout << "Error: Invalid color value. Valid values are 0, 1, or 2." << endl;
            return -1; // or throw an exception, depending on your implementation
        }
    }
    else
    {
        // Invalid coordinates
        cout << "Error: Invalid coordinates." << endl;
        return -1; // or throw an exception, depending on your implementation
    }
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
    case 8:
        exit(0);
        break;
    default:
        cout << "Invalid choice number!" << endl; // Inform if invalid choice number is entered
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
    // Get source image dimensions
    int width = source.getWidth();
    int height = source.getHeigth();

    // Create a new ppmImage object with the same dimensions as the source image
    ppmImage result(width, height);

    // Loop through each pixel in the source image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Get the color value for the specified color choice
            if (color_choice == 1)
            {
                result.setPixelInfo(w, h, 1, source(w, h, 1));
                result.setPixelInfo(w, h, 2,0);
                result.setPixelInfo(w, h, 3,0);
            }
            else if (color_choice == 2)
            {
                result.setPixelInfo(w, h, 2, source(w, h, 2));
                result.setPixelInfo(w, h, 1,0);
                result.setPixelInfo(w, h, 3,0);
            }
            else if (color_choice == 3)
            {
                result.setPixelInfo(w, h, 3, source(w, h, 3));
                result.setPixelInfo(w, h, 2,0);
                result.setPixelInfo(w, h, 1,0);
            }
            else
            {
                return ppmImage(); // Return an empty ppmImage object
            }
        }
    }
    // Return the resulting ppmImage object
    return result;
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
            case 1: // Red and green swap
            {
                int temp = image_object_to_be_modified(i, j, 1);                                         // Store red channel value in temp
                image_object_to_be_modified.setPixelInfo(i, j, 1, image_object_to_be_modified(i, j, 2)); // Assign green channel value to red channel
                image_object_to_be_modified.setPixelInfo(i, j, 2, temp);                                              // Assign temp value to green channel
            }
            break;
            case 2: // Red and blue swap
            {
                int temp = image_object_to_be_modified(i, j, 1);                                         // Store red channel value in temp
                image_object_to_be_modified.setPixelInfo(i, j, 1, image_object_to_be_modified(i, j, 3)); // Assign blue channel value to red channel
                image_object_to_be_modified.setPixelInfo(i, j, 3, temp);                                              // Assign temp value to blue channel
            }
            break;
            case 3: // Green and blue swap
            {
                int temp = image_object_to_be_modified(i, j, 2);                                         // Store green channel value in temp
                image_object_to_be_modified.setPixelInfo(i, j, 2, image_object_to_be_modified(i, j, 3)); // Assign blue channel value to green channel
                image_object_to_be_modified.setPixelInfo(i, j, 3, temp);                                              // Assign temp value to blue channel
            }
            break;
            default: // No swaps
                result = 0;
                break;
            }
        }
    }
    return result;
}
