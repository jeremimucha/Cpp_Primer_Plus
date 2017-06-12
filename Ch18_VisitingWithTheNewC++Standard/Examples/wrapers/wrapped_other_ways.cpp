// wrapped_other_ways.cpp -- other ways to avoid multiple template instantiation
#include <iostream>
#include <functional>
#include "somedefs.h"


// redefine use_f - adapt the type of the formal parameter f to match
// the original arguments. Use a function wrapper object as the second param.
template<typename T>
T use_f(T v, std::function<T(T)> f)     // f call signature is T(T)
{
    static int count = 0;
    ++count;
    std::cout << " use_f count = " << count
              << ", &count = " << &count << std::endl;
    return f(v);
}

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }


int main()
{
    using std::cout;
    using std::endl;

    double y = 1.21;

    cout << "Function pointer dub:\n";
    cout << "  " << use_f<double>(y, dub) << endl;
    cout << "Function pointer square:\n";
    cout << "  " << use_f<double>(y, square) << endl;
    cout << "Function object Fp:\n";
    cout << "  " << use_f<double>(y, Fp(10.0)) << endl;
    cout << "Function object Fq:\n";
    cout << "  " << use_f<double>(y, Fq(10.0)) << endl;
    cout << "Lambda expression 1:\n";
    cout << "  " << use_f<double>(y, [](double u){return u*u;}) << endl;
    cout << "Lambda expression 2:\n";
    cout << "  " << use_f<double>(y, [](double u){return u+u/2.0;}) << endl;
    return 0;
}
