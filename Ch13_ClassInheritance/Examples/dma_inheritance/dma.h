// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_

#include <iostream>
#include <cstring>


// Base class uinsg DMA
class baseDMA
{
private:
    char* label;
    int rating;

public:
    baseDMA(const char* l="null", int r=0)
        :label(new char[std::strlen(l) + 1]), rating(r)
        {
            std::strcpy(label, l);
            std::cout << "--> baseDMA(const char*, int)\n";
        }
    baseDMA(const baseDMA& rs)
        :label(new char[std::strlen(rs.label) + 1]), rating(rs.rating)
        {
            std::strcpy(label, rs.label);
            std::cout << "--> baseDMA(const baseDMA&)\n";
        }
    virtual ~baseDMA()
        { delete[] label; std::cout<< "--> ~baseDMA()\n"; }
    baseDMA& operator=(const baseDMA& rs);
    friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};


// derived class without DMA
// no d estructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public baseDMA
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char* c="blank", const char* l="null", int r=0)
        :baseDMA(l,r)
        {
            std::strncpy(color, c, COL_LEN-1);
            color[COL_LEN-1] = '\0';
            std::cout << "--> lacksDMA(const char*, const char*, int)\n";
        }
    lacksDMA(const char* c, const baseDMA& rs)
        :baseDMA(rs)
        {
            std::strncpy(color, c, COL_LEN-1);
            color[COL_LEN-1] = '\0';
            std::cout << "--> lacksDMA(const char*, const baseDMA&)\n";
        }
    ~lacksDMA() // not actually necessary - default would be fine
        { std::cout << "--> ~lacksDMA()\n"; }
    friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};


// derived class with DMA
class hasDMA : public baseDMA
{
private:
    char* style;
public:
    hasDMA(const char* s="none", const char* l="null", int r=0)
        :baseDMA(l, r), style(new char[std::strlen(s) + 1])
        {
            std::strcpy(style, s);
            std::cout << "--> hasDMA(const char*, const char*, int)\n";
        }
    hasDMA(const char* s, const baseDMA& rs)
        :baseDMA(rs), style(new char[std::strlen(s) + 1])
        {
            std::strcpy(style, s);
            std::cout << "--> hasDMA(const char*, const baseDMA&)\n";
        }
    hasDMA(const hasDMA& hs)
        :baseDMA(hs)    // invoke base class copy construcotr
        ,style(new char[std::strlen(hs.style) + 1])
        {
            std::strcpy(style, hs.style);
            std::cout << "--> hasDMA(const hasDMA&)\n";
        }
    ~hasDMA()
        { delete[] style; std::cout << "--> ~hasDMA()\n"; }
    hasDMA& operator=(const hasDMA& hs);
    friend std::ostream& operator<<(std::ostream& os, const hasDMA& hs);
};


#endif /*DMA_H_*/
