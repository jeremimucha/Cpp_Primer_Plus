// ex3.cpp -- Chpater 17 exercise 2 - copy one file to another, named on the cmd
#include <iostream>
#include <fstream>
#include <cstdlib>


inline bool file_exists(const char* fname)
{

    std::ifstream ifs(fname);
    return ifs.is_open();
}


int main(int argc, char* argv[])
{
    using namespace std;
    if( argc < 3 ){
        cout << "Usage: " << argv[0] << "from_file to_file [1-truncate existing]\n";
        exit(EXIT_FAILURE);
    }

    ifstream fromfile(argv[1], ios_base::in | ios_base::binary);
    if(!fromfile.is_open()){
        cout << "Could not open the " << argv[1] << " file. Aborting.\n";
        exit(EXIT_FAILURE);
    }
    ofstream tofile;
    if( argc < 4 || (argc==4 && argv[3][0] != '1')){
        if(file_exists(argv[2])){
            cout << argv[2] << " file already exists. Aborting.\n";
            exit(EXIT_FAILURE);
        }
    }
    tofile.open(argv[2], ios_base::out | ios_base::binary);
    if(!tofile.is_open()){
        cout << "Could not open the " << argv[2] << " file for output. Aborting.\n";
        exit(EXIT_FAILURE);
    }

    tofile << fromfile.rdbuf();

    fromfile.close();
    tofile.close();
    cout << "\nDone.\n";
    return 0;
}
