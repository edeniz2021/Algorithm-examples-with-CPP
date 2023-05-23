#include <iostream>
#include <sstream>
#include "template.hpp"

template <class T>
Catalog<T>::Catalog()
{
    dataFile("data.txt");
}

template <class T>
void Catalog<T>::dataFile(std::string fileName)
{
    std::ifstream File(fileName);
    std::string data;
    getline(File, catalogName);
    setPrototype();
    allData += "Catalog Read: " + catalogName + "\n";

    while (getline(File, data))
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(data);

        while (getline(tokenStream, token, '\"'))
        {
            if (!token.empty() && token != " " && token.back() != '\r')
                tokens.push_back(token);
        }
        dataVec.push_back(tokens);
    }
    File.close();
    throw_exception();
    /*for (const auto &item : dataVec)
     {
         for (const auto &token : item)
         {
             std::cout << token << std::endl;
         }
     }*/
}

template <class T>
void Catalog<T>::commandFile(std::string fileName)
{
    std::ifstream File(fileName);
}

template <class T>
void Catalog<T>::setPrototype()
{
    if (catalogName == "movie")
        prototype = {"title", "director", "year", "genre", "starring"};
    else if (catalogName == "book")
        prototype = {"title", "authors", "year", "tags"};
    else if (catalogName == "music")
        prototype = {"title", "artists", "year", "genre"};
    prototype.size();
    /*for (const std::string &item : prototype)
    {
        std::cout << item << std::endl;
    }*/
}
template <class T>
void Catalog<T>::throw_exception()
{
    int i, j, k;
    try
    {
        for (i = 0; i < dataVec.size(); ++i)
        {
            for (j = i + 1; j < dataVec.size(); ++j)
            {
                if (dataVec[i][0] == dataVec[j][0])
                {
                    unique++;
                    throw std::runtime_error("Exception: duplicate entry");
                }
            }
        }
    }
    catch (const std::exception &e)
    {
        for (k = 0; k < dataVec[i].size(); k++)
        {
            allData += dataVec[i][k] + " ";
        }
        allData += "\n";
        allData += std::string(e.what()) + "\n";
        dataVec.erase(dataVec.begin() + i);
    }
    try
    {
        for (i = 0; i < dataVec.size(); ++i)
        {
            if (dataVec[i].size() != prototype.size())
            {
                unique++;
                throw std::runtime_error("Exception: missing field");
            }
        }
    }
    catch (const std::exception &e)
    {
        for (k = 0; k < dataVec[i].size(); k++)
        {
            allData += dataVec[i][k] + " ";
        }
        allData += "\n";
        allData += std::string(e.what()) + "\n";
        dataVec.erase(dataVec.begin() + i);
    }
    std::string uni = std::to_string(unique);
    allData += uni + " unique entries" + "\n";
    std::cout << allData;
    sortType("year");
}
template <class T>
void Catalog<T>::sortType(std::string type)
{
    int i, j, x;
    int n = dataVec.size();
    for (x = 0; x < prototype.size(); ++x)
    {
        if (prototype[x] == type)
            break;
    }
    std::sort(dataVec.begin(), dataVec.end(), [&](const std::vector<std::string> &a, const std::vector<std::string> &b)
              { return a[x] < b[x]; });
    /*for (const auto& row : dataVec) {
    for (const std::string& value : row) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    }*/
}

template <class T>
int Catalog<T>::unique = 0;