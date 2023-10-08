#include <iostream>
#include <string>
using namespace std;

void print_bill()
{
    string bill[] = {"1","Prarthi","9820138387","Book1","Author1","120","3"};
    // Customer id, name, phone number, book name, price per book, quantity

    string c_id = bill[0];
    string c_name = bill[1];
    string c_contact = bill[2];
    string b_name = bill[3];
    string a_name = bill[4];
    string price = bill[5];
    string quantity = bill[6];

    cout << "***************************************";
    cout << "\nCustomer ID : " << c_id;
    cout << "\nCustomer Name : " << c_name;
    cout << "\nCustomer Contact No. : " << c_contact;
    cout << "\nBook Name : " << b_name << " by " << a_name;
    cout << "\nPrice : " << price;
    cout << "\nQuantity : " << quantity;
    cout << "\nTotal Bill : " << stoi(price) * stoi(quantity);
    cout << "\n***************************************" << endl;
}

int main()
{
    print_bill();
    return 0;
}