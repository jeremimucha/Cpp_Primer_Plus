// textin4.cpp -- reading chars with cin.get()
#include <iostream>


int main()
{
    using namespace std;
    int ch;     // int for the EOF test
    int count = 0;

    cout << "Enter some chars:\n";
    while( (ch = cin.get()) != EOF ){
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << " characters read\n";

    return 0;
}