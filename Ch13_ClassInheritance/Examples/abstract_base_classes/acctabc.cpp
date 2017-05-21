// acctabc -- bank account class methods
#include <iostream>
#include "acctabc.h"
using std::cout;
using std::ios_base;
using std::endl;
using std::string;


// Abstract Base Class
void AcctABC::Deposit(double amt)
{
    if(amt < 0){
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled.\n";
    }
    else{
        balance += amt;
    }
}

void AcctABC::Withdraw(double amt)
{
    cout << "-> AcctABC::Withdraw(double)\n";
    balance -= amt;
}

// protected methods for formatting
AcctABC::Formatting AcctABC::SetFormat() const
{
// set up ###.## format
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting& f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

// Brass methods
void Brass::Withdraw(double amt)
{
    cout << "-> Brass::Withdraw(double)\n";
    if(amt < 0){
        cout << "Withdrawal amount must be positive; "
             << "withdrawal canceled.\n";
    }
    else if(amt <= Balance()){
        AcctABC::Withdraw(amt);
    }
    else{
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal canceled.\n";
    }
}

void Brass::ViewAcct() const
{
    cout << "-> Brass::ViewAcct()\n";
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    Restore(f);
}


// BrassPlus Methods
void BrassPlus::ViewAcct() const
{
    cout << "-> BrassPlus::ViewAcct()\n";
    Formatting f = SetFormat();
    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    cout << "-> BrassPlus::Withdraw(double)\n";
    Formatting f = SetFormat();
    
    double bal = Balance();
    if(amt > 0 && amt <= bal){
        AcctABC::Withdraw(amt);
    }
    else if ((amt > 0) && (amt <= bal + maxLoan - owesBank) ){
        double advance = amt - bal;
        owesBank += advance *= (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else{
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    Restore(f);
}
