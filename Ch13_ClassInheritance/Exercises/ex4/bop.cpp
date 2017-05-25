// bop.cpp -- chapter 13 pe4 - Port implementation code
#include "bop.h"


Port& Port::operator=(const Port& p)
{
    if( this == &p )
        return *this;
    
    delete[] brand;
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    // trust that the assigned obj was properly initialized,
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


// VintagePort
void VintagePort::Show() const
{
    Port::Show();
    std::cout << "Nickname: " << nickname << '\n'
              << "Year: " << year
              << std::endl;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
    if( this == &vp )
        return *this;

    // handle the base class part
    Port::operator=(vp);    // implicit upcast to type Port

    delete[] nickname;
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;

    std::cout << "--> VintagePort::operator=(const VintagePort&)\n";

    return *this;
}

