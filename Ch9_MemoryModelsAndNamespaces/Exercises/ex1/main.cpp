// main.cpp -- a file utilizing the golf structure and functions
#include <iostream>
#include "golf.h"


constexpr int SIZE = 5;


int main()
{
    golf golfers[5];
    const char* name_good = "Foo Bar";
    const char* name_toolong = "This is a way too long name for the golf structure";
    const char* names[] = {name_good, name_toolong};
    constexpr int size_names = sizeof(names)/sizeof(names[0]);
    int i=0;
    for(; i<size_names; ++i){
        setgolf(golfers[i], names[i], (i+11+i*7));
    }
    for(; i<SIZE; ++i){
        setgolf(golfers[i]);
    }
    handicap(golfers[3], 444);

    for(int i=0; i<SIZE; ++i){
        showgolf(golfers[i]);
    }
    
    return 0;
}
