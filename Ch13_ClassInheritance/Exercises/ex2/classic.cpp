// classic.cpp -- chapter 13 ex2
#include <iostream>
#include <cstring>
#include "classic.h"


// Cd implementation

void Cd::Report() const
{
    std::cout << "Performers: " << performers << '\n'
              << "Label: " << label << '\n'
              << "Selections: " << selections << '\n'
              << "Playtime: " << playtime
              << std::endl;
}

Cd& Cd::operator=(const Cd& d)
{
    if( this == &d )
        return *this;
    delete[] performers;
    delete[] label;
    performers = new char[std::strlen(d.performers) + 1];
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    std::cout << "--> Cd::operator=(const Cd&)\n";

    return *this;
}


// Classic implementation

void Classic::Report() const
{
    Cd::Report();
    std::cout << "Primary: " << primary
              << std::endl;
}

Classic& Classic::operator=(const Classic& c)
{
    if( this == &c )
        return *this;

    Cd::operator=(c);    // handle the base class part
    delete[] primary;
    primary = new char[std::strlen(c.primary) + 1];
    std::strcpy(primary, c.primary);

    std::cout << "--> Classic::operator=(const Classic&)\n";

    return *this;
}
