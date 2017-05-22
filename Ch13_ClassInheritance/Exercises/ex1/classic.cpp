// classic.cpp -- implementation code for classic.h
#include "classic.h"
#include <iostream>


void Cd::Report() const
{
    std::cout << "Performers: " << performers <<'\n'
              << "Label: " << label << '\n'
              << "Selections: " << selections << '\n'
              << "Playtime: " << playtime
              << std::endl;
}

void Classic::Report() const
{
    Cd::Report();
    std::cout << "Primary: " << primary
              << std::endl;
}
