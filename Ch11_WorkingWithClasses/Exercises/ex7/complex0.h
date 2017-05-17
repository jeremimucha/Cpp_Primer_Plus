// complex.h -- chapter 11 exercise 7 
// definition of a class representing a complex number
#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>


class Complex0
{
private:
    double re;      // real part
    double im;      // imaginary part
public:
    Complex0()
        :re(0), im(0) { }
    explicit Complex0(double real)
        :re(real), im(0) { }
    Complex0(double real, double imaginary)
        :re(real), im(imaginary) { }
// operators
    Complex0 operator+(const Complex0& c) const
        { return Complex0(re + c.re, im + c.im); }
    Complex0 operator-(const Complex0& c) const
        { return Complex0(re - c.re, im - c.im); }
    Complex0 operator*(const Complex0& c) const
        { return Complex0(re*c.re - im*c.im, re*c.im + im*c.re); }
    Complex0 operator*(double x)
        { return Complex0(x * re, x * im); }
    Complex0 operator~() const
        { return Complex0(re, -im); }
// friend functions
friend Complex0 operator*(double x, const Complex0& c);
friend std::ostream& operator<<(std::ostream& os, const Complex0& c);
friend std::istream& operator>>(std::istream& is, Complex0& c);
};


#endif /*COMPLEX_H_*/
