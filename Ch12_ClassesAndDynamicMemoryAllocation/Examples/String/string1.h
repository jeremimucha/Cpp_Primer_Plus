// string1.h -- fixed and augmented string class definition
#ifndef STRING1_H_
#define STRING1_H_
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
// overloaded operator methods
    String& operator=(const String& );
    String& operator=(const char*);
    char& operator[](int i);
    const char& operator[](int i) const;
// overloaded operator friends
    friend bool operator<(const String& st1, const String& st2);
    friend bool operator>(const String& st1, const String& st2);
    friend bool operator==(const String& st1, const String& st2);
    friend ostream& operator<<(ostream& os, const String& st);
    friend istream& operator>>(istream& is, String& st);
// static function
    static int HowMany();
};


#endif /* STRING1_H_ */
