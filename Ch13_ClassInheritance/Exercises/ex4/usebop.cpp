// usebrass2.cpp -- polymorphic example
#include <iostream>
#include <string>
#include "bop.h"


const int OBJECTS = 4;


int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    Port* p_objects[OBJECTS];
    std::string brand;
    int tempnum;
    char kind;

    for(int i=0; i<OBJECTS; ++i){
        cout << "Enter wine brand: ";
        getline(cin, brand);
        cout << "Enter number of bottles: ";
        cin >> tempnum;
        cout << "Enter 1 for Port or 2 for VintagePort\n"
             << ">> ";
        while(cin >> kind && (kind != '1' && kind != '2')){
            while(cin.get() != '\n')
                ;
            cout << "Enter either 1 or 2"
                 << ">> ";
        }
        while(cin.get() != '\n')
            ;
        if( kind == '1' ){
            std::string style;
            cout << "Enter the style: ";
            getline(cin, style);
            p_objects[i] = new Port(brand.c_str(), style.c_str(), tempnum);
        }
        else if( kind == '2' ){
            std::string nickname;
            cout << "Enter the nickname: ";
            getline(cin, nickname);
            std::cout << "Enter the year: ";
            int year;
            cin >> year;
            while(cin.get() != '\n')
                ;
            p_objects[i] = new VintagePort(brand.c_str(), tempnum,
                                           nickname.c_str(), year);
        }

    }
    cout << endl;

    std::cout << "\nCopy the array:\n";
    Port* p_copy[OBJECTS];
    for(int i=0; i<OBJECTS; ++i){
        p_copy[i] = p_objects[i]->clone();
    }
    std::cout << "\nAdd some bottles:\n";
    for(int i=0; i<OBJECTS; ++i){
        *(p_objects[i]) += 5;
        *(p_copy[i]) += (i+1) * 4;
    }
    for(int i=0; i<OBJECTS; ++i){
        std::cout << "Object #" <<i <<": " << *p_objects[i] << '\n'
                  << "Copy #" <<i <<": " << *p_copy[i]
                  << std::endl;
    }
    std::cout << "\nSubtract some bottles:\n";
    for(int i=0; i<OBJECTS; ++i){
        *(p_objects[i]) -= 2;
        *(p_copy[i]) -= (i+1) * 5;
        std::cout << "Object #" <<i <<": " << *p_objects[i] << '\n'
                  << "Copy #" <<i <<": " << *p_copy[i]
                  << std::endl;
    }
    std::cout << "\nShow the inventory:\n";
    for(int i=0; i<OBJECTS; ++i){
        cout << "p_objects["<<i<<"]:\n";
        p_objects[i]->Show();
        cout << "p_copy["<<i<<"]:\n";
        p_copy[i]->Show();
        cout << endl;
    }

    for(int i=0; i<OBJECTS; ++i){
        delete p_objects[i];    // free memory;
        delete p_copy[i];
    }

    cout << "Done.\n";
    return 0;
}
