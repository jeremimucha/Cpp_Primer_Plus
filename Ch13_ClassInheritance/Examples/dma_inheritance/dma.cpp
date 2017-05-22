// dma.cpp -- dma class methods
#include "dma.h"
#include <cstring>


// baseDMA methods
baseDMA& baseDMA::operator=(const baseDMA& rs)
{
    if( this == &rs )
        return *this;
    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    std::cout << "--> baseDMA::operator=(const baseDMA&)\n";
    return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
    return os << "Label: " << rs.label << '\n'
              << "Rating: " << rs.rating << std::endl;
}


// lacksDMA methods
std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
    return os << (const baseDMA&)ls
              << "Color: " << ls.color << std::endl;
}


// hasDMA methods
hasDMA& hasDMA::operator=(const hasDMA& hs)
{
    if( this == &hs )
        return *this;
    baseDMA::operator=(hs); // copy base portion
    delete[] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    std::cout << "--> hasDMA::operator=(const hasDMA&)\n";
    return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
    return os << (const baseDMA&) hs
              << "Style: " << hs.style << std::endl;
}
