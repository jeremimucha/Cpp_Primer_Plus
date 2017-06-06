// friends.cpp -- Chapter 16 pe8 - merging two lists of strings
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>


class Person
{
private:
    std::string fname;
    std::string lname;
public:
    Person()
        : fname(), lname()
        { }
    Person(const std::string& first, const std::string& last)
        : fname(first), lname(last)
        { }
    void Show() const { std::cout << lname << ", " << fname << '\n'; }
    bool operator==(const Person& other) const;
    bool operator<(const Person& other) const;
// friends
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    friend std::istream& operator>>(std::istream& is, Person& p);
};

std::vector<Person> get_friends(const char* msg);
void show_friends(std::vector<Person> friends, const char* msg);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::vector;
    using std::set;
    using std::string;

    
    vector<Person> matfriends = get_friends("Enter Mat's friends.");
    vector<Person> patfriends = get_friends("Enter Pat's friends.");
    std::sort(matfriends.begin(), matfriends.end());
    std::sort(patfriends.begin(), patfriends.end());
    show_friends(matfriends, "Mat's friends:\n");
    show_friends(patfriends, "Pat's friends:\n");
    // vector<Person> allfriends;
// use a set instead to avoid sorting
    set<Person> allfriends;
    // set_union(matfriends.begin(), matfriends.end()
    //          ,patfriends.begin(), patfriends.end()
    //          ,std::back_insert_iterator<vector<Person>>(allfriends));
    // std::sort(allfriends.begin(), allfriends.end());
    set_union(matfriends.begin(), matfriends.end()
             ,patreiwnds.begin(), patfriends.end()
             ,std::insert_iterator<set<Person>>(allfriends, allfriends.begin()));
    show_friends(allfriends, "Mat's and Pat's friends:\n");

    return 0;
}


bool Person::operator==(const Person& other) const
{
    return (lname == other.lname && fname == other.fname);
}

bool Person::operator<(const Person& other) const
{
    if( lname == other.lname )
        return fname < other.fname;
    else
        return lname < other.lname;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    return os << p.fname << ' ' << p.lname;
}

std::istream& operator>>(std::istream& is, Person& p)
{
    std::string temp;
    if( !(is>>temp) )
        return is;
    if( temp.back() == ',' ){
        temp.pop_back();
        p.lname = temp;
        if( !(is>>p.fname) ){
            p.lname = "";
        }
    }
    else{
        p.fname = temp;
        if( !(is>>p.lname) ){
            p.fname = "";
        }
    }
    return is;
}

std::vector<Person> get_friends(const char* msg)
{
    std::cout << msg << " Empty line to stop.\n";
    std::string line;
    std::vector<Person> friends;
    while(std::cout << ">> " && std::getline(std::cin, line) && !line.empty()){
        std::istringstream iss{line};
        Person p;
        if( !(iss >> p) ){
            std::cout << "Invalid person format.\n"
                      << "Please enter friends in Firstname Lastname or Lastname, Firstname format.\n";
        }
        else
            friends.push_back(p);
    }
    return friends;
}

void show_friends(std::vector<Person> friends, const char* msg)
{
    std::cout << msg;
    for(std::vector<Person>::const_iterator p = friends.begin();
        p!=friends.end();
        ){
        std::cout << *p++ << '\n';
    }
}
