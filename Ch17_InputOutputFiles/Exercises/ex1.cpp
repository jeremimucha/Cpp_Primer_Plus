// ex1.cpp -- Chapter 17 exercise 1 - count chars up to first '$'
// leave '$' in the input stream
#include <iostream>



int main()
{
    using namespace std;
    int ct{0};
    char ch;
    while(cin.get(ch) && ch != '$')
        ++ct;
    if( cin && ch == '$' )
        cin.putback(ch);
    else{
        cout << "Didn't find a '$' character in the stream.\n";
        cin.clear();
        return 1;
    }
    cout << "Number of characters up to '$': " << ct << "\nDone.\n";
}
