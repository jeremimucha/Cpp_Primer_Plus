// address.cpp -- using the & operator to find addresses
#include <iostream>


int main()
{
    using namespace std;

    int donuts = 6;
    double cups = 4.5;
    

    cout << "donuts value = " << donuts
         << " and donuts address = " << &donuts
         << endl;
    cout << "cups value = " << cups
         << " and cups address = " << &cups
         << endl;
    cout << "sizeof(double) = " << sizeof(double)
         << "\nsizeof(int) = " << sizeof(int)
         << endl;

    return 0;
}
