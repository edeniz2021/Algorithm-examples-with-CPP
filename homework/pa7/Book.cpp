#include <iostream>
#include <cstdlib>
#include <string>
#include "Catalog.h"
#include "Book.h"

using namespace std;

Book::Book() {}
Book::~Book() {}
int Book::get_field_number() { return field_number; }
std::string Book::get_title(){ return dataStore[0];}
std::string Book::get_authors(){ return dataStore[1];}
std::string Book::get_year(){ return dataStore[2];}
std::string Book::get_tags(){ return dataStore[3];}