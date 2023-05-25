#ifndef MUSIC_H
#define MUSIC_H

#include <string>
#include <vector>
#include "Catalog.h"
#include "Music.cpp"

class Music 
{
public:
    Music();
    ~Music();
    std::string get_title();
    std::string get_artists();
    std::string get_year();
    std::string get_genre();
    int get_field_number();

private:
    const int field_number = 4;
	std::string dataStore[4];
};

#endif
