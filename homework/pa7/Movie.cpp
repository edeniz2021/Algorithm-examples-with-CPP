#include <iostream>
#include <cstdlib>
#include <string>
#include "Catalog.h"
#include "Movie.h"



Movie::Movie() {}
Movie::~Movie() {}
int Movie::get_field_number() { return field_number; }
std::string Movie::get_title(){ return dataStore[0];}
std::string Movie::get_director(){ return dataStore[1];}
std::string Movie::get_year(){ return dataStore[2];}
std::string Movie::get_genre(){ return dataStore[3];}
std::string Movie::get_starring(){ return dataStore[4];}
