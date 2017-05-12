// golf.cpp -- implementation code for golf.h
#include <iostream>
#include <string>
#include "golf.h"


void setgolf(golf& g, const char* name, int hc)
{
    for(int i=0; i<LEN && name[i]; ++i){
        g.fullname[i] = name[i];
    }
    g.handicap = hc;
}


int setgolf(golf& g)
{
    using namespace std;
    char name[LEN];
    int hc;

    cout << "Please enter the full name of the golfer.\n";
    while( cout<<">> " && cin.getline(name, LEN).fail() && name[0] ){
        cout << "Please enter a name up to 40 characters long.\n";
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
    
    // set the fullname
    int i{0};
    for(; i<LEN && name[i]; ++i){
        g.fullname[i] = name[i];
    }
    // set the handicap
    g.handicap = hc;

    return i;
}

void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf& g)
{
    std::cout << "Name: " << g.fullname
              << ", Handicap: " << g.handicap
              << std::endl;
}
