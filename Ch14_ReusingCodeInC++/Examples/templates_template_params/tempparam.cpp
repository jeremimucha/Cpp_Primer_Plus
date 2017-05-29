// tempparam.cpp -- templates as parameters
#include <iostream>
#include <string>
#include <sstream>
#include "stacktp.h"


template <template <typename T> class Thing>
class Crab
{
private:
    Thing<int> s1;
    Thing<double> s2;
public:
    Crab() { }
    // assumes the thing class has push() and pop() members
    bool push(int a, double x)
        { return s1.push(a) && s2.push(x); }
    bool pop(int& a, double& x)
        { return s1.pop(a) && s2.pop(x); }
};


int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    Crab<Stack> nebula;
// Stack must match template <typname T> class Thing
    int ni;
    double nb;
    
    const char* msg = "Enter int double pairs, such as 4 3.5 (empty line to end).\n";
    cout << msg;
    std::string line;
    while( cout << ">> " && getline(cin, line) && !line.empty()){
        std::istringstream iss(line);
        if( !(iss >> ni >> nb) ){
            cout << "Please enter int double pairs (e.g. 42 2.72). Empty line to quit.\n";
            continue;
        }
        if(!nebula.push(ni, nb))
            break;
    }

    while(nebula.pop(ni, nb))
        cout << ni << ", " << nb << endl;
    
    cout << "Done.\n";

    return 0;
}
