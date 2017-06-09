// format2.cpp -- formating output
#include <iostream>
#include <iomanip>
#include <cstring>


struct CorpoRat
{
    char* name;
    double hwage;
    double worktime;
    CorpoRat(const char* n, double wage, double worked)
        : name(new char[std::strlen(n) + 1])
        , hwage(wage)
        , worktime(worked)
        { std::strcpy(name, n); }
    ~CorpoRat() { delete[] name; }

    void show1() const;
    void show2() const;
// friends
    friend std::ostream& operator<<(std::ostream& os, const CorpoRat& r);
};


inline void eatline() { while(std::cin.get() != '\n') ; }


int main()
{
    using namespace std;
    const int NLEN = 20;
    char name[NLEN];
    cout << "Enter name: ";
    cin.get(name, NLEN);
    if(cin.peek() != '\n'){
        cout << "Sorry, name trunkated to: " << name <<'\n';
    }
    eatline();
    
    double wages;
    while(cout << "Enter hourly wages: " && !(cin >> wages) ){
        cout << "Invalid format, please enter a double value.\n";
        cin.clear();
        eatline();
    }

    double worktime;
    while(cout << "Enter number of hours worked: " && !(cin >> worktime) ){
        cout << "Invalid format, please enter a double value.\n";
        cin.clear();
        eatline();
    }

    CorpoRat dude(name, wages, worktime);
    dude.show1();
    cout << endl;
    dude.show2();
    cout << endl;
    cout << dude;
}


void CorpoRat::show1() const
{
    std::cout << std::right << std::fixed;
    std::cout << std::setw(30) << name << ": "
              << "$" << std::setw(7) << std::setprecision(2) << hwage << ":"
              << std::setw(5) << std::setprecision(1) << worktime;
}

void CorpoRat::show2() const
{
    std::ios_base::fmtflags old = std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << std::setw(30) << name << ": "
              << "$" << std::setw(7) << std::setprecision(2) << hwage << ":"
              << std::setw(5) << std::setprecision(1) << worktime;
    std::cout.setf(old);
}


std::ostream& operator<<(std::ostream& os, const CorpoRat& r)
{
    return os << r.name
              << " $" << std::setprecision(2) << r.hwage
              << ", " << std::setprecision(2) << r.worktime;
}
