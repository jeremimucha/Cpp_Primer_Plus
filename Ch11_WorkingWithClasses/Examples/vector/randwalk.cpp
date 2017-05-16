// randwalk.cpp -- using the Vector class
#include <iostream>
#include <cstdlib>      // rand(), srand(), prototypes
#include <ctime>        // time() prototype
#include <cctype>
#include "vect.h"
#include <string>
#include <sstream>
#include <fstream>


int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // seed random number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    ofstream fout;
    cout << "Would you like to save the random walk to a file (y/n)?\n";
    char ch;
    for(
       ; cout<<">> " && (cin >> ch) && (ch=tolower(ch)) != 'y' && ch != 'n'
       ; cout<<"Plese answer \"Yes\" or \"No\"\n"){
        while( cin.get() != '\n' )
            ;
    }
    while( cin.get() != '\n' )
        ;
    if( ch == 'y' ){
        string fname;
        cout << "Please enter the file name\n>> ";
        getline(cin, fname);
        fout.open(fname);
        if( !fout.is_open() ){
            cerr << "\nCould not open the file " << fname
                 << ".\nTerminating.";
            exit(EXIT_FAILURE);
        }
    }
    
    const char* prompt = "Enter target distance (q to quit): ";
    std::string line;
    while(cout << prompt
          && std::getline(cin, line)
          && line != "q" && line != "Q")
    {
        istringstream iss{line};
        if( !(iss >> target) ){
            cout << "Invalid input. Target distance should be type double.\n";
            continue;
        }
        cout << "Enter step length: ";
        if( !(cin >> dstep) )
            break;
        while(cin.get() != '\n' )
            ;

        if( fout.is_open() ){
            fout << "Target distance: " << target
                 << " Step Size: " << dstep
                 << "\n";
         }

        while(result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            if(fout.is_open()){
                fout << steps <<';' << result << '\n';
            }
            ++steps;
        }
        cout << "After " << steps << " steps, the subject has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = " 
             << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
    }

    cout << "Bye!\n";
    cin.clear();
    while(cin.get() != '\n')
        ;
    return 0;
}
