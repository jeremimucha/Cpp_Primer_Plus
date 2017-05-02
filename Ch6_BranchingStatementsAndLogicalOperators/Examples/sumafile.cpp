// sumafile.cpp -- functions with an array argument
#include <iostream>
#include <fstream>
#include <cstdlib>


constexpr int SIZE = 60;


int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream infile;
    
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    infile.open(filename);
    if( !infile.is_open() ){
        cout << "Could not open the file " << filename
             << "\nProgram terminating."
             << endl;
        exit(EXIT_FAILURE);
    }
    
    double value;
    double sum = 0.0;
    int count = 0;

    while( infile >> value && infile.good() ){
        ++count;
        sum += value;
    }
    if(infile.eof())
        cout << "End of file reached.\n";
    else if(infile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    if(count == 0)
        cout << "No data processed.\n";
    else{
        cout << "Items read: " << count
             << "\nSum: " << sum
             << "\nAverage: " << sum / count
             << endl;
    }
    infile.close();
    return 0;
}
