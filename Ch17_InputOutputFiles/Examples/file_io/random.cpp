// random.cpp -- random access to a binary file
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>


const int LIM = 20;


struct planet
{
    char name[LIM];         // name of planet
    double population;      // its population
    double g;               // its acceleration of gravity
};


const char* file = "planets.dat";       // ASSUMED TO EXIST (binary.cpp example)
inline void eatline() { while(std::cin.get() != '\n'); }


int main()
{
    using namespace std;
    
    planet pl;
    cout << fixed;

// show initial contents
    fstream finout;     // read and write streams
    finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
    int ct = 0;
    if(finout.is_open()){
        finout.seekg(0);    // go to beginning
        cout << "Here are teh current contents of the "
             << file << " file:\n";
        while(finout.read( (char*)&pl, sizeof(pl) )){
            cout << ct++ << ": " << setw(LIM) << pl.name << ": "
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
        }
        if(finout.eof())
            finout.clear();   // allow further file access (edit records later)
        else{
            cerr << "Error in reading " << file << ".\n";
            exit(EXIT_FAILURE);
        }
    }
    else{
        cerr << file << " coul not be opened -- bye.\n";
        exit(EXIT_FAILURE);
    }

// change a record
    cout << "Enter the record number you wish to change: ";
    long rec;
    cin >> rec;
    eatline();
    if(rec < 0 || rec >= ct){
        cerr << "Invalid record number -- bye\n";
        exit(EXIT_FAILURE);
    }
    streampos place = rec * sizeof(pl);
    finout.seekg(place);
    if(finout.fail()){
        cerr << "Error on attempted seek\n";
        exit(EXIT_FAILURE);
    }
    
    finout.read( (char*)&pl, sizeof(pl) );
    cout << "Your selection:\n";
    cout << rec << ": " << setw(LIM) << pl.name << ": "
         << setprecision(0) << setw(12) << pl.population
         << setprecision(2) << setw(6) << pl.g << endl;
    if(finout.eof())
        finout.clear();

    cout << "Enter planet name: ";
    cin.get(pl.name, LIM);
    eatline();
    cout << "Enter planetary popoulation: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration of gravity: ";
    cin >> pl.g;
    finout.seekp(place);    // go back
    finout.write( (char*)&pl, sizeof(pl) ) << flush;
    if(finout.fail()){
        cerr << "Error on attempted write\n";
        exit(EXIT_FAILURE);
    }

// show revised file
    ct = 0;
    finout.seekg(0);
    cout << "Here are the new contents of the " << file
         << " file:\n";
    while(finout.read( (char*)&pl, sizeof(pl) )){
        cout << ct++ << ": " << setw(LIM) << pl.name << ": "
             << setprecision(0) << setw(12) << pl.population
             << setprecision(2) << setw(6) << pl.g << endl;
    }
    finout.close();
    cout << "\nDone.\n";
    return 0;
}
