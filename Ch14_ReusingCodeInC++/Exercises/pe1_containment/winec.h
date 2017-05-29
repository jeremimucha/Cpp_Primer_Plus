// winec.h -- Chapter 14 pe1 - Wine class using containment
#ifndef WINEC_H_
#define WINEC_H_

#include <iostream>
#include <string>
#include <valarray>


template<typename T, typename U>
class Pair
{
private:
    T a;
    U b;
public:
    Pair() { }
    Pair(const T& aval, const U& bval)
        : a(aval), b(bval)
        { }
    T& fst()
        { return a; }
    U& snd()
        { return b; }
    const T& fst() const
        { return a; }
    const U& snd() const
        { return b; }
};


class Wine
{
private:
    using ArrayInt = std::valarray<int>;
    std::string label;
    int nyears;
    Pair< ArrayInt, ArrayInt > yrbtl;   // (vintage_year, bottle_count)
public:
    Wine()
        : label("noname")
        , nyears(0)
        , yrbtl(ArrayInt(), ArrayInt())
        {
            std::cout << "--> Wine()\n";
        }
    Wine(const char* l, int y)
        : label(l)
        , nyears(y)
        , yrbtl(ArrayInt(nyears), ArrayInt(nyears))
        {
            std::cout << "--> Wine(const char*, int)\n";
        }
    Wine(const char* l, int y, const int yr[], const int bot[])
        : label(l)
        , nyears(y)
        , yrbtl(ArrayInt(nyears), ArrayInt(nyears))
        {
            for(int i=0; i<nyears; ++i){
                yrbtl.fst()[i] = yr[i];
                yrbtl.snd()[i] = bot[i];
            }
            std::cout << "--> Wine(const char*, int, const int [], const int [])\n";
        }
    void GetBottles();
    void Show() const;
    std::string& Label()
        { return label; }
    const std::string& Label() const
        { return label; }
    int sum() const;
};

#endif /*WINEC_H_*/
