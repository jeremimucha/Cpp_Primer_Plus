// winec.cpp -- Chapter 14 Wine class using containment -- implementation
#include "winec.h"
#include <sstream>


void Wine::GetBottles()
{
    using std::cout; using std::cin;

    ArrayInt& pyrs = yrbtl.fst();
    ArrayInt& pbot = yrbtl.snd();
    std::ostringstream oss;
    oss << "Enter " << label << " data for " << nyears << " years(s):\n";
    cout << oss.str();
    for(int i=0; i<nyears; ++i){
        oss.clear();
        oss.str("");
        oss << "Enter year #" << (i+1) << ": ";
        std::string prompt(oss.str());
        while(cout << prompt && !(cin >> pyrs[i])){
            cout << "Invalid input. Please enter an int.\n";
            cin.clear();
            while(cin.get() != '\n')
                ;
        }
        while(cin.get() != '\n')
            ;
        oss.clear();
        oss.str("");
        oss << "Enter bottles for year " << pyrs[i] << ": "; 
        prompt = oss.str();
        while(cout << prompt && !(cin >> pbot[i])){
            cout << "Invalid input. Please enter an int.\n";
            cin.clear();
            while(cin.get() != '\n')
                ;
        }
        while(cin.get() != '\n')
            ;
    }
}

void Wine::Show() const
{
    using std::cout; using std::endl;
    cout << "Wine: " << label << '\n';
    cout << "\tYear\tBottles\n";
    for(int i=0; i<nyears; ++i){
        cout << '\t' << yrbtl.fst()[i]
             << '\t' << yrbtl.snd()[i]
             << '\n'; 
    }
}

int Wine::sum() const
{
    int total{0};
    for(int i=0; i<nyears; ++i)
        total += yrbtl.snd()[i];

    return total;
}
