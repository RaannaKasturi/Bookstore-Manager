#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    time_t now = time(0);
    char dt[80];
    strftime(dt, 80, "%Y%m%d%H%M", localtime(&now));
    string currentTime(dt);
    cout << "The current local date and time is: " << currentTime << endl;
    return 0;
}