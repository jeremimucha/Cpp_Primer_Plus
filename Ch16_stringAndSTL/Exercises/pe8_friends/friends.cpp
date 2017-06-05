// friends.cpp -- Chapter 16 pe8 - merging two lists of strings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>


class Person
{
private:
    std::string fname;
    std::string lname;
public:
    Person(const std:string& first, const std::string& last)
        : fname(first), lname(last)
        { }
    void Show() const { cout << lname << ", " << fname << '\n'; }
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    friend std::istream& operator>>(std::istream& is, Person& p);
};

std::istream& get_person(std::istream& is, Person& p);


int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::vector;
    using std::string;

    
    vector<string> matfirnds;
    vector<string> patfriends;
    string line;
    cout << "Enter Mat's friends. Empty line to stop.\n";
    while(cout << ">> " && getline(cin, line) && !line.empty()){
        std::istringstream iss(line);
        Person p;
        if( !(iss >> p) ){
            cout << "Invalid person format.\n"
                 << "Please enter friends in Firstname Lastname or Lastname, Firstname format.\n";
        }
        else
            matfriends.push_back(p);
    }
}


friend std::ostream& operator<<(std::ostream& os, const Person& p)
{
    return os << p.fname << ' ' << p.lname;
}

friend std::istream& operator>>(std::istream& is, Person& p);
{
    std::string temp;
    if( !(is>>temp) )
        return is;
    if( temp.back() == ',' ){
        temp.pop_back();
        lname = temp;
        if( !(is>>fname) ){
            lname = "";
        }
    }
    else{
        fname = temp;
        if( !(is>>lname) ){
            fname = "";
        }
    }
    return is;
}

std::istream& get_person(std::istream& is, Person& p)
{
    if( is >> p )
        return is;
    else{

    }
}
