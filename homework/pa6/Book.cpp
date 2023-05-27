#include <iostream>
#include <cstdlib>
#include <string>
#include "Book.h"

Book::Book() {}
Book::~Book() {}
int Book::get_field_number() { return field_number; }
int Book::get_length() { return length; }
std::string Book::get_title() const { return dataStore[0]; }
std::string Book::get_authors() const { return dataStore[1]; }
std::string Book::get_year() const { return dataStore[2]; }
std::string Book::get_genre() const { return dataStore[3]; }
std::string Book::get_starring() const { return ""; }
std::string Book::get_artists() const { return ""; }
std::string Book::get_director() const { return ""; }
std::string Book::get_tags() const { return ""; }
std::string Book::get_data() const
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
void Book::set_dataStore(std::vector<std::string> &v)
{
    int i = 0;
    std::vector<std::string>::iterator itr = v.begin();
    for (i = 0; itr != v.end(); itr++, i++)
    {
        dataStore[i] = *itr;
    }
    length = i;
}
