// cow.cpp - chapter 12 pe1 -- implementation code for Cow class
#include <iostream>
#include <cstring>
#include "cow.h"
using std::cout;

int Cow::count = 0;

Cow::Cow(const char* nm, const char* ho, double wt)
    :hobby(new char[std::strlen(ho) + 1]), weight(wt)
{
    int i{0};
    for(; i<19 && nm[i]; ++i){
        name[i] = nm[i];
    }
    for(; i<20; ++i)
        name[i] = '\0';

    std::strcpy(hobby, ho);
    ++count;
    cout << "Cow(const char*, const char*, double) constructor called. Count: " << count <<'\n';;
}

Cow::Cow(const Cow& c)
    :hobby(new char[std::strlen(c.hobby) + 1]), weight(c.weight)
{
    std::strncpy(name, c.name, 20);
    std::strcpy(hobby, c.hobby);
    ++count;
    cout << "Cow(const Cow&) copy constructor called. Count: " << count <<'\n';
}

Cow::~Cow()
{
    delete[] hobby;
    --count;
    cout << "~Cow() destructor called. Count: " << count <<'\n';
}

Cow& Cow::operator=(const Cow& c)
{
    if( this == &c )
        return *this;
    std::strncpy(name, c.name, 20);
    delete[] hobby;
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
    cout << "operator=(const Cow& c) copy assignment called. Count: " << count <<'\n';
    return *this;
}

void Cow::ShowCow() const
{
    cout << name << ", weight: " << weight << ", hobby: " << hobby;
}
