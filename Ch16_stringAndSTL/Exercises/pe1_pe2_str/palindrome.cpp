// palindrome.cpp -- Chapter 16 pe 1 - check if a string is a palindrome
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


bool is_palindrome(const string& s);
bool is_palindrome_2(const string& s);
bool is_palindrome_3(const string& s);


int main()
{
    cout << "Enter strings to find out if they're palindromes.\n"
         << "Enter 'quit' to quit.\n";
    string word;
    while(cout << ">> " && cin >> word && word != "quit"){
        cout << "1: " << word << (is_palindrome(word)   ?
                                    " IS  palindrome."  :
                                    " NOT palindrome.");
        cout << "\n2: " << word << (is_palindrome_2(word) ?
                                   " IS  palindrome."     :
                                   " NOT palindrome.");
        cout << "\n3: " << word << (is_palindrome_3(word) ?
                                   " IS  palindrome."     :
                                   " NOT palindrome."); 
        cout << endl;
    }

    return 0;
}


bool is_palindrome(const string& s)
{
    string::const_iterator fi = s.begin();
    string::const_iterator fiend = s.begin() + s.size() / 2;
    string::const_reverse_iterator ri = s.rbegin();
    while(fi < fiend && tolower(*fi) == tolower(*ri)){
        ++fi; ++ri;
    }
    return fi == fiend;
}

bool is_palindrome_2(const string& s)
{
    string::size_type b = 0;
    string::size_type e = s.size() - 1;
    for(; b < s.size() / 2 && tolower(s[b]) == tolower(s[e]); ++b, --e)
        ;
    return e <= b;
}

bool is_palindrome_3(const string& s)
{
    const char* b = &s[0];
    const char* e = &s[s.size()] - 1;
    while( b < e && tolower(*b) == tolower(*e)){
        ++b; --e;
    }
    return e <= b;
}
