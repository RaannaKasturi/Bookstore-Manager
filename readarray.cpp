#include <iostream>
#include <string>

using namespace std;

struct Book {
    int id;
    string name;
    string author;
    int price;
};

Book books[] = {
    {1, "Book 1", "Author 1", 52},
    {2, "Book 2", "Author 3", 65},
    {3, "Book 3", "Author 1", 35},
    {4, "Book 4", "Author 3", 33},
    {5, "Book 5", "Author 2", 58},
    {6, "Book 6", "Author 4", 45},
    {7, "Book 7", "Author 3", 55},
    {8, "Book 8", "Author 1", 12},
    {9, "Book 9", "Author 5", 9},
    {10, "Book 10", "Author 2", 24}
};

int main() {
    int BookID;
    bool found;

    while (true) { // Run the program in an infinite loop
        found = false; // Reset the found flag for each iteration

        cout << "Enter Book ID (or enter 0 to exit): ";
        cin >> BookID;

        if (BookID == 0) {
            cout << "Exiting the program." << endl;
            break; // Exit the loop and the program if the user enters 0
        }

        for (const Book &book : books) {
            if (book.id == BookID) {
                found = true;
                cout << "Book Details:" << endl;
                cout << "Book ID: " << book.id << endl;
                cout << "Book Name: " << book.name << endl;
                cout << "Book Author: " << book.author << endl;
                cout << "Book Price: ₹" << book.price << endl;
                break; // Exit the loop once a matching book is found
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    return 0;
}
