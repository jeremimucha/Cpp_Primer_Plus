// strtype1.cpp -- using the C++ string class
#include <iostream>
#include <string>


int main()
{
    using namespace std;
    constexpr unsigned int SIZE = 20;
    char charr1[SIZE];
    char charr2[SIZE] = "jaguar";
    string str1;
    string str2 = "panther";

    cout << "Enter a kind of feline";
    cin >> charr1;
    cout << "Enter another kind of fealine: ";
    cin >> str1;
    cout << "Here are some felines:\n"
         << charr1 << " " << charr2 << " "
         << str1 << " " << str2
         << endl;
    cout << "The third lether in " << charr2 << " is "
         << charr2[2]
         << endl;
    cout << "The thid letter in " << str2 << " is "
         << str2[2]
         << endl;

    return 0;
}
