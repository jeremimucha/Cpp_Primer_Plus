// format.cpp -- formatting output
#include <iostream>
#include <iomanip>


int main()
{
    using std::cin; using std::cout;

    cout << "Enter an integer: ";
    int num;
    cin >> num;
    while(cin.get() != '\n')
        ;
    
    cout << "Your number:\n";
    cout << std::showbase;
    // cout << std::noshowbase;
    cout << std::setw(15) << num << ':'
         << std::setw(15) << std::hex << num << ':'
         << std::setw(15) << std::oct << num << ':'
         << std::endl;

    return 0;
}
