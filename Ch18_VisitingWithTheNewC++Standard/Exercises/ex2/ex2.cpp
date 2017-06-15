// ex2.cpp -- Chapter 18 ex2 - using the Cpmv class
#include <iostream>
#include "cpmv.h"


const Cpmv copy_left(const Cpmv& l, const Cpmv& r)
{
    return l;
}

Cpmv add(const Cpmv& a, const Cpmv& b)
{
    return a + b;
}


int main()
{
    Cpmv c1;
    Cpmv c2("foo", "bar");
    std::cout << "c2:\n";
    c2.Display();
    Cpmv c3("bar", "foo");
    std::cout << "c3:\n";
    c3.Display();
    Cpmv c4(c2);
    std::cout << "c4:\n";
    c4.Display();
    Cpmv c5(c4 + c3);
    std::cout << "c5:\n";
    c5.Display();
    c1 = c5;
    std::cout << "c1:\n";
    c1.Display();
    Cpmv c6 = c1 + c5;
    std::cout << "c6:\n";
    c6.Display();

    return 0;
}
