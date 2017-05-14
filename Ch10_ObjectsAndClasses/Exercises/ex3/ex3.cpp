// ex3.cpp -- chapter 10 pe3 - use Golf class
#include <iostream>
#include "Golf.h"


int main()
{
    Golf one;       // init to 0
    Golf two{true}; // interactive

    one.set_handicap(42);
    one.show();
    std::cout << '\n';
    two.show();

    return 0;
}
