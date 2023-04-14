#pragma once
#include <iostream>
#include <string>
#include "LibraryItem.h"//using base class header file

using namespace std;

//devired class inherite from base class

class Journal : public LibraryItem
{
public:
	Journal(string type, int id, string title, int year, int volume, int number) : LibraryItem(type, id, title, year), mVolume(volume), mNumber(number) {}//constructor
	~Journal() {}//destructor
	void print() const override;
private:
	//this journal class own data type
	int mVolume;
	int mNumber;
};

//override the method
void Journal::print() const {
	LibraryItem::print();
	cout << "Volume: " << mVolume << endl;
	cout << "Number: " << mNumber << endl;
	cout << " " << endl;
}

