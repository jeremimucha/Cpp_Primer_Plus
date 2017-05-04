// arrfun4.cpp -- functions with an array range
#include <iostream>


const int ArSize = 8;


int sum_arr(const int* begin, const int* end);


int main()
{
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    std::cout << "array address = " << cookies << '\n'
              << "sizeof(cookies) = " << sizeof(cookies) << '\n';

    int sum = sum_arr(cookies, cookies + ArSize);
    std::cout << "Total cookies eaten: " << sum << std::endl;

    sum = sum_arr(cookies, cookies + 3);
    std::cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(cookies + 4, cookies + 8);
    std::cout << "Last four eaters ate " << sum << " cookies.\n";

    return 0;
}


// return the sum of an integer array
int sum_arr(const int* begin, const int* end)
{
    int total{0};
    while( begin != end )
        total += *begin++;
    return total;
}
