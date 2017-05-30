// queuetest.cpp -- testing the queuetp template class
#include <iostream>
#include <cstring>
#include "queuetp.h"
#include "workermi.h"



int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    QueueTP<Worker*> lolas;

    while(true)
    {
        char choice;
        const char* msg = "Enter the employee category:\n"
                          "w: waiter           s: singer\n"
                          "t: singing waiter   q: quit\n";
        cout << msg;
        while(cout <<">> " && cin >> choice && strchr("wstq", choice) == NULL){
            cout << "Please enter w, s, t or q\n";
        }
        if(choice == 'q')
            break;
        switch(choice){
            case 'w':
                lolas.push(new Waiter);
                break;
            case 's':
                lolas.push(new Singer);
                break;
            case 't':
                lolas.push(new SingingWaiter);
                break;
        }
        while(cin.get() != '\n')
            ;
        lolas.last()->Set();
    }

    cout << "\nHere is your staff:\n";

    for(QueueTP<Worker*>::const_forward_iterator node=lolas.begin(); node!=lolas.end(); node = node->next){
        cout << endl;
        node->val->Show();
    }

    for(QueueTP<Worker*>::const_forward_iterator node=lolas.begin(); node!=lolas.end(); node = node->next){
        delete node->val;
    }

    cout << "Bye.\n";
    return 0;
}
