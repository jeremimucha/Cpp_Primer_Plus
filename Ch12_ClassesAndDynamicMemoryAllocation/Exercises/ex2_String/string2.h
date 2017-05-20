// string2.h -- chapter 12 pe2
#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
using std::ostream;
using std::istream;


class String
{
private:
    char* str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;   // cin input limit
public:
// constructors and other methods
    String(const char* s);  // constructor
    String()                // default constructor
        :str(new char[1]), len(1)
        { str[0] = '\0'; ++num_strings; }
    String(const String&);  // copy constructor
    ~String();              // destructor
    int length() const { return len; }
    String& stringlow();
    String& stringup();
    int countchar(char c);
// overloaded operator methods
    String& operator=(const String& );
    String& operator=(const char*);
    char& operator[](int i);
    const char& operator[](int i) const;
    const String operator+(const String&) const;
// overloaded operator friends
    friend bool operator<(const String& st1, const String& st2);
    friend bool operator>(const String& st1, const String& st2);
    friend bool operator==(const String& st1, const String& st2);
    friend ostream& operator<<(ostream& os, const String& st);
    friend istream& operator>>(istream& is, String& st);
    friend const String operator+(const char* left, const String& right);
// static function
    static int HowMany();
};


#endif /* STRING1_H_ */
