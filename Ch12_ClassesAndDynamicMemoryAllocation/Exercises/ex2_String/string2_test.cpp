// string2_test.cpp -- chapter 12 pe2 -- String class test
#include <iostream>
#include "string2.h"
using std::cout;


int main()
{
    String s1 = "ABCDE";
    String s2 = "abcde";
    String s3(s1 + s2);
    String s4 = s1 + "zxcvb";
    String s5 = "ZXCVB" + s2;
    cout << "s1: " << s1 << '\n';
    cout << "s2: " << s2 << '\n';
    cout << "s3: " << s3 << '\n';
    cout << "s4: " << s4 << '\n';
    cout << "s5: " << s5 << '\n';
    cout << "s3.stringlow(): " << s3.stringlow() << '\n';
    cout << "s3.stringup(): " << s3.stringup() << '\n';
    cout << "s4.stringlow(): " << s4.stringlow() << '\n';
    cout << "s4.stringup(): " << s4.stringup() << '\n';
    cout << "s5.stringlow(): " << s5.stringlow() << '\n';
    cout << "s5.stringup(): " << s5.stringup() << '\n';
    String s6(s5 + s4 + s1 + s1 + s2 + s2);
    s1 = s6 + s1;
    cout << "s6: " << s6 << '\n';
    cout << "s1: " << s1 << '\n';
    cout << "s6.countchar('a'): " << s6.countchar('a') << '\n';
    cout << "s6.countchar('A'): " << s6.countchar('A') << '\n';
    return 0;
}
