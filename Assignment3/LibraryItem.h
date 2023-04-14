#pragma once
#include <iostream>
#include <string>

using namespace std;

//Base class
class LibraryItem
{
public:
    LibraryItem(string type, int id, string title, int year): mType(type), mId(id), mTitle(title), mYear(year){}//constructor
    virtual ~LibraryItem() {};//destructor, also declare this class is abstract class
    virtual void print() const;
    string getTitle();
protected:
    //data field
    string mType;
    int mId;
    string mTitle;
    int mYear;
};

//method for overriding
void LibraryItem::print() const {
    cout << "--------------------------------------" << endl;
    cout << "Type: " << mType << endl;
    cout << "Title: " << mTitle << endl;
    cout << "ID: " << mId << endl;
    cout << "Year: " << mYear << endl;
}

//method to get library item's title
string LibraryItem::getTitle() {
    return mTitle;
}
