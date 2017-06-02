// str1.cpp -- introducing the string class
#include <iostream>
#include <string>


int main()
{
    using namespace std;
    // string(const char*);
    string one("Lottery Winner!");  
    cout << one << endl;
    // string(size_type, char);
    string two(20, '$');
    cout << two << endl;
    // string(const string&);
    string three(one);              
    cout << three << endl;
    one += "Oops!";
    cout << one << endl;
    two = "Sorry! That was ";
    three[0] = 'P';
    // string()
    string four;
    // string& operator=(const string&); string operator+(const string&, const string&);
    four = two + three;
    cout << four << endl;
    char alls[] = "All's well that ends well";
    // string(const char*, size_type);
    string five(alls, 20);
    cout << five << "!\n";
    // string(Iter, Iter);
    string six(alls+6, alls+10);
    cout << six << ", ";
    // string(Iter, Iter);
    string seven(&five[6], &five[10]);
    cout << seven << "...\n";
    // string(const string&, size_type, size_type);
    string eight(four, 7, 16);
    cout << eight << " in motion! " << endl;
    return 0;
}
