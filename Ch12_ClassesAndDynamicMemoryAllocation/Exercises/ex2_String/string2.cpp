// string2.cpp -- chapter 12 pe2 -- String class methods
#include <cstring>
#include <cctype>
#include "string2.h"
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
    cout << "-> String(const char*) constructor. N = " << num_strings << '\n';
}

String::String(const String& st)
{
    ++num_strings;              // static member update
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    cout << "-> String(const String&) copy constructor. N = " << num_strings << '\n';
}

String::~String()
{
    --num_strings;
    delete[] str;
    cout << "-> ~String() destructor. N = " << num_strings << '\n';
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
    cout << "-> operator=(const String& st) assignment. N = " << num_strings << '\n';
    return *this;
}

    // assign C-string to a String
String& String::operator=(const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    cout << "-> operaotr(const char*) assignment. N = " << num_strings << '\n';
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

const String String::operator+(const String& s) const
{
    // char* temp = new char[len + s.len -1];
    char temp[len + s.len +1];
    std::strcpy(temp, str);
    std::strcat(temp, s.str);
    return String(temp);
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

const String operator+(const char* left, const String& right)
{
    int llen = std::strlen(left);
    char temp[llen + right.len +1];
    std::strcpy(temp, left);
    std::strcat(temp, right.str);
    return String(temp);
}


String& String::stringlow()
{
    for(char* c = str; c != str+len; ++c){
        if( std::isalpha(*c) )
            *c = std::tolower(*c);
    }
    return *this;
}

String& String::stringup()
{
    for(char* c = str; c != str+len; ++c){
        if( std::isalpha(*c) )
            *c = std::toupper(*c);
    }
    return *this;
}

int String::countchar(char c)
{
    int count{0};
    for(char* ch = str; ch != str+len; ){
        if( *ch++ == c)
            ++count;
    }
    return count;
}
