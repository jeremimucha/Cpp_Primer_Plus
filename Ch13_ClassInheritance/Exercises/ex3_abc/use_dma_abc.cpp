// usebrass2.cpp -- polymorphic example
#include <iostream>
#include <string>
#include "dma_abc.h"


const int OBJECTS = 4;


int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    DMA_ABC* p_objects[OBJECTS];
    std::string temp;
    int tempnum;
    char kind;

    for(int i=0; i<OBJECTS; ++i){
        cout << "Enter object's label: ";
        getline(cin, temp);
        cout << "Enter object's rating: ";
        cin >> tempnum;
        cout << "Enter 1 for baseDMA, 2 for lacksDMA or 3 for hasDMA\n"
             << ">> ";
        while(cin >> kind && (kind != '1' && kind != '2' && kind != '3')){
            while(cin.get() != '\n')
                ;
            cout << "Enter either 1, 2 or 3"
                 << ">> ";
        }
        while(cin.get() != '\n')
            ;
        if( kind == '1' )
            p_objects[i] = new baseDMA(temp.c_str(), tempnum);
        else if( kind == '2' ){
            std::string color;
            cout << "Enter the color: ";
            getline(cin, color);
            p_objects[i] = new lacksDMA(color.c_str(), temp.c_str(), tempnum);
        }
        else if( kind == '3' ){
            std::string style;
            cout << "Enter the style: ";
            getline(cin, style);
            p_objects[i] = new hasDMA(style.c_str(), temp.c_str(), tempnum);
        }

    }
    cout << endl;

    std::cout << "\nCopy the array:\n";
    DMA_ABC* p_copy[OBJECTS];
    for(int i=0; i<OBJECTS; ++i){
        p_copy[i] = p_objects[i]->clone();
    }
    for(int i=0; i<OBJECTS; ++i){
        cout << "p_objects["<<i<<"]:\n";
        p_objects[i]->View();
        cout << "p_copy["<<i<<"]:\n";
        p_copy[i]->View();
        cout << endl;
    }

    for(int i=0; i<OBJECTS; ++i){
        delete p_objects[i];    // free memory;
        delete p_copy[i];
    }

    cout << "Done.\n";
    return 0;
}
