// string1.cpp -- String class methods
#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;


// initializing static class member
int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char* s)
{
    len = std::strlen(s);       // set size
    str = new char[len + 1];
    std::strcpy(str, s);
    ++num_strings;
}

String::String(const String& st)
{
    ++num_strings;              // static member update
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete[] str;
}

// overloaded operator methods;
String& String::operator=(const String& st)
{
    if( this == &st )
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

    // assign C-string to a String
String& String::operator=(const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

    // read-write char access for non-const String
char& String::operator[](int i)
{
    return str[i];
}

    // read only char access for const String
const char& String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends
bool operator<(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

inline
bool operator>(const String& st1, const String& st2)
{
    return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

    // simple String output
ostream& operator<<(ostream& os, const String& st)
{
    return os << st.str;
}

    // quick and dirty String input
istream& operator>>(istream& is, String& st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is)
        st = temp;
    while( is && is.get() != '\n' )
        ;
    return is;
}
