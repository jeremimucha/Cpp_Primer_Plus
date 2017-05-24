// dma_abc.h -- chapter 13 pe3 -- inheritance, abc's and dynamic memory alloc
#ifndef DMA_ABC_H_
#define DMA_ABC_H_

#include <iostream>
#include <cstring>


// DMA abstract base class
class DMA_ABC
{
private:
    char* label;
    int rating;
public:
    DMA_ABC(const char* l="null", int r)
        : label(new char[std::strlen(l) + 1])
        , rating(r)
        {
            std::strcpy(label, l);
            std::cout << "--> DMA_ABC(const char*, int r)\n";
        }
    DMA_ABC(const DMA_ABC& r)
        : label(new char[std::strlen(r.label) + 1])
        , rating(r.rating)
        {
            std::strcpy(label, r.label);
            std::cout << "--> DMA_ABC(const DMA_ABC&)\n";
        }
    virtual void View() const = 0;
    virtual ~DMA_ABC()
        { delete[] label; std::cout << "--> ~DMA_ABC()\n"; }
    DMA_ABC& operaotr=(const DMA_ABC& r);
    friend std::ostream& operator<<(std::ostream& os, const DMA_ABC& r);
};


class baseDMA : public DMA_ABC
{
public:
    baseDMA(const char* l="null", int r=0)
        : DMA_ABC(l, r);
        { std::cout << "--> baseDMA(const char*, int)\n"; }
    
    // Not actually needed - default memberwise-copy-constructor is OK here
    baseDMA(const baseDMA& r)
        : DMA_ABC(r)
        { std::cout << "--> baseDMA(const baseDMA&)\n"; }
    
    virtual void View() const;
    virtual ~baseDMA()
        { std::cout << "--> ~baseDMA()\n"; }
    // not actually needed - the default memberwise-copy-assignment is OK here
    baseDMA& operator=(const baseDMA& r);
    friend std::ostream& operator<<(std::ostream& os, const baseDMA& r);
};


class lacksDMA : DMA_ABC
{
private:
    enum {COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char* c="blank", const char* l="null", int r=0)
        : DMA_ABC(l, r)
        {
            std::strncpy(color, c, COL_LEN-1);
            color[COL_LEN-1] = '\0';
            std::cout << "--> lacksDMA(const char*, const char*, int)\n";
        }
    // Not actually needed
    lacksDMA(const lacksDMA& r)
        : DMA_ABC(r)
        { std::cout << "--> lacksDMA(const lacksDMA&)\n"; }
    virtual void View() const;
    virtual ~lacksDMA()
        { std::cout << "--> ~lacksDMA()\n"; }
    // Not actually needed
    lacksDMA& operator=(const lacksDMA& r);
    firend std::ostream& operator<<(std::ostream& os, const lacksDMA& r);
};


class hasDMA : public DMA_ABC
{
private:
    char* style;
public:
    hasDMA(const char* s="none", const char* l="null", int r=0)
        : DMA_ABC(l, r)
        , style(new char[std::strlen(s) + 1])
        {
            std::strcpy(style, s);
            std::cout << "--> hasDMA(const char*, const char*, int)\n";
        }
    //  copy constructor necessary
    hasDMA(const hasDMA& r)
        : DMA_ABC(r)    // invoke base class copy constructor
        , style(new char[std::strlen(r.style) + 1])
        {
            std::strcpy(style, r.style);
            std::cout << "--> hasDMA(const hasDMA&)\n";
        }
    virtual void View() const;
    virtual ~hasDMA()
        { delete[] style; std::cout << "--> ~hasDMA()\n"; }
    hasDMA& operator=(const hasDMA& r);
    friend std::ostream& operator<<(std::ostream& os, const hasDMA& r);
};


#endif /*DMA_ABC_H_*/
