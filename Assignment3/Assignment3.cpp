//Yuekai Wu 13113181

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include "LibraryItem.h"
#include "Book.h"
#include "Journal.h"
#include "Movie.h"

using namespace std;

int m = 0;
LibraryItem* libraryItem[100];//declare 100 library item object
vector<string> idList;//declare vertor to store the library items' id

void displayInfo();
void search();
void searchID(string s, vector<string>::iterator it);
void searchPhraseInTitle(string s);

void displayInfo() {//the information of student who contributed to the solution
    cout << "--------------------------------------" << endl;
    cout << "    Assignment 3 Semester 1 2020      " << endl;
    cout << "  Submitted by: Yuekai, Wu 13113181   " << endl;
    cout << "--------------------------------------" << endl;
}

//search function use to choose the way for searching
void search() {
    cout << "--------------------------------------" << endl;
    cout << "Enter 'q' to quit, enter 'i' to search by ID, or enter any other to search by phrase in title" << endl;
    string userInput;
    cin >> userInput;
    if (userInput == "i"){//user enter 'i' to search item by id
        cout << "Enter ID to start search, or enter 'b' to go back to choose search method" << endl;
        string userInputID;
        cin >> userInputID;
        searchID(userInputID, idList.begin());
    }
    else if (userInput == "q") {//user enter 'q' to quit the application
        cout << "Program quit." << endl;
        exit(0);
    }
    else {//user enter other key or word to search item by phrase in title
        cout << "Enter phrase in title to start search, or enter 'b' to go back to choose search method" << endl;
        string userInputTitle;
        cin >> userInputTitle;
        searchPhraseInTitle(userInputTitle);
    }
}

//searchID function use to search item by entered id
void searchID(string s, vector<string>::iterator it) {
    string userInputID;
    if (s != "b") {
        while (it != idList.end()) {
            if (s == *it) {
                break;
            }
            it++;
        }
        for (int i = 0;i < m; i++) {
            if (*it == idList.at(i)) {
                libraryItem[i]->print();
                cout << "--------------------------------------" << endl;
                cout << "Enter ID to start search, or enter 'b' to go back to choose search method" << endl;
                cin >> userInputID;
                if (userInputID == "b") {
                    search();
                }
                else {
                    searchID(userInputID, idList.begin());
                }
                return;
            }
            
        }
        cout << "There is no item with ID " << s << endl;
    }
    search();
    
}

//searchPhraseInTitle function use to search item by phrase in title
void searchPhraseInTitle(string s) {
    string userInputTitle;
    if (s != "b") {
        int check = 0;
        for (int i = 0;i < m; i++) {
            stringstream titleLine(libraryItem[i]->getTitle());
            string token;
            string nameString[10];
            int j = 0;
            while (getline(titleLine, token, ' ') && j < 10) {
                nameString[j] = token;
                j++;
            }
            for (int k = 0; k < 10; k++){
                if (s == nameString[k]) {
                    libraryItem[i]->print();
                    check++;
                }
            }
        }
        if (check != 0) {
            cout << "--------------------------------------" << endl;
            cout << "Enter phrase in title to start search, or enter 'b' to go back to choose search method" << endl;
            cin >> userInputTitle;
            if (userInputTitle == "b") {
                search();
            }
            else {
                searchPhraseInTitle(userInputTitle);
            }
            return;
        }
        else {
            cout << "There is no item with phrase " << s << endl;
        }
    }
    search();
}


int main()
{
    displayInfo();
    ifstream file;
    file.open("library.txt");//open file
    if (file.is_open() == false) {//check if the file is exist
        cout << "File is not exist." << endl;
        exit(0);
    }
    
    string fileLine;
    string token;
    while (!file.eof()) {
        getline(file, fileLine);
        stringstream line(fileLine);
        if (file.eof()) break;
        if (fileLine[0] == 'M'){
            string movieString[5];
            int i = 0;
            while (getline(line, token, ',') && i < 5) {
                movieString[i] = token;
                i++;
            }
            libraryItem[m] = new Movie(movieString[0], atoi(movieString[1].c_str()), movieString[2], atoi(movieString[3].c_str()), movieString[4]);
            idList.push_back(movieString[1]);
            m++;
        }
        else if (fileLine[0] == 'B') {
            string bookString[6];
            int i = 0;
            while (getline(line, token, ',') && i < 6) {
                bookString[i] = token;
                i++;
            }
            libraryItem[m] = new Book(bookString[0], atoi(bookString[1].c_str()), bookString[2], atoi(bookString[3].c_str()), bookString[4], atoi(bookString[5].c_str()));
            idList.push_back(bookString[1]);
            m++;
        }
        else if (fileLine[0] == 'J') {
            string journalString[6];
            int i = 0;
            while (getline(line, token, ',') && i < 6) {
                journalString[i] = token;
                i++;
            }
            libraryItem[m] = new Journal(journalString[0], atoi(journalString[1].c_str()), journalString[2], atoi(journalString[3].c_str()), atoi(journalString[4].c_str()), atoi(journalString[5].c_str()) );
            idList.push_back(journalString[1]);
            m++;
        }
    }

    for (int i = 0; i < m; i++) {
        libraryItem[i]->print();//print all items' information
        //delete libraryItem[i];//destructor
    }

    search();//start search
}




