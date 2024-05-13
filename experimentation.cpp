#include <iostream>
#include <ctime>
using namespace std;
int main() {

    /* GETTING THE CURRENT TIMESTAMP USING CTIME*/

    // Get the current time in seconds since epoch
    time_t currentTime = time(nullptr);
    
    // Convert the time to a local time struct
    tm* localTime = localtime(&currentTime);
    
    // Output the date and time
    cout << "Current date and time: ";
    // Output the year
    cout << 1900 + localTime->tm_year << "-";
    // Output the month
    cout << 1 + localTime->tm_mon << "-";
    // Output the day
    cout << localTime->tm_mday << " ";
    // Output the hour
    cout << localTime->tm_hour << ":";
    // Output the minute
    cout << localTime->tm_min << ":";
    // Output the second
    cout << localTime->tm_sec << std::endl;

    return 0;
}
