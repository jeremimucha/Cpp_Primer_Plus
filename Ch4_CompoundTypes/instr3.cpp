// instr3.cpp -- reading more than one work with get() & get()
#include <iostream>


int main()
{
    using namespace std;

    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name: ";
    cin.get(name, ArSize).get();  // reads through newline
    cout << "Enter your favorite dessert: ";
    cin.get(dessert, ArSize).get();
    cout << "I have some delicious " << dessert
         << " for you, " << name << ".\n";
}
