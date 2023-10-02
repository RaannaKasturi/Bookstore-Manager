#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream bData("bookdata.txt");
    if (bData.is_open()) {
        cout << "Enter the ID you want to search for: ";
        int selectedID;
        cin >> selectedID;
        bool found = false;
        string row;

        while (getline(bData, row)) {
            size_t pos = row.find(",");
            if (pos != string::npos) {
                int id = stoi(row.substr(0, pos));
                if (id == selectedID) {
                    string bookData = row;
                    size_t startPos = 0;
                    size_t endPos = row.find(",", startPos);
                    if (endPos == string::npos) {
                        endPos = row.length();
                    }
                    
                    string bookID = bookData.substr(startPos, endPos - startPos);
                    bookData.erase(startPos, endPos - startPos + 1);
                    
                    startPos = 0;
                    endPos = bookData.find(",", startPos);
                    string bookName = bookData.substr(startPos, endPos - startPos);
                    bookData.erase(startPos, endPos - startPos + 1);
                    
                    startPos = 0;
                    endPos = bookData.find(",", startPos);
                    string bookAuthor = bookData.substr(startPos, endPos - startPos);
                    bookData.erase(startPos, endPos - startPos + 1);
                    
                    int bookStock = stoi(bookData);

                    cout << "Book ID: " << bookID << endl;
                    cout << "Book Name: " << bookName << endl;
                    cout << "Book Author: " << bookAuthor << endl;
                    cout << "Book Stock: " << bookStock << endl;
                    
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "ID not found in the file." << endl;
        }

        bData.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}
