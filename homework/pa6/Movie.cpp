#include <iostream>
#include <cstdlib>
#include <string>
#include "Movie.h"

Movie::Movie() {}
Movie::~Movie() {}
int Movie::get_field_number() { return field_number; }
int Movie::get_length() { return length; }
std::string Movie::get_title() const { return dataStore[0]; }
std::string Movie::get_artists() const { return ""; }
std::string Movie::get_year() const { return dataStore[2]; }
std::string Movie::get_genre() const { return dataStore[3]; }
std::string Movie::get_starring() const { return dataStore[4]; }
std::string Movie::get_tags() const { return ""; }
std::string Movie::get_director() const { return dataStore[1]; }
std::string Movie::get_authors() const { return ""; }
std::string Movie::get_data() const
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
void Movie::set_dataStore(std::vector<std::string> &v)
{
    int i = 0;
    std::vector<std::string>::iterator itr = v.begin();
    for (i = 0; itr != v.end(); itr++, i++)
    {
        dataStore[i] = *itr;
    }
    length = i;
}
