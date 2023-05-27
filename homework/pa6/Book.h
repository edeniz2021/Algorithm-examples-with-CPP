#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
class Book
{
public:
    Book();
    ~Book();
    std::string get_title() const;
    std::string get_director() const;
    std::string get_year() const;
    std::string get_starring() const;
    std::string get_genre() const;
    std::string get_authors() const;
    std::string get_artists() const;
    std::string get_tags() const;
    void set_dataStore(std::vector<std::string> &v);
    std::string get_data() const;
    int get_field_number();
    int get_length();

private:
    int field_number = 4;
    int length;
    std::string dataStore[4];
};
#endif
