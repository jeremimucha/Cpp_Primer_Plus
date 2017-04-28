// hexoct2.cpp -- display values in hex and octal
#include <iostream>

using namespace std;


int main()
{
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monsieur cuts a striking figure!\n"
         << "chest = " << chest << " (decimal for 42)\n"
         << hex << "waist = " << waist << " (hexadecimal for 42)\n"
         << oct << "inseam = " << inseam << " (octal for 42)"
         << endl;

    return 0;
}
