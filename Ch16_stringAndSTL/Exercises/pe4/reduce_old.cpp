// reduce_old.cpp -- Ch16 pe4 -- reduce function with an "old" interface
#include <iostream>
#include <algorithm>
#include <string>


int reduce(long ar[], int n);
template<typename InputIterator>
void show_array(InputIterator begin, InputIterator end)
{
    while(begin != end)
        std::cout << *begin++ << ' ';
}

int main()
{
    long testarray[] = {24, 12, 5, 63, 88, 12, 12, 11, 53, 24, 5};
    int size_arr = sizeof(testarray) / sizeof(testarray[0]);
    std::cout << "Original array: ";
    show_array(testarray, testarray+size_arr);
    std::cout << std::endl;
    int newsize = reduce(testarray, size_arr);
    std::cout << "Array after reduce: ";
    show_array(testarray, testarray+newsize);
    std::cout << std::endl;
    std::cout << "Array after recude, original size: ";
    show_array(testarray, testarray+size_arr);
}


int reduce(long ar[], int n)
{
    std::sort(ar, ar+n);
    long* last = std::unique(ar, ar+n);
    return last - ar;
}
