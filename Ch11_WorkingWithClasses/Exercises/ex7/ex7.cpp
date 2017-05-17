// ex7.cpp -- code using the Complex0 class
#include <iostream>
#include "complex0.h"
using namespace std;


int main()
{
    Complex0 a(3.0, 4.0);
    Complex0 c;
    const char* msg = "Enter a complex number (q to quit):\n";
    while(cout << msg && cin >> c){
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
    }
    cout << "Done!\n";
    return 0;
}
