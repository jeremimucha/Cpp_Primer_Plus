// account.cpp -- chapter 10 pe1 - implementation code
#include <iostream>
#include "account.h"


void Account::display() const
{
    using std::cout;
    cout << "Account holder: " << depositor_
         << ", Account number: " << number_
         << ", Balance: " << balance_
         << std::endl; 
}

double Account::deposit(double amount)
{
    if( 0 < amount )
        balance_ += amount;
    return balance_;
}

double Account::withdraw(double amount)
{
    if( 0 < amount && amount <= balance_ )
        balance_ -= amount;
    return balance_;
}
