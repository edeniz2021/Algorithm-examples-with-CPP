#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include "Catalog.h"
#include "Movie.cpp"

class Movie
{
public:
    Movie();
    ~Movie();
    std::string get_title();
    std::string get_director();
    std::string get_year();
    std::string get_genre();
    std::string get_starring();
    int get_field_number();

private:
    const int field_number = 5;
	std::string dataStore[5];
};

#endif
