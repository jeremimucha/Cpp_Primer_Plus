// pointer.cpp -- our first pointer variable
#include <iostream>


int main()
{
    using namespace std;

    int updates = 6;
    int* p_updates = &updates;

    // express values two ways
    cout << "Values: updates = " << updates
         << ", *p_updates = " << *p_updates
         << endl;

    // express address two ways
    cout << "Addresses: &updates = " << &updates
         << ", p_updates = " << p_updates
         << endl;

    // use pointer to change value
    *p_updates = ++*p_updates;
    cout << "Now updates = " << updates
         << endl;

    return 0;
}
