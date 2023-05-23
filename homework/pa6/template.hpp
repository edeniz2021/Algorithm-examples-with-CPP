#ifndef TEMPLATE_H
#define TEMPLATE_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

template<class T>
class Catalog
{
    public:
    Catalog();
    void dataFile(std::string fileName);
    void commandFile(std::string fileName);
    void setPrototype();
    void throw_exception();
    void sortType(std::string type);

    private:
    std::string catalogName;
    std::vector<std::string>prototype;
    std::string allData;
    static int unique;
    std::vector<std::vector<std::string>> dataVec;

};
#endif