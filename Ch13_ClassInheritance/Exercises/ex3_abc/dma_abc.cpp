// dma_abc.cpp -- chapter 13 pe3 -- implementation
#include "dma_abc.h"


// DMA_ABC
// ----------------------------------------------------------------------------
void DMA_ABC::View() const
{
    std::cout << "Label: " << label << ", @: " << (void*)label <<  '\n'
              << "Rating: " << rating
              << std::endl;
}

DMA_ABC& DMA_ABC::operator=(const DMA_ABC& r)
{
    if( this == &r )
        return *this;

    delete[] label;
    label = new char[std::strlen(r.label) + 1];
    std::strcpy(label, r.label);
    rating = r.rating;
    std::cout << "--> DMA_ABC::operator=(const DMA_ABC&)\n";

    return *this;
}

std::ostream& operator<<(std::ostream& os, const DMA_ABC& r)
{
    return os << r.label << ", " << r.rating;
}
// ----------------------------------------------------------------------------


// baseDMA
// ----------------------------------------------------------------------------
void baseDMA::View() const
{
    DMA_ABC::View();
    std::cout << "baseDMA::View(), nothing to add\n";
}

baseDMA& baseDMA::operator=(const baseDMA& r)
{
    if( this == &r )
        return *this;

    // call the base class assignment operator to handle the base class part
    DMA_ABC::operator=(r);  // implicitly upcast to DMA_ABC type
    // nothing more to do
    std::cout << "--> baseDMA::operator=(const baseDMA&)\n";

    return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& r)
{
    return os << "baseDMA: " << r.get_label() << ", " << r.get_rating();
}
// ----------------------------------------------------------------------------


// lacksDMA
// ----------------------------------------------------------------------------
void lacksDMA::View() const
{
    DMA_ABC::View();
    std::cout << "Color: " << color << ", @: " << (void*)color
              << std::endl;
}

lacksDMA& lacksDMA::operator=(const lacksDMA& r)
{
    if( this == &r )
        return *this;

    // call the base class assignment operator to handle the base class part
    DMA_ABC::operator=(r);  // implicit upcast to DMA_ABC type
    std::cout << "--> lacksDMA::operator=(const lacksDMA&)\n";

    return *this;
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& r)
{
    return os << "lacksDMA: " << r.get_label() << ", " << r.get_rating()
              << ", " << r.color;
}
// ----------------------------------------------------------------------------


// hasDMA
// ----------------------------------------------------------------------------
void hasDMA::View() const
{
    DMA_ABC::View();
    std::cout << "Style: " << style << ", @: " << (void*)style
              << std::endl;
}

hasDMA& hasDMA::operator=(const hasDMA& r)
{
    if( this == &r )
        return *this;
    
    // handle the base class part
    DMA_ABC::operator=(r);  // implicit upcast to DMA_ABC type
    delete[] style;
    style = new char[std::strlen(r.style) + 1];
    std::strcpy(style, r.style);

    std::cout << "--> hasDMA::operator=(const hasDMA&)\n";

    return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& r)
{
    return os << "hasDMA: " << r.get_label() << ", " << r.get_rating()
              << ", " << r.style;
}
// ----------------------------------------------------------------------------
