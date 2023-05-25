#ifndef CATALOG_H
#define CATALOG_H
#include <iostream>
#include <vector>

template <class T>
class Catalog
{
public:
	Catalog();
	~Catalog();
	void set_data(T obj) { objects.push_back(obj); }
	//void sort_object(){}
	//void search_pbject(){}

protected:
	std::vector<T> objects;
	std::string allData;
};

#endif