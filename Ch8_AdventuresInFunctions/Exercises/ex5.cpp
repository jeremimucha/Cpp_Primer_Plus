// ex5.cpp -- return the largest item in an array of elements of type T
#include <iostream>


template<typename T>
T max5(T arr[], int size);


int main()
{
    int ints[] = {3, 5, 12, 1, 6, 34, 76, 23, 77};
    constexpr int size_ints = sizeof(ints)/sizeof(ints[0]);
    double doubles[] = {33.23, .23, 1, 65.3, 7.32, 65.3, 32.4};
    constexpr int size_doubles = sizeof(doubles)/sizeof(doubles[0]);

    std::cout << "max5(ints, size_ints) = " << max5(ints, size_ints)
              << std::endl;
    std::cout << "max5(doubles, size_doubles) = " << max5(doubles, size_doubles)
              << std::endl;


}

template<typename T>
T max5(T arr[], int size)
{
    T max = arr[0];

    for(int i=1; i<size; ++i){
        max = max < arr[i] ? arr[i] : max;
    }

    return max;
}
