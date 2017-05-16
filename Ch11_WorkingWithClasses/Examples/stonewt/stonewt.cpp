// stonewt.cpp -- Stonewt implementation
#include <iostream>
#include "stonewt.h"
using std::cout;


void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

// conversion functions
Stonewt::operator int() const
{
    // round to nearest integer
    return int(pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}
