// review.cpp -- Chapter 10 review 
#include <iostream>
#include <string>


// #5
class Account
{
private:
    std::string depositor_;
    std::string number_;
    double balance_;
public:
    Account()
        :depositor_(0), number_(0), balance_(0.0) { }
    
    Account(std::string depositor, std::string number, double balance=0.0)
        :depositor_(depositor), number_(number), balance_(balance) { }

    void display() const;
    double deposit(double amount);
    double withdraw(double amount);
};

void Account::display() const
{
    using namespace std;
    cout << "Account holder: " << depositor_
         << ", Account number: " << number_
         << ", Balance: " << balance_; 
}

double Account::deposit(double amount)
{
    if( 0 < amount )
        balance += amount;
    return balance_;
}

double Account::withdraw(double amount)
{
    if( 0 < amount && amount <= balance_ )
        balance_ -= amount;
    return balance_;
}


int main()
{

}
