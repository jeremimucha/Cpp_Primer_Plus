// ex1.cpp -- Read input from stdin up to '@'. Echo input, converted to
// uppercase, except for digits.
#include <iostream>
#include <cctype>
using namespace std;


#define SWAP_CASE(C)    ((C) = isupper((C)) ? tolower((C)) : toupper((C)))


static inline void swap_case(char& ch);


int main()
{
    char ch;
    while( cin.get(ch) && ch != '@' ){
        if( isalpha(ch) ){
            SWAP_CASE(ch);
        }
        if( !isdigit(ch) ){
            cout << ch;
        }
    }
}


static inline void swap_case(char& ch)
{
    isupper(ch) ? tolower(ch)
                : toupper(ch);
}
