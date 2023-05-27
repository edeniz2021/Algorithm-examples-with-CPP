#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

class Movie
{
public:
    Movie();
    ~Movie();
    int get_length();
    std::string get_title() const;
    std::string get_director() const;
    std::string get_year() const;
    std::string get_starring() const;
    std::string get_genre() const;
    std::string get_artists() const;
    std::string get_tags() const;
    std::string get_authors() const;
    std::string get_data() const;
    void set_dataStore(std::vector<std::string> &v);
    int get_field_number();

private:
    int field_number = 5;
    int length;
    std::string dataStore[5];
};


#endif
