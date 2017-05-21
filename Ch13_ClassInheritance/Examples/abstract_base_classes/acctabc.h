// acctabc.h -- bank account classes
#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>
using std::cout; using std::endl;

// Abstract Base Class
class AcctABC
{
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string& FullName() const
        { return fullName; }
    long AcctNum() const
        { return acctNum; }
    Formatting SetFormat() const;
    void Restore(Formatting& f) const;
public:
    AcctABC(const std::string& s="Nullbody", long an=-1, double bal=0.0)
        : fullName(s), acctNum(an), balance(bal)
        { cout << "--> AcctABC::AcctABC() constructor\n"; }
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0;  // pure virtual function
    double Balance() const
        { return balance; }
    virtual void ViewAcct() const = 0;      // pure virtual function
    virtual ~AcctABC() { cout << "--> AcctABC::~AcctABC()\n"; }
};


// Brass Account Class
class Brass : public AcctABC
{
public:
    Brass(const std::string& s="Nullbody", long an=-1, double bal=0.0)
        : AcctABC(s, an, bal)
        { cout << "--> Brass::Brass() constructor\n"; }
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass() { cout << "--> Brass::~Brass()\n"; }
};

// BrassPlus Account Class
class BrassPlus : public AcctABC
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string& s = "Nullbody", long an=-1, double bal=0.0,
              double ml=500, double r=0.10)
        : AcctABC(s, an, bal), maxLoan(ml), rate(r), owesBank(0)
        { cout << "--> BrassPlus::BrassPlus() constructor\n"; }
    BrassPlus(const Brass& ba, double ml=500, double r=0.10)
        : AcctABC(ba), maxLoan(ml), rate(r), owesBank(0.0)  // uses imlicit copy constructor
        { }
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m)
        { maxLoan = m; }
    void ResetRate(double r)
        { rate = r; }
    void ResetOwes()
        { owesBank = 0; }
    virtual ~BrassPlus() { cout << "--> BrassPlus::~BrassPlus()\n"; }
};

#endif /*ACCTABC_H_*/
