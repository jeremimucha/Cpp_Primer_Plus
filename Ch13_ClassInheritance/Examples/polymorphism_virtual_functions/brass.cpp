// brass.cpp - bank account class methods
#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;


// formatting stuf
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);


// Brass methods

void Brass::Deposit(double amt)
{
    if(amt<0){
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled.\n";
    }
    else
        balance += amt;
}

void Brass::Withdraw(double amt)
{
    cout << "-> Brass::Withdraw(double) called\n";
    // set up ##.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if(amt < 0){
        cout << "Withdrawal amount must be positive; "
             << "withdrawal canceled.\n";
    }
    else if(amt <= balance){
        balance -= amt;
    }
    else{
        cout << "Withdrawal amount $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal canceled.\n";
    }
    restore(initialState, prec);
}

void Brass::ViewAcct() const
{
    cout << "-> Brass::ViewAcct() called\n";
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);    // restore original format
}


// BrassPlus Methods

// redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
    cout << "-> BrassPlus::ViewAcct() called\n";
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct(); // display base portion
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);  // ###.## format
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialState, prec);
}

// redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{
    cout << "-> BrassPlus::Withdraw(double) called\n";
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if(amt <= bal)
        Brass::Withdraw(amt);
    else if(amt <= bal + maxLoan - owesBank){
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else{
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    restore(initialState, prec);
}


format setFormat()
{
    // set up ###.## format
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}
