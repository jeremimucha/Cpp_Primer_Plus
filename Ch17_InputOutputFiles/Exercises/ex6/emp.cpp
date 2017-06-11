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
    std::cout << "Enter Job: ";
    std::cin >> job;
    while(std::cin.get() != '\n')
        ;
}

void abstr_emp::serialize(std::ofstream& ofs) const
{
    std::size_t len;
    // std::string& members[] = {fname, lname, job};
    // for( const std::string* s : { &fname, &lname, &job }){
    //     len = s->size();
    //     ofs.write( (char*)&len, sizeof(len) );
    //     ofs.write( s->data(), len );
    // }
// fname
    len = fname.size();
    ofs.write( (char*)&len, sizeof(len) );
    ofs.write( fname.data(), len );
// lname
    len = lname.size();
    ofs.write( (char*)&len, sizeof(len) );
    ofs.write( lname.data(), len );
// job
    len = job.size();
    ofs.write( (char*)&len, sizeof(len) );
    ofs.write( job.data(), len );
}

void abstr_emp::deserialize(std::ifstream& ifs)
{
    std::size_t len;
    // for( std::string* ps : { &fname, &lname, &job }){
    //     ifs.read( (char*)&len, sizeof(len) );
    //     if(ifs.fail()){
    //         std::cerr << "<abstr_emp::deserialize>: failed to read size_t from file.\n";
    //         exit(EXIT_FAILURE);
    //     }
    //     char buf[len +1];
    //     ifs.read(buf, len);
    //     if(ifs.fail()){
    //         std::cerr << "<abstr_emp::deserialize>: failed to read string from file.\n";
    //         exit(EXIT_FAILURE);
    //     }
    //     buf[len] = '\0';
    //     *ps = buf;
    // }
// fname
    ifs.read( (char*)&len, sizeof(len) );
    if(ifs.fail()){
        std::cerr << "<abstr_emp::deserialize>: failed to read len fname from file.\n";
        exit(EXIT_FAILURE);
    }
    char buffname[len + 1];
    ifs.read(buffname, len);
    if(ifs.fail()){

    }
    buffname[len] = '\0';
    fname = buffname;
// lname
    ifs.read( (char*)&len, sizeof(len) );
    if(ifs.fail()){
        std::cerr << "<abstr_emp::deserialize>: failed to read len lname from file.\n";
        exit(EXIT_FAILURE);
    }
    char buflname[len + 1];
    ifs.read(buflname, len);
    if(ifs.fail()){

    }
    buflname[len] = '\0';
    lname = buflname;
// job
    ifs.read( (char*)&len, sizeof(len) );
    if(ifs.fail()){
        std::cerr << "<abstr_emp::deserialize>: failed to read len job from file.\n";
        exit(EXIT_FAILURE);
    }
    char bufjob[len + 1];
    ifs.read(bufjob, len);
    if(ifs.fail()){

    }
    bufjob[len] = '\0';
    job = bufjob;
}

void abstr_emp::writeall(std::ofstream& ofs) const
{
    decltype(Abstr_emp) classkind = Abstr_emp;
    ofs.write( (char*)&classkind, sizeof(classkind) );
    serialize(ofs);
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
    return os << e.fname << e.lname;
}

std::vector<abstr_emp*> abstr_emp::readall(std::ifstream& ifs)
{
    std::vector<abstr_emp*> emps;
    unsigned int classkind;
    while( ifs.read( (char*)&classkind, sizeof(classkind) ) ){
        switch(classkind){
            case Abstr_emp:
            case Employee:
                emps.push_back(new employee);
                break;
            case Manager:
                emps.push_back(new manager);
                break;
            case Fink:
                emps.push_back(new fink);
                break;
            case Highfink:
                emps.push_back(new highfink);
                break;
            default:
                std::cerr << "<abstr_emp::readall>: reached default\n";
                break;
        }
        emps.back()->getall(ifs);
    }
    return emps;
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
    unsigned int classkind = abstr_emp::Employee;
    ofs.write( (char*)&classkind, sizeof(classkind) );
    abstr_emp::serialize(ofs);
    serialize(ofs);
}

void employee::getall(std::ifstream& ifs)
{
    abstr_emp::deserialize(ifs);
    deserialize(ifs);
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

void manager::deserialize(std::ifstream& ifs)
{
    ifs.read( (char*)&inchargeof, sizeof(inchargeof) );
    if(ifs.fail()){
        std::cerr << "<manager::deserialize>: Failed to read int.\n";
    }
}

void manager::writeall(std::ofstream& ofs) const
{
    unsigned int classkind = abstr_emp::Manager;
    ofs.write( (char*)&classkind, sizeof(classkind) );
    abstr_emp::serialize(ofs);
    serialize(ofs);
}

void manager::getall(std::ifstream& ifs)
{
    abstr_emp::deserialize(ifs);
    deserialize(ifs);
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
    if(ofs.fail()){
        std::cerr << "<fink::serialize>: Failed to write size_t\n";
        exit(EXIT_FAILURE);
    }
    ofs.write( reportsto.data(), len );
    if(ofs.fail()){
        std::cerr << "<fink::serialize>: Failed to write string\n";
        exit(EXIT_FAILURE);
    }
}

void fink::deserialize(std::ifstream& ifs)
{
    std::size_t len;
    ifs.read( (char*)&len, sizeof(len) );
    if(ifs.fail()){
        std::cerr << "<fink::deserialize>: Failed to read size_t.\n";
        exit(EXIT_FAILURE);
    }
    char buf[len + 1];
    ifs.read( buf, len );
    if(ifs.fail()){
        std::cerr << "<fink::deserialize>: Faield to read string.\n";
        exit(EXIT_FAILURE);
    }
    buf[len] = '\0';
    reportsto = buf;
}

void fink::writeall(std::ofstream& ofs) const
{
    unsigned int classkind = abstr_emp::Fink;
    ofs.write( (char*)&classkind, sizeof(classkind) );
    abstr_emp::serialize(ofs);
    serialize(ofs);
}

void fink::getall(std::ifstream& ifs)
{
    abstr_emp::deserialize(ifs);
    deserialize(ifs);
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
    unsigned int classkind = abstr_emp::Highfink;
    ofs.write( (char*)&classkind, sizeof(classkind) );
    abstr_emp::serialize(ofs);
    manager::serialize(ofs);
    fink::serialize(ofs);
    serialize(ofs);
}

void highfink::getall(std::ifstream& ifs)
{
    abstr_emp::deserialize(ifs);
    manager::deserialize(ifs);
    fink::deserialize(ifs);
    deserialize(ifs);
}
/* ------------------------------------------------------------------------- */
