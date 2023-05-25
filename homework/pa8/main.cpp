#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

template <class T>
class Catalog
{
public:
    Catalog() {}
    ~Catalog() {}
    void set_data(T obj) { objects.push_back(obj); }
    void sort_objects(const std::string &field)
    {
        std::sort(objects.begin(), objects.end(), [&](const T &a, const T &b)
                  {
                      if (field == "title")
                          return a.get_title() < b.get_title();
                      else if (field == "year")
                          return a.get_year() < b.get_year();
                      else if (field == "artists")
                          return a.get_artists() < b.get_artists();
                      else if (field == "genre")
                          return a.get_genre() < b.get_genre();
                      else
                          return false; });

        for (const T &obj : objects)
        {
            std::cout << obj.get_data() << std::endl;
        }
    }

    // void search_pbject(){}
    const std::vector<T> &get_objects() const
    {
        return objects;
    }
    void set_allData(std::string data)
    {
        allData += data;
    }
    std::string parse_lines(T &obj, const std::string &str)
    {
        std::string tit;
        int count = 0;
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);

        while (getline(tokenStream, token, '\"'))
        {
            if (!token.empty() && token != " " && token.back() != '\r')
            {
                tokens.push_back(token);
                count++;
                if (count == 1)
                {
                    tit = token;
                }
            }
        }
        obj.set_dataStore(tokens);
        return tit;
    }

    bool duplicate_check(const std::string &str) const
    {
        for (const T &obj : get_objects())
        {
            if (obj.get_title() == str)
            {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<T> objects;
    std::string allData;
}; /*
 class Book
 {
 public:
     Book();
     ~Book();
     std::string get_title();
     std::string get_authors();
     std::string get_year();
     std::string get_tags();
     std::string get_data() const;
     void set_dataStore(std::vector<std::string> &v);
     int get_field_number();

 private:
     const int field_number = 4;
     std::string dataStore[4];
     int length;
 };
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
     std::string get_data() const;
     void set_dataStore(std::vector<std::string> &v);
     int get_field_number();

 private:
     const int field_number = 5;
     int length;
     std::string dataStore[5];
 };*/
class Music
{
public:
    Music();
    ~Music();
    std::string get_title() const;
    std::string get_artists() const;
    std::string get_year() const;
    std::string get_genre() const;
    std::string get_data() const;
    int get_length();
    void set_dataStore(std::vector<std::string> &v);
    int get_field_number();

private:
    int field_number = 4;
    int length;
    std::string dataStore[4];
};
/*
Book::Book() {}
Book::~Book() {}
int Book::get_field_number() { return field_number; }
std::string Book::get_title() { return dataStore[0]; }
std::string Book::get_authors() { return dataStore[1]; }
std::string Book::get_year() { return dataStore[2]; }
std::string Book::get_tags() { return dataStore[3]; }
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
    get_data();
}

Movie::Movie() {}
Movie::~Movie() {}
int Movie::get_field_number() { return field_number; }
std::string Movie::get_title() { return dataStore[0]; }
std::string Movie::get_director() { return dataStore[1]; }
std::string Movie::get_year() { return dataStore[2]; }
std::string Movie::get_genre() { return dataStore[3]; }
std::string Movie::get_starring() { return dataStore[4]; }
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
}*/

Music::Music() {}
Music::~Music() {}
int Music::get_field_number() { return field_number; }
int Music::get_length() { return length; }
std::string Music::get_title() const { return dataStore[0]; }
std::string Music::get_artists() const { return dataStore[1]; }
std::string Music::get_year() const { return dataStore[2]; }
std::string Music::get_genre() const { return dataStore[3]; }
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

int main()
{
    std::ifstream data_file("data.txt");
    std::string str;
    data_file >> str;
    if (str == "music")
    {
        Catalog<Music> catalog;
        Music m;
        getline(data_file, str);
        while (getline(data_file, str))
        {
            try
            {
                int count = 0;

                if (catalog.duplicate_check(catalog.parse_lines(m, str)))
                {
                    if (m.get_length() != m.get_field_number())
                    {
                        count = 1;
                        throw std::runtime_error("Exception: missing field");
                    }
                    else
                    {
                        catalog.set_data(m);
                    }
                }
                else
                {
                    if (count == 1)
                    {
                        throw std::runtime_error("Exception: missing field");
                    }
                    else
                    {
                        throw std::runtime_error("Exception: duplicate entry");
                    }
                }
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
                std::cout << str << std::endl;
            }
        }
        std::cout << std::endl;
        catalog.sort_objects("year");
    }
    /*else if (str == "book")
    {
        Catalog<Book> catalog;
        Book b;
        getline(data_file, str);
        while (getline(data_file, str))
        {
            try
            {
                if (catalog.duplicate_check(str))
                {
                    catalog.parse_lines(b, str);
                    catalog.set_data(b);
                }
                else
                {
                    throw std::runtime_error("Exception: duplicate entry");
                }
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
    else if (str == "movie")
    {
        Catalog<Movie> catalog;
        Movie m;
        getline(data_file, str);
        while (getline(data_file, str))
        {
            try
            {

                if (catalog.duplicate_check(str))
                {
                    catalog.parse_lines(m, str);
                    catalog.set_data(m);
                }
                else
                {
                    throw std::runtime_error("Exception: duplicate entry");
                }
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }*/
}