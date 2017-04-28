// numstr.cpp -- following number input with line input
#include <iostream>

#define CLEARLINE(is)   while((is).get() != '\n')


int main()
{
    using namespace std;

    cout << "What year was your house built?\n";
    int year;
    cin >> year;
    CLEARLINE(cin);
    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";

    return 0;
}
