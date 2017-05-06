// firstref.cpp -- defining and using a reference
#include <iostream>


int main()
{
    using namespace std;
    int rats = 101;
    int& rodents = rats;    // rodents is a reference

    cout << "rats = "  << rats
         << ", rodents = " << rodents
         << endl;
    ++rodents;
    cout << "rats = " << rats
         << ", rodents = " << rodents
         << endl;

    cout << "rats address = " << &rats
         << ", rodents address = " << &rodents
         << endl;

    return 0;
}
