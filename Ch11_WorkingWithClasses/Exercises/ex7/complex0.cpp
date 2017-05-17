// complex0.cpp -- implementation code for Complex0 class
#include "complex0.h"
using std::ios_base;


Complex0 operator*(double x, const Complex0& c)
{
    return Complex0(x * c.re, x * c.im); 
}


std::ostream& operator<<(std::ostream& os, const Complex0& c)
{
    const char* i = c.im < 0 ? ", -i" : ", i";
    double imag = c.im < 0 ? -c.im : c.im;
    return os << '(' << c.re << i << imag <<')';
}

std::istream& operator>>(std::istream& is, Complex0& c)
{
    // ( 1.0 , i 1.0 )
    char ch1, ch2, ch3;
    double real, imag;

    if( !(is >> ch1) )
        return is;  // failed to read a single character, eof()? bad()?
    if( ch1 != '(' ){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    is >> real >> ch1 >> ch2 >> imag >> ch3;
    if( !is )
        return is;
    if( ch1 != ',' || (ch2 != 'i' && ch2 != 'j') || ch3 != ')' ){
        is.clear(ios_base::failbit);
        return is;
    }

    c.re = real;
    c.im = imag;

    return is;
}
