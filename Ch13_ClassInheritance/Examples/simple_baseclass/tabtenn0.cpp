// tabtenn0.cpp -- simple base-class methods
#include "tabtenn0.h"
#include <iostream>


void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}
