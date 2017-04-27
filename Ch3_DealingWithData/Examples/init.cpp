// init.cpp -- type changes on initialization
#include <iostream>


int main()
{
    using namespace std;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;         // int converted to float;
    int guess(3.9832);      // double converted to int
    int debt = 7.2e12;      // result not defined in C++
    cout << "tree = " << tree
         << "\nguess = " << guess
         << "\ndebt = " << debt
         << endl;

    return 0;
}
