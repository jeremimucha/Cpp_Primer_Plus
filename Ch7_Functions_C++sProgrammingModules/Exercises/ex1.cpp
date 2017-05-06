// Ch7 ex1 -- Prompt the user for pairs of numbers. Calculate the harmonic
// mean of the numbers.
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;


struct MyPair
{
    double fst;
    double snd;
};

static inline
istream& operator>>(istream& is, MyPair& p);

static inline
ostream& operator<<(ostream& os, MyPair& p);

double harmonic_mean(MyPair& p);


int main()
{
    cout << "Please enter MyPairs of values in the (x,y) format\n";
    MyPair p;
    string line;
    while( cout << ">> " && getline(cin, line) && !line.empty() ){
        istringstream iss{line};
        if( iss >> p ){
            cout << "Harmonic mean of " << p << " = " << harmonic_mean(p) << '\n';
        }
        else{
            cout << "Invalid input. Please enter (x,y) pairs of doubles. Empty line to quit.\n"
                 << endl;
        }
    }


    return 0;
}


static inline
istream& operator>>(istream& is, MyPair& p)
{
    char ch1, ch2;
    double a, b;

    if( !(is >> ch1) )
        return is;
    if( ch1 != '(' ){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    
    is >> a >> ch1 >> b >> ch2;
    if( !is )
        return is;
    if( ch1 != ',' || ch2 != ')' ){
        is.clear(ios_base::failbit);
        return is;
    }
    p.fst = a;
    p.snd = b;

    return is;
}

static inline
ostream& operator<<(ostream& os, MyPair& p)
{
    return os << '(' << p.fst << ',' << p.snd << ')';
}

double harmonic_mean(MyPair& p)
{
    return 2.0 * p.fst * p.snd / (p.fst + p.snd);
}
