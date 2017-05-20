// stack.h -- class declaration for the stack ADT
#ifndef STACK_H_
#define STACK_H_


#include <iostream>
using std::cout;


typedef unsigned long Item;


class Stack
{
private:
    enum {MAX = 10};
    Item* pitems;   // holds stack items
    int size;       // number of elements in stack
    int top;        // index for top stack item
public:
    Stack(int n=MAX)
        :pitems(new Item[n]), size(n), top(0)
        { cout << "--> Stack(int n)\n"; }
    Stack(const Stack& st)
        :pitems(new Item[st.size]), size(st.size), top(st.top)
        { 
            for(int i=0; i<st.top; ++i) pitems[i] = st.pitems[i];
            cout << "--> Stack(const Stack& st)\n";
        }
    ~Stack()
        { delete[] pitems; cout << "--> ~Stack()\n"; }
    bool isempty() const
        { return top == 0; }
    bool isfull() const
        { return top == size; }
    // push() returns false if stack already is full, true otherwise
    bool push(const Item& item);
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item& item);
    Stack& operator=(const Stack& st);
};


#endif /* STACK_H_ */
