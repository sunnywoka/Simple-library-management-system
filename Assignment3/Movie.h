#pragma once
#include <iostream>
#include <string>
#include "LibraryItem.h"//using base class header file

using namespace std;

//devired class inherite from base class
class Movie : public LibraryItem
{
public:
	Movie(string type, int id, string title, int year, string director) : LibraryItem(type, id, title, year), mDirector(director) {}//constructor
	~Movie(){}//destructor
	void print() const override;
private:
	//this movie class own data type
	string mDirector;
};

//override the method
void Movie::print() const {
	LibraryItem::print();
	cout << "Director: " << mDirector << endl;
	cout << " " << endl;
}