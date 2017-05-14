// ex1.cpp -- chapter 10 pe1, code using the account class
#include <iostream>
#include "account.h"


const int SIZE = 5;
const char* names[SIZE] = {"Foo", "Bar", "Don", "Ger", "Bob"};
const char* numbers[SIZE] = {"12345", "23456", "34567", "45678", "56789"};


int main()
{
    Account accounts[SIZE]; // default constructor
    for(int i=0; i<SIZE; ++i){
        accounts[i] = Account(names[i], numbers[i], (1234) / ((i+1)*3.14));
    }
    std::cout << "Accounts:\n";
    for(int i=0; i<SIZE; ++i)
        accounts[i].display();
    for(int i=0; i<SIZE; ++i){
        accounts[i].deposit(42.11);
    }
    std::cout << "\nAccounts after deposit:\n";
    for(int i=0; i<SIZE; ++i){
        accounts[i].display();
    }
    for(int i=0; i<SIZE; ++i)
        accounts[i].withdraw(130);
    std::cout << "\nAccounts after withdrawal:\n";
    for(int i=0; i<SIZE; ++i)
        accounts[i].display();

    return 0;
}
