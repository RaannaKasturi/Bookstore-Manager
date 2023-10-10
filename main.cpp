#include <iostream>
#include <conio.h>
#include <string>
#include <regex>

using namespace std;

string books[][4] = { //books array
    {"1", "Book 1", "Author 1", "52"},
    {"2", "Book 2", "Author 3", "65"},
    {"3", "Book 3", "Author 1", "35"},
    {"4", "Book 4", "Author 3", "33"},
    {"5", "Book 5", "Author 2", "58"},
    {"6", "Book 6", "Author 4", "45"},
    {"7", "Book 7", "Author 3", "55"},
    {"8", "Book 8", "Author 1", "12"},
    {"9", "Book 9", "Author 5", "9"},
    {"10", "Book 10", "Author 2", "24"}
};

void searchBook(){ //searchbook function
    while (true) { //take user input for BookID
        cout << "Enter 0 to exit the Program!" << endl;
        cout << "Enter Book ID: ";
        int BookID;
        cin >> BookID;

        if (BookID == 0) { //exiting the loop and the program
            cout << "Exiting the program." << endl;
            break; 
        }
        
        if (BookID >= 1 && BookID <= 10) { //ranging the array search from 1 to 10
            int arrayIndex = BookID - 1;

            string bookID, bookName, bookAuthor, bookPrice;
            bookID = books[arrayIndex][0];
            bookName = books[arrayIndex][1];
            bookAuthor = books[arrayIndex][2];
            bookPrice = books[arrayIndex][3];

            
            cout << "Book Details:" << endl; //displaying book details
            cout << "Book ID: " << bookID << endl;
            cout << "Book Name: " << bookName << endl;
            cout << "Book Author: " << bookAuthor << endl;
            cout << "Book Price: ₹" << bookPrice << endl;
        } 
        else {
            cout << "Invalid Book ID. Please enter a number between 1 and 10." << endl;
        }
    }
}

string cnum() {
    string cnum;
    regex pattern("(0|91)?[6-9][0-9]{9}");
    bool valid = false;
    while (!valid) {
        cout << "Enter phone number: ";
        cin >> cnum;
        if (regex_match(cnum, pattern)) {
            valid = true;
        }
        else {
            cout << "Invalid phone number. Please enter a valid phone number: " << endl;
        }
    }
    return cnum;
}

string cname() {
    string name;
    regex pattern("^[a-zA-Z ]+$");
    bool valid = false;
    while (!valid) {
        cout << "Enter name: ";
        cin >> name;
        if (regex_match(name, pattern)) {
            valid = true;
        }
        else {
            cout << "Invalid name. Please enter a valid name." << endl;
        }
    }
    cout << "Name entered: " << name << endl;
    return name;
}

void print_bill() {
    string bill[] = {"1","Prarthi","9820138387","Book1","Author1","120","3"};
    // Customer id, name, phone number, book name, price per book, quantity

    string cid = bill[0];
    string cname = bill[1];
    string ccontact = bill[2];
    string bname = bill[3];
    string bauthor = bill[4];
    string bprice = bill[5];
    string bquantity = bill[6];

    cout << "***************************************";
    cout << "\nCustomer ID : " << cid;
    cout << "\nCustomer Name : " << cname;
    cout << "\nCustomer Contact No. : " << ccontact;
    cout << "\nBook Name : " << bname << " by " << bauthor;
    cout << "\nPrice : " << bprice;
    cout << "\nQuantity : " << bquantity;
    cout << "\nTotal Bill : " << stoi(bprice) * stoi(bquantity);
    cout << "\n***************************************" << endl;
}

