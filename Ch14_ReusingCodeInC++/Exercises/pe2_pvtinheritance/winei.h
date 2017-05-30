// winei.h -- Chapter 14 pe2 -- Wine class using inheritance
#ifndef WINEI_H_
#define WINEI_H_

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


class Wine : private std::string,
             private Pair< std::valarray<int>, std::valarray<int> >
{
private:
    using ArrayInt = std::valarray<int>;
    using PairArray = Pair<ArrayInt, ArrayInt>;
    int nyears;
public:
    Wine()
        : std::string("noname")
        , Pair<ArrayInt, ArrayInt>(ArrayInt(), ArrayInt())
        , nyears(0)
        { }
    Wine(const char* l, int y)
        : std::string(l)
        , Pair<ArrayInt, ArrayInt>(ArrayInt(y), ArrayInt(y))
        , nyears(y)
        { }
    Wine(const char* l, int y, const int yr[], const int bot[])
        : std::string(l)
        , Pair<ArrayInt, ArrayInt>(ArrayInt(y), ArrayInt(y))
        , nyears(y)
        {
            for(int i=0; i<nyears; ++i){
                Pair<ArrayInt, ArrayInt>::fst()[i] = yr[i];
                Pair<ArrayInt, ArrayInt>::snd()[i] = bot[i];
            }
        }
    void GetBottles();
    void Show() const;
    std::string& Label()
        { return (std::string&)*this; }
    const std::string& Label() const
        { return (const std::string&)*this; }
    int sum() const;
};


#endif /*WINEI_H_*/
