// friends.cpp -- Chapter 17 exercise 5 - obtain two 'Friend lists' from files
// merge them, eliminating duplicated and write to a file
#include <iostream>
#include <fstream>
#include <cstdlib>      // for exit()
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>


// Person
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
std::vector<Person> get_friends(const char* msg);
std::vector<Person> read_friends(std::ifstream& ifs);
void show_friends(std::vector<Person> friends, const char* msg);


int main(int argc, char* argv[])
{
    using namespace std;
    if(argc != 4){
        cout << "Usage: " << argv[0] << "matsfriends_file patsfriends_file combinedfriends_file\n";
        exit(EXIT_FAILURE);
    }

    ifstream ifs(argv[1]);
    if(!ifs.is_open()){
        cout << "Failed to open " << argv[1] << " for input. Aborting.\n";
        exit(EXIT_FAILURE);
    }
    vector<Person> matfriends = read_friends(ifs);
    ifs.clear();
    ifs.close();
    ifs.open(argv[2]);
    if(!ifs.is_open()){
        cout << "Failed to open " << argv[2] << " for input. Aborting.\n";
        exit(EXIT_FAILURE);
    }
    vector<Person> patfriends = read_friends(ifs);
    ifs.close();

    ofstream ofs(argv[3]);
    if(!ofs.is_open()){
        cout << "Failed to open " << argv[3] << " for output. Aborting.\n";
        exit(EXIT_FAILURE);
    }

    set_union(matfriends.begin(), matfriends.end()
             ,patfriends.begin(), patfriends.end()
             ,ostream_iterator<Person, char>(ofs, "\n"));

    ofs.close();
    cout << "Done.\n";
    return 0;
}


// Person definitions
/* ------------------------------------------------------------------------- */
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

std::vector<Person> read_friends(std::ifstream& ifs)
{
    int linecnt{0};
    Person p;
    std::vector<Person> friends;
    while( ++linecnt ){
        ifs >> p;
        if(ifs.fail() && !ifs.eof()){
            std::cerr << "Invalid Person format on line " << linecnt << ". Aborting.\n";
            exit(EXIT_FAILURE);
        }
        if(ifs.eof())
            break;
        friends.push_back(p);
    }
    return friends;
}
/* ------------------------------------------------------------------------- */