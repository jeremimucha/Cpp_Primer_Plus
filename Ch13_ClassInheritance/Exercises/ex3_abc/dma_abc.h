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
    
    virtual void View() const = 0;
    virtual ~DMA_ABC()
        { std::cout << "--> ~DMA_ABC()\n"; }
};


class baseDMA : public DMA_ABC
{
private:
    //
public:
    
};


#endif /*DMA_ABC_H_*/
