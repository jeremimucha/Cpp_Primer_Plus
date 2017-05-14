// golf.cpp -- chapter 10 pe3 - implementation
#include <iostream>
#include "golf.h"

Golf::Golf(bool interactive)
{
    std::cout << "Called Golf(" << interactive << ")\n";
    if(!interactive){
        fullname[0] = '\0';
        handicap = 0;
    }
    else{
        using std::cout; using std::cin;
        char name[LEN];
        int hc;
        cout << "Please enter the full name of the golfer.\n";
        // cin.getline(arr, N) reads up to N-1 characters, discards the \n;
        // if \n isn't found in the N chars read it sets the .fail() bit
        // .fail() is set also if the first character read is the \n char
        // check the name[0] to allow empty name member field;
        while( cout<<">> " && cin.getline(name, LEN).fail() && name[0] ){
            cout << "Please enter a name up to " << LEN << " characters long.\n";
            cin.clear();
            while( cin.get() != '\n' )
                ;
        }
        if( cin.eof() )
            cin.clear();

        cout << "Please enter the handicap.\n";
        while( cout<<">> " && !(cin >> hc) ){
            cout << "Please enter an integer value for the handicap.\n";
            cin.clear();
            while( cin.get() != '\n' )
                ;
        }
        while( cin.get() != '\n' )
            ;

        *this = Golf(name, hc);
    }
}

void Golf::show() const
{
    std::cout << "Name: " << fullname
              << ", Handicap: " << handicap;
}
