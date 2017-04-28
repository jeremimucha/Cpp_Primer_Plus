// hexoct1.cpp -- shows hex and oct literals
#include <iostream>


int main()
{
    using namespace std;

    int chest = 42;
    int waist = 0x42;
    int inseam = 042;

    cout << "Monsieur cuts a striking figure!\n"
         << "chest = " << chest << " (42 in decimal)\n"
         << "waist = " << waist << " (0x42 in hex)\n"
         << "inseam = " << inseam << " (042 in octal)\n";

    return 0;
}
