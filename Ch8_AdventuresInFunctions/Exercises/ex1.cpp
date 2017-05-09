// ex1.cpp -- write a function that prints a string once if called with just
// the string. If called with an additional int argument it prints the string
// the number of times the function has been called.
#include <iostream>


void silly(const char* s, int n=0);

int main()
{

    silly("Calling one arg silly");
    silly("Calling two arg silly for the first time", 100);
    silly("Calling two arg silly for the 2nd time", 123);
    silly("Calling one arg silly again");
    silly("Calling two arg silly 3rd time", 999);

    return 0;
}

void silly(const char* s, int n)
{
    static unsigned int times_called = 0;
    int nprints{1};
    
    if(n){
        nprints = ++times_called;
    }

    for(int i=0; i<nprints; ++i){
        std::cout << s << '\n';
    }
}
