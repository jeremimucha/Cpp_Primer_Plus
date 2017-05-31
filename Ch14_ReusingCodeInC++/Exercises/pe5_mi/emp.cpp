// emp.cpp -- Chapter 14 pe5 abstr_emp and children impelentation
#include <iostream>
#include "emp.h"


// abstr_emp
/* ------------------------------------------------------------------------- */
abstr_emp::~abstr_emp()
{
    std::cout << "--> ~abstr_emp()\n";
}

void abstr_emp::ShowAll() const
{
    std::cout << "First Name: " << fname << '\n'
              << "Last Name: " << lname << '\n'
              << "Job: " << job << '\n';
}

void abstr_emp::SetAll()
{
    std::cout << "Enter First Name: ";
    std::cin >> fname;
    std::cout << "Enter Last Name: ";
    std::cin >> lname;
    while(std::cin.get() != '\n')
        ;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
    return os << e.fname << e.lname;
}
/* ------------------------------------------------------------------------- */


// employee
/* ------------------------------------------------------------------------- */
void employee::ShowAll() const
{
    std::cout << "Employee:\n";
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    std::cout << "Enter employee's data:\n";
    abstr_emp::SetAll(); 
}
/* ------------------------------------------------------------------------- */


// manager
/* ------------------------------------------------------------------------- */
void manager::ShowAll() const
{
    std::cout << "Manager:\n";
    abstr_emp::ShowAll();
    std::cout << "In charge of: " << InChargeOf() << " employees." << '\n';
}

void manager::SetAll()
{
    std::cout << "Enter Manager's data:\n";
    abstr_emp::SetAll();
    std::cout << "Enter number of employees managed: ";
    std::cin >> inchargeof;
    while(std::cin.get() != '\n')
        ;
}
/* ------------------------------------------------------------------------- */


// fink
/* ------------------------------------------------------------------------- */
void fink::ShowAll() const
{
    std::cout << "Fink:\n";
    abstr_emp::ShowAll();
    std::cout << "Reports to: " << reportsto << '\n';
}

void fink::SetAll()
{
    std::cout << "Enter Fink's data:\n";
    abstr_emp::SetAll();
    std::cout << "Enter Fink's manager: ";
    std::cin >> reportsto;
    while(std::cin.get() != '\n')
        ;
}
/* ------------------------------------------------------------------------- */


// highfink
/* ------------------------------------------------------------------------- */
void highfink::ShowAll() const
{
    std::cout << "Highfink:\n";
    abstr_emp::ShowAll();
    std::cout << "In charge of: " << manager::InChargeOf() << " employees." << '\n';
    std::cout << "Reports to: " << fink::ReportsTo() << ".\n";
}

void highfink::SetAll()
{
    std::cout << "Enter highfink data:\n";
    abstr_emp::SetAll();
    std::cout << "Enter number of employees highfink's in charge of: ";
    std::cin >> manager::InChargeOf();
    std::cout << "Enter highfink's supervisor: ";
    std::cin >> fink::ReportsTo();
    while(std::cin.get() != '\n')
        ;
}
/* ------------------------------------------------------------------------- */
