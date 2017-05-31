// workmi.cpp -- multiple inheritance
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "personmi.h"


const int SIZE = 5;


int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    // seed random number generator for PokerPlayer and Card classes
    std::srand(std::time(nullptr));

    Person* lolas[SIZE];

    int ct;
    for(ct=0; ct<SIZE; ++ct){
        char choice;
        cout << "Enter the person category:\n"
             << "g: gunslinger  p: poker player  "
             << "b: bad dude q: quit\n";
        while(cin >> choice && strchr("gpbq", choice) == NULL){
            cout << "Please enter a w, s, t or q: ";
        }
        if(choice == 'q')
            break;
        switch(choice){
            case 'g':
                lolas[ct] = new Gunslinger;
                break;
            case 'p':
                lolas[ct] = new PokerPlayer;
                break;
            case 'b':
                lolas[ct] = new BadDude;
                break;
        }
        while(cin.get() != '\n')
            ;
        lolas[ct]->Set();
    }

    cout << "\nHere is your gang:\n";
    
    int i;
    for(i=0; i <ct; ++i){
        cout << endl;
        lolas[i]->Show();
    }
    for(i=0; i<ct; ++i)
        delete lolas[i];
    
    cout << "Bye.\n";

    return 0;
}
