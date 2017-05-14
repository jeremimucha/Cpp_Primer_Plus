// account.h -- chapter 10 pe1
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <iostream>
#include <string>
using std::cout;

class Account
{
private:
    std::string depositor_;
    std::string number_;
    double balance_;
public:
    Account()
        :depositor_(""), number_(""), balance_(0.0) 
        { cout << "Default Account\n"; }
    
    Account(std::string depositor, std::string number, double balance=0.0)
        :depositor_(depositor), number_(number), balance_(balance)
        { cout << "Account(" << depositor<<','<<number<<','<<balance<<")\n"; }

    ~Account() { cout << "~Account("<<depositor_ <<")\n"; }

    void display() const;
    double deposit(double amount);
    double withdraw(double amount);
};


#endif /* ACCOUNT_H_ */
