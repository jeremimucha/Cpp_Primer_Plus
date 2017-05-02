// outfile.cpp -- writing to a file
#include <iostream>
#include <fstream>


int main()
{
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outfile;
    outfile.open("carinfo.txt");

    cout << "Enter the make and model of automibile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    // display information on scrren with cout
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and maodel: " << automobile
         << "\nYear: " << year
         << "\nWas asking $" << a_price
         << "\nNow asking $" << d_price
         << endl;

    // now do exact same thigs using outfile
    outfile << fixed;
    outfile.precision(2);
    outfile.setf(ios_base::showpoint);
    outfile << "Make and maodel: " << automobile
            << "\nYear: " << year
            << "\nWas asking $" << a_price
            << "\nNow asking $" << d_price
            << endl;
    outfile.close();

    return 0;
}