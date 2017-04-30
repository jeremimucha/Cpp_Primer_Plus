// textin1.cpp -- reading chars with a while loop
#include <iostream>


int main()
{
    using namespace std;

    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    while(cin >> ch && ch != '#'){
        cout << ch;
        ++count;
    }
    cout << endl << count << " characters read\n";

    return 0;
}
