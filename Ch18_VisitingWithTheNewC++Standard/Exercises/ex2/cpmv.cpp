#include "cpmv.h"


Cpmv& Cpmv::operator=(const Cpmv& cp)
{
    if(this == &cp)
        return *this;
    delete pi;
    pi = new Info{cp.pi->qcode, cp.pi->zcode};
    std::cout << "--> Cpmv::operator=(const Cpmv &)\n";
    return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv)
{
    if(this == &mv)
        return *this;
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;
    std::cout << "--> Cpmv::operator=(Cpmv &&)\n";
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const
{
    return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
}

void Cpmv::Display() const
{
    std::cout << "obj addr: 0x" << this << '\n'
              << "pi addr: 0x" << pi << '\n'
              << "qcode: " << pi->qcode << ", 0x" << &pi->qcode << '\n'
              << "zcode: " << pi->zcode << ", 0x" << &pi->zcode << '\n';
}
