// stringbad.cpp -- StringBad class methods
#include <cstring>
#include "stringbad.h"
using std::cout;


// initializing static class member
int StringBad::num_strings = 0;


// class methods

// construct StringBad from C-String
StringBad::StringBad(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    ++num_strings;
    cout << num_strings << ": \"" << str << "\" object created\n";
}

// destructor
StringBad::~StringBad()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete[] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
    return os << st.str;
}
