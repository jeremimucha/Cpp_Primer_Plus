// classic.h -- chapter 13 pe2
#ifndef CLASSIC_H_
#define CLASSIC_H_

#include <iostream>
#include <cstring>


// Base class
class Cd
{
private:
    char* performers;
    char* label;
    int selections;
    double playtime;
public:
    Cd(const char* s1, const char* s2, int n, double x)
        : performers(new char[std::strlen(s1)+1])
        , label(new char[std::strlen(s2) + 1])
        , selections(n)
        , playtime(x)
        {
            std::strcpy(performers, s1);
            std::strcpy(label, s2);
            std::cout << "--> Cd(const char*, const char*, int, double)\n";
        }
    Cd(const Cd& d)
        : performers(new char[std::strlen(d.performers) + 1])
        , label(new char[std::strlen(d.label) + 1])
        , selections(d.selections)
        , playtime(d.playtime)
        {
            std::strcpy(performers, d.performers);
            std::strcpy(label, d.label);
            std::cout << "--> Cd(const Cd& d)\n";
        }
    Cd()
        : performers(nullptr)
        , label(nullptr)
        , selections(0)
        , playtime(0)
        {
            std::cout << "--> Cd()\n";
        }
    virtual ~Cd()
        {
            delete[] performers;
            delete[] label;
            std::cout << "--> ~Cd()\n";
        }
    virtual void Report() const;
    Cd& operator=(const Cd& d);
};


// derived class
class Classic : public Cd
{
private:
    char* primary;

public:
    Classic(const char* perf, const char* lab, const char* prim, int n, double x)
        : Cd(perf, lab, n, x)
        , primary(new char[std::strlen(prim) + 1])
        {
            std::strcpy(primary, prim);
            std::cout << "--> Classic(const char*, const char*, const char*, int, double)\n";
        }
    Classic(const Cd& d, const char* prim)
        : Cd(d)
        , primary(new char[std::strlen(prim) + 1])
        {
            std::strcpy(primary, prim);
            std::cout << "--> Classic(const Cd&, const char* prim)\n";
        }
    Classic(const Classic& c)
        : Cd(c)
        , primary(new char[std::strlen(c.primary) + 1])
        {
            std::strcpy(primary, c.primary);
            std::cout << "--> Classic(const Classic&)\n";
        }
    Classic()
        : Cd()
        , primary(nullptr)
        {
            std::cout << "--> Classic()\n";
        }
    virtual ~Classic()
        {
            delete[] primary;
            std::cout << "--> ~Classic()\n";
        }
    virtual void Report() const;
    Classic& operator=(const Classic& c);
};


#endif /*CLASSIC_H_*/
