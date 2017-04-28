// instr2.cpp -- reading more than one work with getline
#include <iostream>


int main()
{
    using namespace std;

    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name: ";
    cin.getline(name, ArSize);  // reads through newline
    cout << "Enter your favorite dessert: ";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert
         << " for you, " << name << ".\n";

    return 0;
}
