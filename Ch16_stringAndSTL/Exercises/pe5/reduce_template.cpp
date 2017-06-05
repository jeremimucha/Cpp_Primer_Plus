// reduce_template.cpp -- CH16 pe5 -- reduce function template with 'old' iterface
#include <iostream>
#include <algorithm>
#include <string>


template<typename T>
int reduce(T ar[], int n);
template<typename OutputIterator>
void show_array(OutputIterator begin, OutputIterator end);


int main()
{
    using std::cout;
    using std::endl;
    long arrlong[] = {11, 9, 42, 42, 9, 9, 9, 42, 11, 24, 72};
    size_t size_arrlong = sizeof(arrlong) / sizeof(arrlong[0]);
    std::string arrstr[] = {"one", "two", "one", "one", "abc", "foo",
                                "three", "foobar", "nope", "nope" };
    size_t size_arrstr = sizeof(arrstr) / sizeof(arrstr[0]);
    cout << "Original long array: ";
    show_array(arrlong, arrlong + size_arrlong);
    cout << endl;
    cout << "Original str array: ";
    show_array(arrstr, arrstr+size_arrstr);
    cout << endl;
    size_t s2_arrlong = reduce(arrlong, size_arrlong);
    size_t s2_arrstr = reduce(arrstr, size_arrstr);
    cout << "long array after reduce: ";
    show_array(arrlong, arrlong+s2_arrlong);
    cout << endl;
    cout << "long array after reduce, original size: ";
    show_array(arrlong, arrlong+size_arrlong);
    cout << endl;
    cout << "string array after reduce: ";
    show_array(arrstr, arrstr+s2_arrstr);
    cout << endl;
    cout << "string array after reduce, original size ("<<size_arrstr << "): ";
    show_array(arrstr, arrstr+size_arrstr);

    return 0;
}

template<typename T>
int reduce(T ar[], int n)
{
    std::sort(ar, ar+n);
    T* last = std::unique(ar, ar+n);
    return last - ar;
}

template<typename InputIterator>
void show_array(InputIterator begin, InputIterator end)
{
    while( begin != end ){
        std::cout << *begin++ << ", ";
    }
}
