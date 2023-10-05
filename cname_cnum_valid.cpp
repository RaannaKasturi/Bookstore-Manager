#include <iostream>
#include <regex>
#include <string>

using namespace std;

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

int main() {
    cout << "Customer's Name: " << cname() <<endl;
    cout << "Customer's Contact: " << cnum() << endl;
    return 1;
}