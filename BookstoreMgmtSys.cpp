#include <iostream> // for basic input output
#include <string> // for storing characters in 1D array and string manipulation
#include <regex> // for setting regular expression and verification of the user input
#include <fstream> // for creating, modifying and writing the files
#include <ctime> // for accessing date and time

using namespace std;

string books[][4] = { //books array
    {"1", "It Ends With Us", "(Collen Hoover)", "100"},
    {"2", "Milk and Honey", "(Rupi Kaur)", "200"},
    {"3", "Call Me by Your Name", "(Andre Aciman)", "300"},
    {"4", "Nexus Sentinels", "(Nayan Kasturi)", "400"},
    {"5", "Verity", "(Collen Hoover)", "500"},
    {"6", "That Sapphire Night", "(Swastika Jha)", "600"},
    {"7", "Sorry You're Not My Type", "(Sudeep Nagarkar)", "700"},
    {"8", "The Fault In Our Stars", "(John Green)", "800"},
    {"9", "After", "(Anna Todd)", "900"},
    {"10", "Healing Words", "(Alexandra Vasiliu)", "1000"}
};

class CustomerDetails { // stores and returns customer details
    private:
        string name;
        string num;

    public:
        string cname() { // takes customer's name and verifies it
            regex pattern("^[a-zA-Z ]+$");
            bool valid = false;

            while (!valid) {
                cout << "Enter customer's name: "; 
                cin >> ws; //removes the whitespace from previous execution of int main()
                getline(cin, name);

                if (regex_match(name, pattern)) {
                    valid = true;
                } else {
                    cout << "Invalid name. Please enter a valid customer's name." << endl;
                }
            }

            cout << "Customer's Name: " << name << endl;
            return name;
        }

        string cnum() { // takes customer's contact number and verifies it
            regex pattern("(0|91)?[6-9][0-9]{9}");
            bool valid = false;

            while (!valid) {
                cout << "Enter customer's contact number: ";
                cin >> num;

                if (regex_match(num, pattern)) {
                    valid = true;
                } else {
                    cout << "Invalid contact number. Please enter a valid customer's contact number." << endl;
                }
            }

            cout << "Customer's Contact Number: " << num << endl;
            return num;
        }
};

class OrderCalc: public CustomerDetails { // child class containing order processing function
    private:
        int total_price;

    public:
        int orderProcess(string purchased[][4], int &bookCount) { // order processing and returns the total order amount
            bool flag = true;
            total_price = 0;

            cout << "Enter 0 to exit the program" << endl;
            cout << "Enter book ID: ";

            while (flag) {
                int bookID;
                cin >> bookID;

                if (bookID == 0) {
                    flag = false;
                    break;
                } else if (bookID >= 1 && bookID <= 10 && bookCount < 100) {
                    purchased[bookCount][0] = to_string(bookID);
                    purchased[bookCount][1] = books[bookID - 1][1];
                    purchased[bookCount][2] = books[bookID - 1][2];
                    purchased[bookCount][3] = books[bookID - 1][3];

                    for (int a = 0; a < 4; a++) {
                        cout << purchased[bookCount][a] << "\t";
                    }

                    int book_price_converted = stoi(purchased[bookCount][3]);
                    total_price += book_price_converted;
                    bookCount++;
                } else {
                    cout << "\nInvalid Book ID. Please enter a number between 1 and 10." << endl;
                }

                cout << "\nEnter 0 to exit the program";
                cout << "\nEnter next Book ID for further purchase: ";
            }

            cout << "\nFinal List of books purchased: " << endl;
            for (int j = 0; j < bookCount; j++) {
                for (int a = 0; a < 4; a++) {
                    cout << purchased[j][a] << "\t";
                }
                cout << endl;
            }

            cout << "------------------------------------------------" << endl;
            cout << "                 Total Price :  ₹" << total_price << endl;
            cout << "------------------------------------------------" << endl;

            return total_price;
        }
};

class Transactions: public OrderCalc { // child class storing transaction history and creating bills and files
    public:
        string generateOrderID() { // generates serial - wise order IDs
            static int orderNumber = 1; // Static variable to keep track of order numbers
            string orderID = "ABOID_" + to_string(orderNumber);
            orderNumber++; 
            return orderID;
        }

        void writeTXT (string orderID, string custname, string custnum, int totalPrice){ // creates and writes the transaction in .txt file
            fstream f;
            f.open("transactions.txt", ios::app);
            if (!f) {
                ofstream MyFile("transactions.txt");
                f << orderID << "\t\t\t" << custname << "\t\t\t" << custnum << "\t\t\t₹" << totalPrice <<"\n";
                cout << "Bill Printed Successfully" << endl;
                f.close();
            }
            else {
                f << orderID << "\t\t\t" << custname << "\t\t\t" << custnum << "\t\t\t₹" << totalPrice <<"\n";
                cout << "Bill Printed Successfully" << endl;
                f.close();
            }
        }

        void saveTransaction(string orderID, string custname, string custnum, int totalPrice, string purchased[][4], int bookCount) { // creates a formatted bill in console
            writeTXT(orderID, custname, custnum, totalPrice);
            cout << endl;
            cout << "################################################" << endl;
            cout << "                 ARK Book Store                 " << endl;
            cout << "------------------------------------------------" << endl;
            cout << endl;
            cout << "Bill No.: " << orderID << endl;
            cout << "Customer Name: " << custname << endl;
            cout << "Customer Number: " << custnum << endl;
            cout << endl;
            cout << "------------------------------------------------" << endl;
            cout << "                Purchased Books                 " << endl;
            cout << "------------------------------------------------" << endl;
            cout << endl;
            for (int i = 0; i < bookCount; i++) {
                for (int a = 0; a < 4; a++) {
                    cout << purchased[i][a] << "\t";
                }
                cout << endl;
            }
            cout << endl;
            cout << "------------------------------------------------" << endl;
            cout << "                          Total: ₹" << totalPrice << endl;
            cout << "################################################" << endl;
            cout << endl;
        }

        void printBill(string custname, string custnum, string orderID, string purchased[100][4], int totalPrice, int bookCount){
            // creates a formatted bill in .txt file
            fstream f;
            string billNo = orderID + ".txt";
            ofstream MyFile(billNo);
            f.open(billNo);
            f << endl;
            f << "################################################" << endl;
            f << "                 ARK Book Store                 " << endl;
            f << "------------------------------------------------" << endl;
            f << endl;
            f << "Bill No.: " << orderID << endl;
            f << "Customer Name: " << custname << endl;
            f << "Customer Number: " << custnum << endl;
            f << endl;
            f << "------------------------------------------------" << endl;
            f << "                Purchased Books                 " << endl;
            f << "------------------------------------------------" << endl;
            f << endl;
            for (int i = 0; i < bookCount; i++) {
                for (int a = 0; a < 4; a++) {
                    f << purchased[i][a] << "\t\t";
                }
                f << endl;
            }
            f << endl;
            f << "------------------------------------------------" << endl;
            f << "                           Total: ₹"<< totalPrice << endl;
            f << "################################################" << endl;
            f << endl;
            f.close();
        }
};

int main() {

    while (true) { // loop - ensures continuous program execution
        string custname, custnum, orderID;
        string purchased[100][4];
        int totalPrice, bookCount = 0;

        Transactions clt;
        cout << "### BOOKSTORE MANAGEMENT SYSTEM by EB, NK & PK ###" << endl;

        custname = clt.cname(); // takes in customer's name and verifies it
        custnum = clt.cnum(); // takes in customer's contact number and verifies it
        totalPrice = clt.orderProcess(purchased, bookCount); // takes in book IDs and returns the calculated total price
        orderID = clt.generateOrderID(); // generates sequential order IDs
        clt.saveTransaction(orderID, custname, custnum, totalPrice, purchased, bookCount); // prints the formatted bill in console
        clt.printBill(custname, custnum, orderID, purchased, totalPrice, bookCount); // creates .txt file w.r.t. bill number and writes formatted bill in it

        cout << "Enter 0 to terminate program or any other key to continue: ";
        string choice;
        cin >> choice;
        if (choice == "0") {
            cout << endl;
            break; // Exits the loop and interrupts the program execution, if the user enters 0
        }
        else{
            cout << endl;
            continue;
        }
    }
    return 0;
}
