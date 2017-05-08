// review.cpp -- chapter 8 review
#include <iostream>
#include <string>
#include <typeinfo>


// #3
void iquote(int i);
void iquote(double d);
void iquote(std::string& s);


// #4
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void box_show(box& b);
void box_set_volume(box& b);


// #6
// a
double mass(double density, double volume=1.0);
// b
void repeat(int n, const char* text);
void repeat(const char* text);
// c
int average(int a, int b);
double average(double a, double b);
// d -- impossible

// #7
template<typename T>
T& larger(T& a, T& b)
{
    return a > b ? a : b;
}

// #8
template<> box& larger<box>(box& a, box& b)
{
    return a.volume > b.volume ? a : b;
}

// #9
/*
int g(int x);
...
float m = 5.5f;
float& rm = m;
decltype(m) v1 = m;     -> float
decltype(rm) v2 = m;    -> float&
decltype((m)) v3 = m;   -> float&
decltype(g(100)) v4;    -> int
decltype(2.0 * m) v5;   -> double
*/
int g(int x)
{
    return x;
}

int main()
{
    // #9
    float m = 5.5f;
    float& rm = m;
    std::cout << "decltype(m) = " << typeid(decltype(m)).name() <<'\n'
              << "decltype(rm) = " << typeid(decltype(rm)).name() <<'\n'
              << "decltype((m)) = " << typeid(decltype((m))).name() <<'\n'
              << "decltype((rm)) = " << typeid(decltype((rm))).name() <<'\n'
              << "decltype(g(100)) = " << typeid(decltype(g(100))).name() <<'\n'
              << "decltype(2.0*m) = " << typeid(decltype(2.0*m)).name()
              << std::endl;
    return 0;
}


// #3
void iquote(int i)
{
    std::cout << "\"" << i << "\"";
}
void iquote(double d)
{
    std::cout << "\"" << d << "\"";
}
void iquote(std::string& s)
{
    std::cout << "\"" << s << "\"";
}

// #4
void box_show(box& b)
{
    std::cout << "Maker: " << b.maker
              << "\nHeight: " << b.height
              << "\nWidth: " << b.width
              << "\nLength: " << b.length
              << "\nVolume: " << b.volume;
}
void box_set_volume(box& b)
{
    b.volume = b.height * b.width * b.length;
}
