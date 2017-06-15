// ex2.cpp -- Chapter 18 exercise 2
#ifndef CPMV_H_
#define CPMV_H_

#include <iostream>
#include <string>


class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };
private:
    Info *pi;
public:
    Cpmv()
        : pi{new Info}
        { std::cout << "--> Cpmv()\n"; }
    Cpmv(const std::string& q, const std::string& z)
        : pi{new Info{q, z}}
        { std::cout << "--> Cpmv(string&, string&)\n"; }
    Cpmv(const Cpmv& cp)
        : pi{new Info{cp.pi->qcode, cp.pi->zcode}}
        { std::cout << "--> Cpmv(const Cpmv &)\n"; }
    Cpmv(Cpmv&& mv)
        : pi{mv.pi}
        { 
            mv.pi = nullptr;
            std::cout << "--> Cpmv(Cpmv &&)\n";
        }
    ~Cpmv()
        { delete pi; std::cout << "--> ~Cpmv()\n"; }
    Cpmv& operator=(const Cpmv& cp);
    Cpmv& operator=(Cpmv&& mv);
    Cpmv operator+(const Cpmv& obj) const;
    void Display() const;
};

#endif /*CPMV_H_*/
