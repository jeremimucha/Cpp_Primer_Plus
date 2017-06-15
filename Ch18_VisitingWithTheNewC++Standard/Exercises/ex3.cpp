// ex3.cpp -- Chapter 18 exercise 3 - variadic template
#include <iostream>


// 0 parameters - end of recursion
// long double sum_values() { }

template<typename T>
long double sum_values(const T& v)
{
    return v;
}

// definition for 3 or more parameters
template<typename T, typename... Args>
long double sum_values(const T& val, const Args&... args)
{
    return val + sum_values(args...);
}

int main()
{
    std::cout << "A = " << (int)'A' << '\n';
    std::cout << "sum_values(1, 2.2, 3.3f, 'A') = "
              << sum_values(1, 2.2, 3.3f, 'A') << '\n';
}
