#include <iostream>
#include <cstdlib>
#include <string>
#include "Music.h"

Music::Music() {}
Music::~Music() {}
int Music::get_field_number() { return field_number; }
int Music::get_length() { return length; }
std::string Music::get_title() const { return dataStore[0]; }
std::string Music::get_artists() const { return dataStore[1]; }
std::string Music::get_year() const { return dataStore[2]; }
std::string Music::get_genre() const { return dataStore[3]; }
std::string Music::get_starring() const { return ""; }
std::string Music::get_tags() const { return ""; }
std::string Music::get_authors() const { return ""; }
std::string Music::get_director() const { return ""; }
std::string Music::get_data() const
{
    std::string data;
    for (int i = 0; i < field_number; i++)
    {
        data += "\"" + dataStore[i] + "\"";
        if (i != field_number - 1)
            data += " ";
    }
    return data;
}
void Music::set_dataStore(std::vector<std::string> &v)
{
    int i = 0;
    std::vector<std::string>::iterator itr = v.begin();
    for (i = 0; itr != v.end(); itr++, i++)
    {
        dataStore[i] = *itr;
    }
    length = i;
}
