// stone.cpp -- user-defined conversions
#include <iostream>
#include "stonewt.h"
using std::cout;


void display(const Stonewt& st, int n);


int main()
{
    Stonewt incognito = 275;    // uses constructor to initialize
    Stonewt wolfe(287.7);       // same as Stonewt wolfe = 285.7
    Stonewt taft(21, 8);

    cout << "The celebrity weighed ";
    incognito.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The President weighed ";
    taft.show_lbs();
    incognito = 276.8;          // uses constructor for conversion
    taft = 325;                 // same as taft = Stonewt(325);
    cout << "After dinner, the celebrity weighed ";
    incognito.show_stn();
    cout << "After dinner, the President weighed ";
    taft.show_lbs();
    display(taft, 2);
    cout << "The wrestler weighed even mode.\n";
    display(422, 2);
    cout << "No stone left unearned\n";

// testing conversion functions
    cout << "\nTesting conversion function:\n";
    Stonewt poppins(9, 2.8);    // 9 stone, 2.8 pounds
    double p_wt = poppins;      // implicit conversion
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int(poppins) << " pounds.\n";

// testing overloaded operaotr*()
    cout << "\nTesting overloaded operaotr*():\n";
    Stonewt st1(10.8);
    cout << "st1 = ";
    st1.show_lbs();
    cout << "2 * st1 = ";
    (2 * st1).show_lbs();

    return 0;
}


void display(const Stonewt& st, int n)
{
    for( int i=0; i<n; ++i ){
        cout << "Wow! ";
        st.show_stn();
    }
}
