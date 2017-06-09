// ex2.cpp -- Ch17 copy keyboard input to a file named on the cmd
#include <iostream>
#include <fstream>
#include <cstdlib>      // for exit()


int main(int argc, char* argv[])
{
    using namespace std;
    if( argc != 2 ){
        cout << "Usage: " << argv[0] << " output_file\n";
        exit(EXIT_FAILURE);
    }

    cout << "Append keyboard input up to a simulated EOF to the "
         << argv[1] << " file.\n";

    ofstream ofs(argv[1], ios_base::app);
    if(!ofs.is_open()){
        cout << "Could not open " << argv[1] << " file.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Please enter the text to append to the file. Ctrl+Z to stop.\n";
    char ch;
    while(cin.get(ch)){
        ofs << ch << flush;     // flush necessary for MSYS2 bash
    }
    if(cin.fail() && !cin.eof()){
        cout << "Didn't reach EOF.\n";
        exit(EXIT_FAILURE);
    }

    ofs.close();
    return 0;
}
