// textin3.cpp -- reading chars to end of file
#include <iostream>


int main()
{
    using namespace std;
    char ch;
    int count = 0;
    
    cout << "Enter some characters:\n";
    while( cin.get(ch) && !cin.eof() ){
        cout << ch;
        ++count;
    }
    cout << endl << count << " characters read\n";

    return 0;
}