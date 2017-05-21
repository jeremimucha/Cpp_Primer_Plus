// tabtenn1.cpp -- simple base-class methods
#include "tabtenn1.h"
#include <iostream>


void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}


// all RatedPlayer methdos implemented inline in the header
