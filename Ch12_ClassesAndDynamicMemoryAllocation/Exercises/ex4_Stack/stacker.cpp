// stacker.cpp -- testing the Stack class
#include <iostream>
#include <cctype>
#include "stack.h"


int main()
{
    using namespace std;
    Stack st;   // create an empty stack
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while(cin >> ch && toupper(ch) != 'Q'){
        while(cin.get() != '\n')
            continue;
        if(!isalpha(ch)){
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if(st.isfull()){
                    cout << "stack already full\n";
                }
                else{
                    st.push(po);
                }
                break;
            case 'P':
            case 'p':
                if(st.isempty()){
                    cout << "stack already empty\n";
                }
                else{
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                }
                break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    Stack st2(st);
    Stack st3(20);
    Stack st4(6);
    for(unsigned long i=123; !st2.isfull(); ++i){
        st2.push(i);
    }
    st3 = st2;
    st4 = st2;
    for(unsigned long i=234; !st3.isfull(); ++i)
        st3.push(i);
    std::cout << "Stack1:\n";
    Item it;
    while(st.pop(it)){
        std::cout << "  " << it << '\n';
    }
    std::cout << "Stack2:\n";
    while(st2.pop(it)){
        std::cout << "  " << it << '\n';
    }
    std::cout << "Stack3:\n";
    while(st3.pop(it)){
        std::cout << "  " << it << '\n';
    }
    std::cout << "Stack4\n";
    while(st4.pop(it)){
        std::cout << "  " << it << '\n';
    }

    cout << "Bye\n";
    return 0;
}
