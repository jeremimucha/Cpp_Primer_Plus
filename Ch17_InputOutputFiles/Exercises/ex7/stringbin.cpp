// stringbin.cpp -- Chapter 17 exercise 7 -- store a vector of strings in a 
// binary file and restore the vector of strings from the file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>


class Store
{
private:
    std::ofstream& ofs;
public:
    Store(std::ofstream& os)
        : ofs(os) { }
    void operator()(const std::string& s);
};

void Store::operator()(const std::string& s)
{
    std::size_t len = s.size();
    ofs.write( (char*)&len, sizeof(len));
    ofs.write( s.data(), len );
}


void ShowStr(const std::string& s);
void GetStrs(std::ifstream& ifs, std::vector<std::string>& vect);


int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    std::size_t BLA;
    cout << "sizeof(std::size_t) = " << sizeof(std::size_t) << "\n"
         << "sizeof(BLA) = " << sizeof(BLA)
         << endl;

// acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while(getline(cin,temp) && !temp.empty()){
        vostr.push_back(temp);
    }
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(),  ShowStr);

// store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

// recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if(!fin.is_open()){
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nNumber of records in vistr: " << vistr.size();
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}


void ShowStr(const std::string& s)
{
    std::cout << s << '\n';
}


void GetStrs(std::ifstream& ifs, std::vector<std::string>& vect)
{
    while(true){
        std::size_t len;
        ifs.read( (char*)&len, sizeof(len));
        if(ifs.eof())
            break;
        char buf[len+1];
        ifs.read( buf, len );
        if(ifs.fail()){
            std::cerr << "Failed to retrieve string from file.\n";
            exit(EXIT_FAILURE);
        }
        buf[len] = '\0';
        vect.push_back(std::string(buf));
    }
    if(ifs.fail() && !ifs.eof()){
        std::cerr << "Error while retrieving data from the file.\n";
        exit(EXIT_FAILURE);
    }
}