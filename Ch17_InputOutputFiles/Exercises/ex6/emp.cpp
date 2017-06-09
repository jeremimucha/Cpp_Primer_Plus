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

void abstr_emp::serialize(std::ofstream& ofs) const
{
    std::size_t len;
    // std::string& members[] = {fname, lname, job};
    for( const std::string* s : { &fname, &lname, &job }){
        len = s->size();
        ofs.write( (char*)&len, sizeof(len) );
        ofs.write( s->data(), len );
    }
}

void abstr_emp::writeall(std::ofstream& ofs) const
{
    ofs.write( (char*)&Abstr_emp, sizeof(Abstr_emp) );
    serialize(ofs);
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
    return os << e.fname << e.lname;
}

abstr_emp* abstr_emp::readall(std::ifstream& ifs) const
{
    decltype(Abstr_emp) classkind;
    ifs.read( (char*)&classkind, sizeof(classkind) );
    switch(classkind){
        case Abstr_emp:
        case Employee:
            return employee::readall(ifs);
            break;
        case Manager:
            return manager::readall(ifs);
            break;
        case Fink:
            return fink::readall(ifs);
            break;
        case Highfink:
            return highfink::readall(ifs);
            break;
        default:
            return nullptr;
    }
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

void employee::writeall(std::ofstream& ofs) const
{
    ofs.write( (char*)&abstr_emp::Employee, sizeof(abstr_emp::Employee) );
    abstr_emp::serialize(ofs);
    serialize(ofs);
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

void manager::serialize(std::ofstream& ofs) const
{
    ofs.write( (char*)&inchargeof, sizeof(inchargeof) );
}

void manager::writeall(std::ofstream& ofs) const
{
    ofs.write( (char*)&abstr_emp::Manager, sizeof(abstr_emp::Manager) );
    abstr_emp::serialize(ofs);
    serialize(ofs);
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

void fink::serialize(std::ofstream& ofs) const
{
    std::size_t len = reportsto.size();
    ofs.write( (char*)&len, sizeof(len) );
}

void fink::writeall(std::ofstream& ofs) const
{
    ofs.write( (char*)&abstr_emp::Fink, sizeof(abstr_emp::Fink) );
    abstr_emp::serialize(ofs);
    serialize(ofs);
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

void highfink::writeall(std::ofstream& ofs) const
{
    ofs.write( (char*)&abstr_emp::Highfink, sizeof(abstr_emp::Highfink) );
    abstr_emp::serialize(ofs);
    manager::serialize(ofs);
    fink::serialize(ofs);
    serialize(ofs);
}
/* ------------------------------------------------------------------------- */
