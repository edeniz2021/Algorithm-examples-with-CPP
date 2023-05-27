#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

template <class T>
class Catalog
{
public:
    Catalog();
    ~Catalog();
    void set_data(T obj)
    {
        unique++;
        objects.push_back(obj);
    }
    int get_unique() { return unique; }
    void write_to_file(const std::string &filename) const;
    void sort_objects(const std::string &field);
    std::vector<std::vector<std::string>> parseCommands(const std::string &fileName);
    void search_objects(const std::string &searchStr, const std::string &field);
    bool duplicate_check(const std::string &str) const;
    std::string parse_lines(T &obj, const std::string &str);
    template <typename Compare>
    bool count_and_sort(const std::string &field, Compare comp, int &emptyCount)
    {
        for (const T &obj : objects)
        {
            if (get_field_value(obj, field).empty())
            {
                emptyCount++;
            }
        }

        if (emptyCount != objects.size())
        {
            std::sort(objects.begin(), objects.end(), comp);
            return true;
        }

        return false;
    }
    const std::vector<T> &get_objects() const
    {
        return objects;
    }
    void set_allData(std::string data)
    {
        allData += data;
    }
    void process_data_file(std::ifstream &data_file);

private:
    std::vector<T> objects;
    std::string allData;
    static int unique;
};
template <class T>
int Catalog<T>::unique = 0;

template <class T>
Catalog<T>::Catalog() {}

template <class T>
Catalog<T>::~Catalog() {}

template <class T>
void Catalog<T>::sort_objects(const std::string &field)
{
    std::string sortStr;
    sortStr += "sort \"" + field + "\"\n";
    try
    {
        bool sortPerformed = false;
        int emptyCount = 0;

        if (field == "title" || field == "authors" || field == "year" || field == "director" || field == "genre" || field == "tags" || field == "artists" || field == "starring")
        {
            sortPerformed = count_and_sort(
                field, [this, field](const T &m1, const T &m2)
                { return get_field_value(m1, field) < get_field_value(m2, field); },
                emptyCount);
        }

        if (sortPerformed)
        {
            allData += sortStr;
            for (const T &obj : objects)
            {
                allData += obj.get_data() + "\n";
            }
        }
        else
        {
            throw std::runtime_error("Exception: command is wrong");
        }
    }
    catch (const std::exception &e)
    {
        allData += std::string(e.what()) + "\n";
        allData += sortStr+ "\n";
    }
}
template <class T>
void Catalog<T>::search_objects(const std::string &searchStr, const std::string &field)
{
    bool found = false;
    std::string search;
    search += "search \"" + searchStr + "\" in \"" + field + "\"\n";
    for (const T &obj : objects)
    {

        if (field == "title" && obj.get_title().find(searchStr) != std::string::npos)
        {
            allData += search;
            allData += obj.get_data() + "\n";
            found = true;
        }
        else if (field == "artists" && obj.get_artists().find(searchStr) != std::string::npos)
        {
            allData += search;
            allData += obj.get_data() + "\n";
            found = true;
        }
        else if (field == "year" && obj.get_year().find(searchStr) != std::string::npos)
        {
            allData += search;
            allData += obj.get_data() + "\n";
            found = true;
        }
        else if (field == "genre" && obj.get_genre().find(searchStr) != std::string::npos)
        {
            allData += search;
            allData += obj.get_data() + "\n";
            found = true;
        }
        else if (field == "tags" && obj.get_tags().find(searchStr) != std::string::npos)
        {
            allData += search;
            allData += obj.get_data() + "\n";
            found = true;
        }
        else if (field == "director" && obj.get_director().find(searchStr) != std::string::npos)
        {
            allData += search;
            allData += obj.get_data() + "\n";
            found = true;
        }
        else if (field == "starring" && obj.get_starring().find(searchStr) != std::string::npos)
        {
            allData += search;
            allData += obj.get_data() + "\n";
            found = true;
        }
        else if (field == "authors" && obj.get_authors().find(searchStr) != std::string::npos)
        {
            allData += search;
            allData += obj.get_data() + "\n";
            found = true;
        }
    }
    try
    {
        if (!found)
        {
            throw std::runtime_error("Exception: command is wrong");
        }
    }
    catch (const std::exception &e)
    {
        allData += std::string(e.what()) + "\n";
        allData += search;
    }
}
template <class T>
std::string Catalog<T>::parse_lines(T &obj, const std::string &str)
{
    std::string tit;
    int count = 0;
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);

    while (getline(tokenStream, token, '\"'))
    {
        if (count % 2 == 1)
        {
            if (token.empty() || token == " ")
            {
                token = "";
            }
            tokens.push_back(token);
            count++;
            if (count == 2)
            {
                tit = token;
            }
        }
        else
        {
            count++;
        }
    }
    obj.set_dataStore(tokens);
    return tit;
}

template <class T>
bool Catalog<T>::duplicate_check(const std::string &str) const
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

template <class T>
void Catalog<T>::process_data_file(std::ifstream &data_file)
{
    std::string str;
    getline(data_file, str);

    T m;
    while (getline(data_file, str))
    {
        try
        {
            int count = 0;

            if (duplicate_check(parse_lines(m, str)))
            {
                if (m.get_length() != m.get_field_number())
                {
                    count = 1;
                    throw std::runtime_error("Exception: missing field");
                }
                else
                {
                    set_data(m);
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
            allData += std::string(e.what()) + "\n";
            allData += str + "\n";
        }
    }
}
template <class T>
std::vector<std::vector<std::string>> Catalog<T>::parseCommands(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::string line;
    std::vector<std::vector<std::string>> commands;
    std::vector<std::string> row{"", "", ""};
    std::string searchStr, inStr, field;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string command;
        std::getline(iss, searchStr, '\"');
        row[0] = searchStr;
        if (row[0] == "search ")
        {
            getline(iss, inStr, '\"');
            row[1] = inStr;
            getline(iss, command, '\"');
            getline(iss, field, '\"');
            row[2] = field;
        }
        else if (row[0] == "sort ")
        {
            getline(iss, inStr, '\"');
            row[1] = inStr;
        }
        commands.push_back(row);
    }

    file.close();
    return commands;
}
template <class T>
void Catalog<T>::write_to_file(const std::string &filename) const
{
    std::ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        outputFile << allData;
        outputFile.close();
    }
    else
    {
        std::cout << "Error opening file: " << filename << std::endl;
    }
}

#endif