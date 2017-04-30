// textin2.cpp -- using cin.get(char)
#include <iostream>


int main()
{
    using namespace std;
    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";
    while( cin.get(ch) && ch != '#' ){
        cout << ch;
        ++count;
    }
    cout << endl << count << " characters read\n";

    return 0;
}