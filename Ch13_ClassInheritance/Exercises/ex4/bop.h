// bop-cpp -- chapter 13 pe4 - benevelent order of programmers Port class
#ifndef BOP_H_
#define BOP_H_

#include <iostream>
#include <cstring>


class Port
{
private:
    enum { LEN_STYLE=20 };
    char* brand;
    char style[LEN_STYLE];  // i.e., tawny, ruby, vintage
    int bottles;

public:
    Port(const char* br="none", const char* st="none", int b=0)
        : brand(new char[std::strlen(brand) + 1])
        , bottles(b)
        {
            std::strcpy(brand, br);
            std::strncpy(style, st, LEN_STYLE-1);
            style[LEN_STYLE-1] = '\0';
            std::cout << "--> Port(const char*, const char*, int)\n";
        }
    Port(const Port& p)
        : brand(new char[std::strlen(p.brand) + 1])
        , bottles(p.bottles)
        {
            std::strcpy(brand, p.brand);
            // trust that the reference object was correctly initialized
            // thus use strcpy() rather than strncpy()
            std::strcpy(style, p.style);
            std::cout << "--> Port(const Port&)\n";
        }
    virtual ~Port()
        { delete[] brand; std::cout << "--> ~Port()\n"; }
    Port& operator=(const Port& p);
    // adds b to bottles
    Port& operator+=(int b);
    // subtracts b from bottles, if available
    Port& operator-=(int b);
    int BottleCount() const
        { return bottles; }
    virtual void Show() const;

// friends
    friend std::ostream& operator<<(std::ostream& os, const Port& p);
};


class VintagePort : public Port
{
private:
    char* nickname;     // i.e. "The Noble", or "Old Velvet", etc.
    int year;           // vintage year

public:
    VintagePort();
    VintagePort(const char* br, int b, const char* nn, int y);
    VintagePort(const VintagePort& vp);
    ~VintagePort()
        { delete[] nickname; std::cout << "--> ~VintagePort()\n"; }
    VintagePort& operator=(const VintagePort& vp);
    virtual void Show() const;

// friends
    friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};


#endif /*BOP_H_*/
