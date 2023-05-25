#ifndef BOOK_H
#define BOOK_H

#include "Catalog.h"
#include <string>
#include <vector>
#include "Book.cpp"
class Book
{
public:
    Book();
    ~Book();
    std::string get_title();
    std::string get_authors();
    std::string get_year();
    std::string get_tags();
    int get_field_number();

private:
    const int field_number = 4;
	std::string dataStore[4];
};
#endif
