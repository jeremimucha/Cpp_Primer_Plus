// ex4.cpp -- Chapter 17 exercise 4 - concatenate two files line by line
#include <iostream>
#include <fstream>
#include <cstdlib>      // for exit()


int main(int argc, char* argv[])
{
    using namespace std;
    if(argc != 4){
        cout << "Usage: " << argv[0] << "fromfile1 fromfile2 tofile\n";
        exit(EXIT_FAILURE);
    }

    ifstream from1(argv[1]);
    if(!from1.is_open()){
        cout << "Can't open " << argv[1] << " for reading. Aborting.\n";
        exit(EXIT_FAILURE);
    }
    ifstream from2(argv[2]);
    if(!from2.is_open()){
        cout << "Can't open " << argv[2] << " for reading. Aborting.\n";
        exit(EXIT_FAILURE);
    }
    ofstream tofile(argv[3]);
    if(!tofile.is_open()){
        cout << "Can't open " << argv[3] << " for writing. Aborting.\n";
        exit(EXIT_FAILURE);
    }

    string line;
    while( getline(from1, line) && tofile << line << " "
        && getline(from2, line) && tofile << line << '\n')
        ;
    while(getline(from1, line))
        tofile << line << '\n';
    while(getline(from2, line))
        tofile << line << '\n';

    from1.close();
    from2.close();
    tofile.close();
    return 0;
}
