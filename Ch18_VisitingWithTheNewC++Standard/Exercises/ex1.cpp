// ex1.cpp -- Chapter 18 exercise 1
#include <iostream>
#include <initializer_list>
using std::initializer_list;

template<typename T>
T average_list(initializer_list<T> il)
{
    auto p = il.begin();
    T total = *p++;
    while( p != il.end() ){
        total += *p++;
    }
    return total / il.size();
}


int main()
{
    using namespace std;
// list of double deduced from list contents
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;
// list of int deduced from list contents
    cout << average_list({20, 30, 19, 17, 45, 38} ) << endl;
// forced list of double
    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;
    return 0;
}
