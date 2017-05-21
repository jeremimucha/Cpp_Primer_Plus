// brass.h -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>
#include <iostream>
using std::cout;

// Brass Account Class
class Brass
{
private:
    std::string fullName;
    long acctNum;
    double balance;
public:
    Brass(const std::string& s="Nullbody", long an=-1, double bal=0.0)
        :fullName(s), acctNum(an), balance(bal)
        { cout << "--> Brass(const string&, long, double) called\n"; }
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const
        { return balance; }
    virtual void ViewAcct() const;
    virtual ~Brass() {cout << "--> ~Brass() called\n"; }
};


// Brass Pluss Account Class
class BrassPlus : public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string& s="Nullbody", long an=-1,
              double bal=0.0, double ml=500, double r=0.11125)
        :Brass(s, an, bal), maxLoan(ml), rate(r), owesBank(0.0)
        { cout << "--> BrassPlus(const string&, long, double, double, double) called \n"; }
    BrassPlus(const Brass& ba, double ml, double r)
        :Brass(ba), maxLoan(ml), rate(r), owesBank(0.0)
        { cout << "--> BrassPlux(const Brass&, double, double) called\n"; }
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
    // virtual ~Brass()
    // {
    //     cout << "--> BrassPlus::~Brass() called\n";
    //     Brass::~Brass();
    // }
};


#endif /* BRASS_H_ */
