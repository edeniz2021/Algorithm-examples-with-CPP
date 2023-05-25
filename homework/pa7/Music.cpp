#include <iostream>
#include <cstdlib>
#include <string>
#include "Catalog.h"
#include "Music.h"


Music::Music() {}
Music::~Music() {}
int Music::get_field_number() { return field_number; }
std::string Music::get_title() { return dataStore[0]; }
std::string Music::get_artists() { return dataStore[1]; }
std::string Music::get_year() { return dataStore[2]; }
std::string Music::get_genre() { return dataStore[3]; }
