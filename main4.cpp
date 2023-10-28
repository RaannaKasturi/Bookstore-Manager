#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>
#include <fstream>

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

class customerDetails // parent
{
    private:
        string fname, lname, name;
        string num;

    public :
        string cname() {
            regex pattern("^[a-zA-Z ]+$");
            bool valid = false;
            while (!valid) {
                cout << "Enter name: ";
                cin >> fname >> lname;
                name = fname + " " + lname;
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
    
        string cnum() {
            regex pattern("(0|91)?[6-9][0-9]{9}");
            bool valid = false;
            while (!valid) {
                cout << "Enter phone number: ";
                cin >> num;
                if (regex_match(num, pattern)) {
                    valid = true;
                }
                else {
                    cout << "Invalid phone number. Please enter a valid phone number: " << endl;
                }
            }
            cout << "Number entered: " << num << endl;
            return num;
        }
};

class orderCalc : public customerDetails {
    private:
        int total_price;
    public :
        int addBook()
        {
            string purchased[10][4]; // Define a fixed-size array to store purchased books

            bool flag = true;
            int i = 0, total_price = 0;

            cout << "Enter 0 to exit the program" << endl;
            cout << "Enter book ID : ";

            while (flag)
            {
                int bookID;
                cin >> bookID;

                if (bookID == 0)
                {
                    flag = false;
                    break;
                    // Exit the loop and proceed to print the Final List of Books purchased
                }
                else if (bookID >= 1 && bookID <= 10 && i <= 10) // Check if i is within array bounds
                {
                    purchased[i][0] = to_string(bookID);      // BookID
                    purchased[i][1] = books[bookID - 1][1];   // Book Name
                    purchased[i][2] = books[bookID - 1][2];   // Author Name
                    purchased[i][3] = books[bookID - 1][3];   // Book Price

                    for (int a = 0; a < 4; a++) {
                        cout << purchased[i][a] << "\t";
                    }

                    // Simultaneously calculate the total price
                    int book_price_converted = stoi(purchased[i][3]);
                    total_price += book_price_converted;
                    i++;
                }
                else
                {
                    cout << "\nInvalid Book ID. Please enter a number between 1 and 10." << endl;
                }

                cout << "\nEnter 0 to exit the program";
                cout << "\nEnter next Book ID for further purchase : ";
            }

            cout << "\nFinal List of books purchased : " << endl;// Print the purchased books
            for (int j = 0; j < i; j++)
            {
                for (int a = 0; a < 4; a++)
                {
                    cout << purchased[j][a] << "\t";
                }
                cout << endl;
            }
            cout << "------------------------------------------------" << endl;
            cout << "\nTotal Price : Rs. " << total_price << endl;
            cout << "------------------------------------------------" << endl;
            return total_price;
    }
};



int main()
{
    cout << "### BOOKSTORE MANAGEMENT PROGRAM ###" << endl;
    string custname, custnum, xyz;
    int totalPrice;
    orderCalc gd;
    custname = gd.cname();
    custnum = gd.cnum();
    totalPrice = gd.addBook();

    fstream f;
    f.open("transaction.txt", ios::app);
    if (!f)
        ofstream MyFile("transaction.txt");
    else {
        f << "\n" << custname << "\t\t\t\t" << custnum << "\t\t\t\t" << totalPrice;
        cout << "Data appended successfully\n";
        f.close();
       
    }
    /*

    cout << "------------------------------------------------" << endl;
    cout << "Customer Name:" << custname << endl;
    cout << "Customer Number:" << custnum << endl;
    cout << "Customer Bill:" << totalPrice << endl;
    cout << "------------------------------------------------" << endl;
    */
   
    return 0;
    getch();
}
