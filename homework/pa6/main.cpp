#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Movie.h"
#include "Music.h"
#include "Book.h"
#include "Catalog.h"
template <typename T>
std::string get_field_value(const T &obj, const std::string &field)
{
    if (field == "title")
    {
        return obj.get_title();
    }
    else if (field == "authors")
    {
        return obj.get_authors();
    }
    else if (field == "year")
    {
        return obj.get_year();
    }
    else if (field == "director")
    {
        return obj.get_director();
    }
    else if (field == "genre")
    {
        return obj.get_genre();
    }
    else if (field == "tags")
    {
        return obj.get_tags();
    }
    else if (field == "artists")
    {
        return obj.get_artists();
    }
    else if (field == "starring")
    {
        return obj.get_starring();
    }

    return "";
}
int main()
{
    std::ifstream data_file("data.txt");
    std::string str;
    data_file >> str;

    if (str == "music")
    {
        Catalog<Music> catalog;
        catalog.set_allData("Catalog read: music\n");
        catalog.process_data_file(data_file);
        std::string unique_entities;
        unique_entities += std::to_string(catalog.get_unique()) + " unique entries\n";
        catalog.set_allData(unique_entities);
        std::vector<std::vector<std::string>> commands = catalog.parseCommands("command.txt");
        for (const auto &command : commands)
        {
            const std::string &cmd = command[0];
            if (cmd == "search ")
            {
                const std::string &searchStr = command[1];
                const std::string &field = command[2];
                catalog.search_objects(searchStr, field);
            }
            else if (cmd == "sort ")
            {
                const std::string &field = command[1];
                catalog.sort_objects(field);
            }
        }
        catalog.write_to_file("output.txt");
    }
    else if (str == "book")
    {
        Catalog<Book> catalog;
        catalog.set_allData("Catalog read: book\n");
        catalog.process_data_file(data_file);
        std::string unique_entities;
        unique_entities += std::to_string(catalog.get_unique()) + " unique entries\n";
        catalog.set_allData(unique_entities);
        std::vector<std::vector<std::string>> commands = catalog.parseCommands("command.txt");
        for (const auto &command : commands)
        {
            const std::string &cmd = command[0];
            if (cmd == "search ")
            {
                const std::string &searchStr = command[1];
                const std::string &field = command[2];
                catalog.search_objects(searchStr, field);
            }
            else if (cmd == "sort ")
            {
                const std::string &field = command[1];
                catalog.sort_objects(field);
            }
        }
        catalog.write_to_file("output.txt");
    }
    else if (str == "movie")
    {
        Catalog<Movie> catalog;
        catalog.set_allData("Catalog read: movie\n");
        catalog.process_data_file(data_file);
        std::string unique_entities;
        unique_entities += std::to_string(catalog.get_unique()) + " unique entries\n";
        catalog.set_allData(unique_entities);
        std::vector<std::vector<std::string>> commands = catalog.parseCommands("command.txt");
        for (const auto &command : commands)
        {
            const std::string &cmd = command[0];
            if (cmd == "search ")
            {
                const std::string &searchStr = command[1];
                const std::string &field = command[2];
                catalog.search_objects(searchStr, field);
            }
            else if (cmd == "sort ")
            {
                const std::string &field = command[1];
                catalog.sort_objects(field);
            }
        }
        catalog.write_to_file("output.txt");
    }
    return 0;
}