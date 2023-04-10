#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
class Image
{
public:
    Image();
    Image(const string fileName);
    Image(int width,int heigth);
    void Menu();
    void openImage();//to read the file
    void saveImage();//to write the file
    void scriptImage();//to make grayscale
    void printPpm()const;
    int getWidth() const { return width; }
    int getHeigth() const { return heigth; }
    int getPix() const { return pix; }

private:
    int width, heigth, pix;
    vector<vector<int> > pixel;//keeps pixel data
    string format;
};
