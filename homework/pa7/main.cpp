#include <iostream>
#include <fstream>
#include <string>
#include "Movie.h"
#include "Music.h"
#include "Book.h"
#include "Catalog.h"
int main()
{
    std::ifstream data_file("data.txt");
    std::ofstream out_f("output.txt");
    std::string str;

    data_file >> str;

    if (str == "music")
    {
        out_f << "Catalog Read: music" << std::endl;
        Catalog<Music> catalog;
        Music *m = new Music; 
    }
    else
    {
        return 0;
    }

    return 0;
}
