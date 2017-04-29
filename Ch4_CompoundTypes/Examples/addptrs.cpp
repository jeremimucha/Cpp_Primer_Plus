// addptrs.cpp -- pointer addition
#include <iostream>


int main()
{
    using namespace std;

    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3,2,1};

    // Here are tow ways to get the address of an array
    double* pw = wages;         // name of an array == address
    short* ps = &stacks[0];     // or use address operator with array elem

    cout << "pw = " << pw <<", *pw = " << *pw
         << endl;
    ++pw;
    cout << "add 1 to the pw pointer:\n"
         << "pw = " << pw << ", *pw = " << *pw << "\n\n"
         << "ps = " << ps << ", *ps = " << *ps
         << endl;
    ++ps;
    cout << "add 1 to the ps pointer:\n"
         << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "access to elements with array notation\n"
         << "stacks[0] = " << stacks[0]
         << ", stacks[1] = " << stacks[1]
         << endl;

    cout << "access two elements with pointer notation\n"
         << "*stacks = " << *stacks
         << ", *(stacks + 1) = " << *(stacks + 1)
         << endl;

    cout << "sizeof(wages) = " << sizeof(wages) << '\n'
         << "sizeof(pw) = " << sizeof(pw)
         << endl;

    return 0;
}
