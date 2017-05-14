// ex2.cpp
#include <iostream>
#include "person.h"


int main()
{
    Person one;
    Person two("Donger");
    Person three("Bar", "Foo");
    Person persons[] = {one, two, three};
    constexpr int size_persons = sizeof(persons)/sizeof(persons[0]);
    for(int i=0; i<size_persons; ++i){
        persons[i].Show();
        std::cout <<'\t';
        persons[i].FormalShow();
        std::cout << '\n';
    }

    return 0;
}
