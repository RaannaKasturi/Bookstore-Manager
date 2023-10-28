#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>
#include <sstream>

using namespace std;

string books[][4] = { //books array
    {"1", "Book 1", "Author 1", "100"},
    {"2", "Book 2", "Author 3", "200"},
    {"3", "Book 3", "Author 1", "300"},
    {"4", "Book 4", "Author 3", "400"},
    {"5", "Book 5", "Author 2", "500"},
    {"6", "Book 6", "Author 4", "600"},
    {"7", "Book 7", "Author 3", "700"},
    {"8", "Book 8", "Author 1", "800"},
    {"9", "Book 9", "Author 5", "900"},
    {"10", "Book 10", "Author 2", "1000"}
};


string cnum() 
{

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


string cname() 
{
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


void getBookOrder()
{
    string purchased[][4] = {
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""}
    };

    bool flag = true;
    int i = 0, j, a, total_price = 0;
    int book_price_converted;
    stringstream ss;

    cout<<"Enter 0 to exit the program"<<endl;
    cout<<"Enter book ID : ";

    while(flag)
    {
        int bookID;
        cin >> bookID;

        if(bookID == 0)
        {
            flag = false;
            break;
            //exit the loop and proceed to print Final List of Books purchased
        }

        if(bookID>=1 && bookID <=10)
        {
            purchased[i][0] = bookID; //bookID
            purchased[i][1] = books[bookID-1][1]; //Book Name
            purchased[i][2] = books[bookID-1][2]; //Author Name
            purchased[i][3] = books[bookID-1][3]; //Book Price

            //just to check what data is getting stored in the purchased array
            cout<<"\n"<<purchased[i][0] << endl;
            cout<<purchased[i][1] << endl;
            cout<<purchased[i][2] << endl;
            cout<<purchased[i][3] << endl;

            // simultaneously calculating the total price

            ss << purchased[i][3];
            cout << "\nvalue of i before - " << i << endl;
            i++;
            ss >> book_price_converted;
            total_price += book_price_converted;
            cout << "\nUpdated price - : "<< total_price;
            cout<< "\nvalue of i after - " << i << endl;
            cout << endl;
            
        }

        else
        {
            cout<<"\nInvalid Book ID. Please enter a number between 1 and 10. "<<endl;
        }

        cout<<"\nEnter 0 to exit the program";
        cout<<"\nEnter next Book ID for further purchase : ";

    }

    cout<<"\nFinal List of books purchased : " <<endl;


    //using nested for loop for accessing record of each book purchased

    for(j=0;j<=i;j++) // used 'j' for accessing the whole row of that book record in that array
    {
        for(a=0;a<4;a++) // used 'a' for accessing the book id, book name, author name and price for the record 'j'
        {
            cout << purchased[j][a];
            cout << "\t";
        }

        cout << endl;

        //both the for loops will go in print bill part
        //will make a class and put purchased array in it as public: 
        //and then access the array with the object

        //used j<=i since final value of i = index of last book
        //example - total books purchased = 3
        //hence index number of last element in array = 3 - 1 = 2 
        //and final value of i after the loop ends is also 2 in this example

    }

    cout<<"\nTotal Price : Rs. " << total_price << endl;
}

int main()
{
    cname();
    cnum();
    getBookOrder();

    return 0;

    /*

    int BookID;
    cout << "Enter 0 to exit the Program!" << "\nEnter Book ID: ";
    cin >> BookID;
    int arrayIndex = BookID - 1;
    string bookID = books[arrayIndex][0];
    string bookName = books[arrayIndex][1];
    string bookAuthor = books[arrayIndex][2];
    string bookPrice = books[arrayIndex][3];


    if (BookID == 0) { //exiting the loop and the program
        cout << "Exiting the program." << endl;
    }

    if (BookID >= 1 && BookID <= 10) { //ranging the array search from 1 to 10


        cout << "Book Details:" << endl; //displaying book details
        cout << "Book ID: " << bookID << endl;
        cout << "Book Name: " << bookName << endl;
        cout << "Book Author: " << bookAuthor << endl;
        cout << "Book Price: ₹" << bookPrice << endl;
    }
    else {
        cout << "Invalid Book ID. Please enter a number between 1 and 10." << endl;
    }
    */

    //cout << "Book Details: " << bookName << " - " << bookAuthor << " [" << bookPrice << "] ";

}
