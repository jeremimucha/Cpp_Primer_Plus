// classic.h -- chapter 13 pe 1
#ifndef CLASSIC_H_
#define CLASSIC_H_

#include <iostream>
#include <cstring>


class Cd                    // represents a Compact Disk
{
private:
    enum { LEN_LABEL=20, LEN_PERF=50 };
    char performers[LEN_PERF];
    char label[LEN_LABEL];
    int selections;         // number of selections
    double playtime;        // plauing time in minutes
public:
    Cd(const char* s1, const char* s2, int n, double x)
        :selections(n), playtime(x)
        {
            std::strncpy(performers, s1, LEN_PERF-1);
            performers[LEN_PERF-1] = '\0';
            std::strncpy(label, s2, LEN_LABEL-1);
            label[LEN_LABEL-1] = '\0';
            std::cout << "--> Cd(const char*, const char*, int, double)\n";
        }
    
    // copy constructor not needed - member-wise copy is fine
    // no dynamic allocation was used
    /*
    Cd(const Cd& d)
        :selections(d.selections), playtime(d.playtime)
        {
            std::strcpy(performers, d.performers);
            std::strcpy(label, d.label);
            std::cout << "--> Cd(const Cd&)\n";
        }
    */

    Cd()
        :performers{0}, label{0}, selections(0),  playtime(0)
        { std::cout << "--> Cd()\n"; }

    // destructor not needed - no dynamic allocation used.
    /*
    ~Cd()
        { std::cout << "--> ~Cd()\n"; }
    */

    virtual void Report() const;    // reports all Cd data
    
    // Assignment operator not needed. Member-wise assignment is fine
    // no dynamic allocation was used
    /*
    Cd& operator=(const Cd& d);
    */
};


// derived class
class Classic : public Cd
{
private:
    enum { LEN_PRIM=20 };
    char primary[LEN_PRIM];
public:
    Classic(const char* perf, const char* lab, const char* prim, int n, double x)
        :Cd(perf, lab, n, x)
        {
            std::strncpy(primary, prim, LEN_PRIM-1);
            primary[LEN_PRIM-1] = '\0';
            std::cout << "--> Classic(const char*, const char*, const char*, int, double)\n";
        }
    Classic(const Cd& d, const char* prim)
        :Cd(d)
        {
            std::strncpy(primary, prim, LEN_PRIM-1);
            primary[LEN_PRIM-1] = '\0';
            std::cout << "--> Classic(const Cd&, const char*)\n";
        }
    Classic()
        :Cd(), primary{0}
        { std::cout << "--> Classic()\n"; }
    virtual void Report() const;
    /*
    ~Classic()
        { std::cout << "--> ~Classic()\n"; }
    */
};


#endif
