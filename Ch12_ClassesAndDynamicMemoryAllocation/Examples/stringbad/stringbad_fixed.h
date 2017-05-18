// stringbad.h -- flawed string class definition
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
#include <iostream>
#include <cstring>
using std::cout;


class StringBad
{
private:
    char* str;                  // pointer to string
    int len;                    // length of string
    static int num_strings;     // number of objects
public:
    StringBad(const char* s);   // constructor
    StringBad()                 // default constructor
        :str(new char[4]), len(4)
        { 
            std::strcpy(str, "C++");
            ++num_strings;
            cout << num_strings << ": \"" << str
                 << "\" default object created\n";
        }
    StringBad(const StringBad& s)
        :str(new char[s.len + 1]), len(s.len)
        {
            std::strcpy(str, s.str);
            ++num_strings;
            cout << num_strings << ": \"" << str
                 << "\" copy constructor called\n";
        }
    ~StringBad();               // destructor;
    StringBad& operator=(const StringBad& s);
// friend function
    friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};


#endif /*STRNGBAD_H_*/
