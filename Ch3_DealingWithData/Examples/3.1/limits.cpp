// limits.cpp -- some integer limits
#include <iostream>
#include <climits>


int main()
{
    using namespace std;

    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    // sizeof operator yields size of type or of variable
    cout << "int is " << sizeof(int) << " bytes.\n";
    cout << "short is " << sizeof(n_short) << " bytes.\n";
    cout << "long is " << sizeof(n_long) << " bytes.\n";
    cout << "long long is " << sizeof(n_llong) << " bytes.\n";
    cout << "\n\n";

    cout << "Maximum values:\n"
         << "int: " << n_int<<'\n'
         << "short: " << n_short<<'\n'
         << "long: " << n_long<<'\n'
         << "long long: " << n_llong<<'\n'
         << endl;

    cout << "Minimum int value = " << INT_MIN <<'\n'
         << "Bits per byte = " << CHAR_BIT << endl;

    return 0;
}
