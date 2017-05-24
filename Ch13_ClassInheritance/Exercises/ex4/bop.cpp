// bop.cpp -- chapter 13 pe4 - Port implementation code
#include "bop.h"


Port& Port::operator=(const Port& p)
{
    if( this == &p )
        return *this;
    
    delete[] brand;
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    // trust that the assignment obj was properly initialized,
    // thus use strcpy rather than strncpy
    std::strcpy(style, p.style);
    bottles = p.bottles;

    std::cout << "--> Port::operator=(const Port& p)\n";

    return *this;
}

Port& Port::operator+=(int b)
{
    this->bottles += b;
    return *this;
}

Port& Port::operator-=(int b)
{
    if( b <= bottles )
        bottles -= b;

    return *this;
}

void Port::Show() const
{
    std::cout << "Brand: " << brand << '\n'
              << "Kind: " << style << '\n'
              << "Bottles: " << bottles
              << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
    return os << p.brand << ", " << p.style << ", " << p.bottles;
}
