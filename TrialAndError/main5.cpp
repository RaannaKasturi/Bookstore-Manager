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

class CustomerDetails {
private:
    string name;
    string num;

public:
    string cname() {
        regex pattern("^[a-zA-Z ]+$");
        bool valid = false;

        while (!valid) {
            cout << "Enter name: ";
            getline(cin, name);

            if (regex_match(name, pattern)) {
                valid = true;
            } else {
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
            } else {
                cout << "Invalid phone number. Please enter a valid phone number: " << endl;
            }
        }

        cout << "Number entered: " << num << endl;
        return num;
    }
};

class OrderCalc: public CustomerDetails {
private:
    int total_price;

public:
    int orderProcess() {
        string purchased[100][4];
        bool flag = true;
        int i = 0;
        total_price = 0;

        cout << "Enter 0 to exit the program" << endl;
        cout << "Enter book ID: ";

        while (flag) {
            int bookID;
            cin >> bookID;

            if (bookID == 0) {
                flag = false;
                break;
            } else if (bookID >= 1 && bookID <= 10 && i <= 10) {
                purchased[i][0] = to_string(bookID);
                purchased[i][1] = books[bookID - 1][1];
                purchased[i][2] = books[bookID - 1][2];
                purchased[i][3] = books[bookID - 1][3];

                for (int a = 0; a < 4; a++) {
                    cout << purchased[i][a] << "\t";
                }

                int book_price_converted = stoi(purchased[i][3]);
                total_price += book_price_converted;
                i++;
            } else {
                cout << "\nInvalid Book ID. Please enter a number between 1 and 10." << endl;
            }

            cout << "\nEnter 0 to exit the program";
            cout << "\nEnter next Book ID for further purchase: ";
        }

        cout << "\nFinal List of books purchased: " << endl;
        for (int j = 0; j < i; j++) {
            for (int a = 0; a < 4; a++) {
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

class Transactions: public OrderCalc {
public:
    string generateOrderID() {
        static int orderNumber = 1; // Static variable to keep track of order numbers
        string orderID = "ABOID_" + to_string(orderNumber);
        orderNumber++; // Increment the order number for the next order
        return orderID;
    }

    void writeTXT (string orderID, string custname, string custnum, int totalPrice){
        fstream f;
        f.open("transactions.txt", ios::app);
        if (!f) {
            ofstream MyFile("transactions.txt");
            f << orderID << "\t\t\t" << custname << "\t\t\t" << custnum << "\t\t\t" << totalPrice <<"\n";
            cout << "Bill Printed Succesfully" << endl;
            f.close();
        }
        else {
            f << orderID << "\t\t\t" << custname << "\t\t\t" << custnum << "\t\t\t" << totalPrice <<"\n";
            cout << "Bill Printed Succesfully" << endl;
            f.close();
        }
    }

    void saveTransaction(string orderID, string custname, string custnum, int totalPrice) {
        writeTXT(orderID, custname, custnum, totalPrice);
        cout << endl;
        cout << endl;
        cout << "################################################" << endl;
        cout << "                 ARK Book Store                 " << endl;
        cout << "------------------------------------------------" << endl;
        cout << endl;
        cout << "Bill No.: " << orderID << endl;
        cout << "Customer Name: " << custname << endl;
        cout << "Customer Number: " << custnum << endl;
        cout << "Customer Bill: " << totalPrice << endl;
        cout << endl;
        cout << "################################################" << endl;
        cout << endl;
        cout << endl;
    }
};

int main() {
    cout << "### BOOKSTORE MANAGEMENT PROGRAM by EB, NK & PK ###" << endl;
    string custname, custnum, orderID;
    int totalPrice;

    Transactions clt;
    custname = clt.cname();
    custnum = clt.cnum();
    totalPrice = clt.orderProcess();
    orderID = clt.generateOrderID();
    clt.saveTransaction(orderID, custname, custnum, totalPrice);

    fstream f;
    string billNo = "ABS_" + (orderID);
    ofstream MyFile(billNo);
    f.open(billNo);
    f << "################################################" << endl;
    f << "                  ARK Book Store                " << endl;
    f << "------------------------------------------------" << endl;
    f << endl;
    f << "Bill No.: " << orderID << endl;
    f << endl;
    f << "Customer Name: " << custname << endl;
    f << "Customer Number: " << custnum << endl;
    f << endl;
    f << "Total Price: " << totalPrice << endl;
    f << endl;
    f << "################################################" << endl;
    f << endl;
    f.close();
    getch();
    return 0;
}
