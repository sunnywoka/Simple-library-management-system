#pragma once
#include <iostream>
#include <string>
#include "LibraryItem.h"//using base class header file


using namespace std;

//devired class inherite from base class

class Book : public LibraryItem
{
public:
	Book(string type, int id, string title, int year, string autor, int numberOfPage) : LibraryItem(type, id, title, year), mAutor(autor), mNumberofPage(numberOfPage) {}//constructor
	~Book() {}//destructor
	void print() const override;
private:
	//this book class own data type
	string mAutor;
	int mNumberofPage;
};

//override the method
void Book::print() const {
	LibraryItem::print();
	cout << "Autor: " << mAutor << endl;
	cout << "Number of pages: " << mNumberofPage << endl;
	cout << " " << endl;
}

