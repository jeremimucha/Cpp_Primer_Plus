// barn.cpp -- chapter 12 pe1 -- code using Cow class
#include <iostream>
#include "cow.h"
using std::cout; using std::endl;


void usecowr(const Cow& c)
{
    cout << "call by reference function, ";
    c.ShowCow();
    cout << endl;
}

void usecow(Cow c)
{
    cout << "call by value function, ";
    c.ShowCow();
    cout << endl;
}


int main()
{
    Cow c1;                             // default constructor
    Cow c2("Foo", "Grasing", 1234);     // three-argument constructor
    c1 = c2;                            // copy assignment
    cout << "After c1 = c2:\n";
    cout << "c1: "; c1.ShowCow();
    cout << "\nc2: "; c2.ShowCow();
    cout << endl;
    c1 = Cow("Bar", "Baring", 2345);// copy assignment;
    cout << "\nAfter copy assignment, c1: ";
    c1.ShowCow();
    cout<<endl;
    Cow c3(c1);                         // copy constructor
    cout << "After copy constructor, c3: ";
    c3.ShowCow();
    cout << endl;
    usecowr(c1);
    usecowr(c2);
    usecow(c2);
    cout << endl;

    return 0;
}
