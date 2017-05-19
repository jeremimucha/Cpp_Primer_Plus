// cow.h -- chapter 12 pe1
#ifndef COW_H_
#define COW_H_
#include <iostream>
using std::cout;


class Cow
{
private:
    char name[20];
    char* hobby;
    double weight;
    static int count;
public:
    Cow()
        :hobby(nullptr), weight(0)
        { 
            name[0] = '\0';
            ++count;
            cout << "Cow() default constructor called. Count: "  << count <<'\n';
        }
    Cow(const char* nm, const char* ho, double wt);
    Cow(const Cow& c);
    ~Cow();
    Cow& operator=(const Cow& c);
    void ShowCow() const;   // display all cow
};


#endif /*COW_H_*/
