// chartype.cpp -- the char type
#include <iostream>

int main()
{
    using namespace std;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Hola! "
         << "Thank you for the " << ch << " character."
         << endl;

    return 0;
}
