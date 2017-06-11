// useemp.cpp -- Chapter 17 ex6 using the abstr_emp classes
// testing serializing and deserializing the objects
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "emp.h"
using namespace std;


int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();

    highfink hf(ma, "Curly Kew");   // recruitment?
    hf.ShowAll();

    cout << "Press a key for next phase.\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Using an abstr_emp* pointer:\n";
    abstr_emp* tri[4] = {&em, &fi, &hf, &hf2};
    for(int i=0; i<4; ++i)
        tri[i]->ShowAll();

    cout << "Serializing the data using the abstr_emp* pointer:\n";
    ofstream ofs("emp.dat", ios_base::out | ios_base::binary);
    if(!ofs.is_open()){
        std::cerr << "Failed to open 'emp.dat' for writing.\n";
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<4; ++i){
        tri[i]->writeall(ofs);
    }
    ofs.close();
    cout << "Written all records to emp.dat\n";
    cout << "Deserializing the data using the abstr_emp* pointer:\n";
    ifstream ifs("emp.dat", ios_base::in | ios_base::binary);
    if(!ifs.is_open()){
        std::cerr << "Failed to open 'emp.dat' for reading.\n";
        exit(EXIT_FAILURE);
    }
    vector<abstr_emp*> vpe = abstr_emp::readall(ifs);
    cout << "Read all records from the emp.dat file:\n";
    for( const abstr_emp* pe : vpe ){
        pe->ShowAll();
    }

    return 0;
}
