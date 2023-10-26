#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Book {
public:
    string bookID;
    string bookName;
    string authorName;
    int bookPrice;

    Book() {}
    Book(const string& id, const string& name, const string& author, int price) {
        bookID = id;
        bookName = name;
        authorName = author;
        bookPrice = price;
    }
};

class Customer {
public:
    string name;
    string phoneNumber;

    Customer() {}
    Customer(const string& n, const string& num) {
        name = n;
        phoneNumber = num;
    }
};

class Bookstore {
private:
    Book books[10];
    int numBooks;
    Customer customer;
    int total_price;

public:
    Bookstore() {
        initializeBooks();
        numBooks = 10;
        total_price = 0;
    }

    void initializeBooks() {
        books[0] = Book("1", "Book 1", "Author 1", 100);
        books[1] = Book("2", "Book 2", "Author 3", 200);
        books[2] = Book("3", "Book 3", "Author 1", 300);
        books[3] = Book("4", "Book 4", "Author 3", 400);
        books[4] = Book("5", "Book 5", "Author 2", 500);
        books[5] = Book("6", "Book 6", "Author 4", 600);
        books[6] = Book("7", "Book 7", "Author 3", 700);
        books[7] = Book("8", "Book 8", "Author 1", 800);
        books[8] = Book("9", "Book 9", "Author 5", 900);
        books[9] = Book("10", "Book 10", "Author 2", 1000);
    }

    void displayBooks() {
        cout << "Available Books:\n";
        cout << "Book ID\tBook Name\tAuthor\tPrice" << endl;
        for (int i = 0; i < numBooks; i++) {
            cout << books[i].bookID << "\t" << books[i].bookName << "\t" << books[i].authorName << "\t" << books[i].bookPrice << endl;
        }
    }

    void getCustomerDetails() {
        cout << "Enter customer name: ";
        cin >> customer.name;
        cout << "Enter customer phone number: ";
        cin >> customer.phoneNumber;
    }

    void getBookOrder() {
        int bookID;
        cout << "Enter 0 to exit the program" << endl;
        cout << "Enter book ID: ";
        cin >> bookID;

        while (bookID != 0) {
            if (bookID >= 1 && bookID <= numBooks) {
                total_price += books[bookID - 1].bookPrice;
                cout << "Added " << books[bookID - 1].bookName << " to your order." << endl;
            } else {
                cout << "Invalid Book ID. Please enter a valid number between 1 and " << numBooks << "." << endl;
            }

            cout << "Enter 0 to exit the program" << endl;
            cout << "Enter next Book ID for further purchase: ";
            cin >> bookID;
        }
    }

    void displayOrder() {
        cout << "Final List of books purchased:\n";
        cout << "Book ID\tBook Name\tAuthor\tPrice" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Total Price: Rs. " << total_price << endl;
        cout << "------------------------------------------------" << endl;
    }
};

int main() {
    cout << "### BOOKSTORE MANAGEMENT PROGRAM ###" << endl;

    Bookstore bookstore;
    bookstore.displayBooks();
    bookstore.getCustomerDetails();
    bookstore.getBookOrder();
    bookstore.displayOrder();

    return 0;
}
