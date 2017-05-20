// stack.cpp -- chapter 12 pe4 -- class methods definitions
#include "stack.h"
#include <iostream>


bool Stack::push(const Item& item)
{
    if(isfull())
        return false;

    pitems[top++] = item;
    return true;
}

bool Stack::pop(Item& item)
{
    if(isempty())
        return false;

    item = pitems[--top];
    return true;
}

Stack& Stack::operator=(const Stack& st)
{
    if( this == &st )
        return *this;

    if(size < st.size){
        delete[] pitems;
        pitems = new Item[st.size];
        std::cout << "--> stack resized\n";
    }
    for(int i=0; i<st.top; ++i)
        pitems[i] = st.pitems[i];
    top = st.top;
    std::cout << "--> operator=(const Stack& st)\n";
    return *this;
}
