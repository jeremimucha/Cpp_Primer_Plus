// vect.h -- Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>


namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};
        // RECT for rectangular, POL for Polar modes
    private:
        double x;       // horizontal
        double y;       // vertical
        double mag;     // length of vector
        double ang;     // direction of vector in degrees
        Mode mode;      // RECT or POL
    // private methods for settings values
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector()
            :x(0.0), y(0.0), mag(0.0), ang(0.0), mode(RECT) { }
        Vector(double n1, double n2, Mode form=RECT);
        void reset(double n1, double n2, Mode form=RECT);
        ~Vector();
        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const { return mag; }
        double angval() const { return ang; }
        void polar_mode();  // set mode to POL
        void rect_mode();   // set mode to RECT
    // operator overloading
        Vector operator+(const Vector& b) const;
        Vector operator-(const Vector& b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
    // friends
        friend Vector operator*(double n, const Vector& a);
        friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    };
} // namespace VECTOR


#endif /* VECTOR_H_ */
