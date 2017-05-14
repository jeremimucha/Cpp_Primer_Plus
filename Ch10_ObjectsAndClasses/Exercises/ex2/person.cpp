// person.cpp -- chapter 10 pe2 - implementation code
#include "person.h"
#include <iostream>


void Person::Show() const
{
    std::cout << fname << ' ' << lname;
}

void Person::FormalShow() const
{
    std::cout << lname << ", " << fname;
}
