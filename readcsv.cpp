#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string row;
  ifstream bData ("bData.csv");
  if (bData.is_open())
  {
    cout << "Enter the ID you want to search for: ";
    int selectedID;
    cin >> selectedID;
    bool found = false;

    while ( getline (bData,row) )
    {
      // Assuming that the ID is in the first column of the CSV file
      size_t pos = row.find(",");
      if (pos != string::npos) {
        int id = stoi(row.substr(0, pos));
        if (id == selectedID) {
          cout << row << '\n';
          found = true;
          //break;  // If you only want to show the first matching row, remove this line to display all matching rows.
        }
      }
    }
    
    if (!found) {
      cout << "ID not found in the file." << endl;
    }

    bData.close();
  }
  else {
    cout << "Unable to open file"; 
  }

  return 0;
}
