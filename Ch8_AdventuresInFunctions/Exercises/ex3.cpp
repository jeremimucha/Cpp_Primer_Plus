// ex3.cpp -- convert a string to uppercase.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string& str_toupper(string& s);


int main()
{
    string line;
    while( cout << "Enter a string (q to quit): " &&
           getline(cin, line) && line != "q")
    {
        cout << str_toupper(line) << endl;
    }
}


string& str_toupper(string& s)
{
    for(int i=0; i<s.size(); ++i){
        s[i] = toupper(s[i]);
    }
    return s;
}
