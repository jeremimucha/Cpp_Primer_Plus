// floatnum.cpp -- floating-point types
#include <iostream>
#include <cfloat>


int main()
{
    using namespace std;

    cout << "Some of the floating point number defines:\n\n"
         << "Significant digits:\n"
         << "float: " << FLT_DIG << '\n'
         << "double: " << DBL_DIG << '\n'
         << "long double: " << LDBL_DIG << '\n';

    cout << "\nNumber of bits used to represent the mantisa:\n"
         << "float: " << FLT_MANT_DIG << '\n'
         << "double: " << DBL_MANT_DIG << '\n'
         << "long double: " << LDBL_MANT_DIG << '\n';

    cout << "\nMaximum exponent values:\n"
         << "float: " << FLT_MAX_10_EXP << '\n'
         << "double: " << DBL_MAX_10_EXP << '\n'
         << "long double: " << LDBL_MAX_10_EXP << '\n';

    cout << "\nMinimum exponent values:\n"
         << "float: " << FLT_MIN_10_EXP << '\n'
         << "double: " << DBL_MIN_10_EXP << '\n'
         << "long double: " << LDBL_MIN_10_EXP << '\n';

    cout.setf(ios_base::fixed, ios_base::floatfield);   // fixed-point
    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;
    const float million = 1.0e6;

    cout << "tub = " << tub
         << ", a million tubs = " << million * tub
         << ",\nand ten million tubs = "
         << 10 * million * tub 
         << endl;

    cout << "mint = " << mint << " and a million mints = "
         << million * mint
         << endl;

    return 0;
}
