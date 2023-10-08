#include <iostream>
#include <string>
using namespace std;

void print_bill()
{
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

int main()
{
    print_bill();
    return 0;
}