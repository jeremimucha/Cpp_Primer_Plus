// ex6.cpp -- return the largest item in an array of elements of type T
#include <iostream>
#include <cstring>


template<typename T>
T maxn(T arr[], int size);
template<>
const char* maxn<const char*>(const char* arr[], int size);

struct strn
{
    const char* str;
    int len;
};

int main()
{
    int ints[] = {3, 5, 12, 1, 6, 34, 76, 23, 77};
    constexpr int size_ints = sizeof(ints)/sizeof(ints[0]);
    double doubles[] = {33.23, .23, 1, 65.3, 7.32, 65.3, 32.4};
    constexpr int size_doubles = sizeof(doubles)/sizeof(doubles[0]);

    std::cout << "maxn(ints, size_ints) = " << maxn(ints, size_ints)
              << std::endl;
    std::cout << "maxn(doubles, size_doubles) = " << maxn(doubles, size_doubles)
              << std::endl;

    constexpr int size_strings = 5;
    const char* strings[size_strings] = {"One", "Two", "Three",
                                         "Four4", "Five"};
    std::cout << "Longest string: " << maxn(strings, size_strings) << std::endl;
}

template<typename T>
T maxn(T arr[], int size)
{
    T max = arr[0];

    for(int i=1; i<size; ++i){
        max = max < arr[i] ? arr[i] : max;
    }

    return max;
}

template<>
const char* maxn<const char*>(const char* arr[], int size)
{
    strn longest = {arr[0], std::strlen(arr[0])};
    for(int i=0; i<size; ++i){
        int len{0};
        longest = (longest.len < (len=std::strlen(arr[i]))) ?
                  strn{arr[i], len}
                  : longest;
    }
    return longest.str;
}
