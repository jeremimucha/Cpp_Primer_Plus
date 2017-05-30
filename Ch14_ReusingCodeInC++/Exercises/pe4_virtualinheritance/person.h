// person.h -- Chapter 14 pe 4 -- virtual inheritance
#ifndef PERSON_H_
#define PERSON_H_

#include <cstring>
#include <cstdlib>

// seed random number generator for PokerPlayer and Card classes
std::srand(std::time(nullptr));

class Person
{
private:
    char* first;
    char* last;
protected:
    virtual void Info() const;
public:
    Person(const char* fname="NULL", const char* lname="NULL")
        : first(new char[std::strlen(fname) + 1])
        , last(new char[std::strlen(lname) + 1])
        {
            std::strcpy(first, fname);
            std::strcpy(last, lname);
            std::cout << "--> Person(const char*, const char*)\n";
        }
    virtual ~Person();
    virtual void Show() const;
};

Person::~Person()
{
    delete[] first;
    delete[] last;
}

void Person::Info() const
{
    std::cout << "First name: " << first << '\n'
              << "Last name: " << last << '\n';
}

void Person::Show() const
{
    std::cout << "Person:\n";
    Info();
}


class Gunslinger : virtual public Person
{
private:
    double drawtime;
    int notches;
protected:
    virtual void Info() const;
public:
    Gunslinger(const char* fname="NULLGUN", const char* lname="NULLGUN",
               double dtime=-1, int n=0)
        : Person(fname, lname)
        , drawtime(dtime)
        , notches(n)
        {
            std::cout << "--> Gunslinger(const char*, const char*, double, int)\n";
        }
    virtual void Show() const;
    double Draw() const
        { return drawtime; }
};

void Gunslinger::Info() const
{
    std::cout << "Drawtime: " << drawtime << '\n'
              << "Gun-notches: " << notches << '\n';
}

void Gunslinger::Show() const
{
    std::cout << "Gunslinger:\n";
    Person::Info();
    Info();
}


class Card
{
protected:
    enum {RANKS=13};
    enum {SUITS=4};
    enum { ace=0, jack=10, queen=11, king=12 };
    enum { clubs, dimonds, hearts, spades };
private:
    static const char* ranks[RANKS];
    static const char* suits[SUITS];
    int rank;
    int suit;
public:
    Card()
        : rank(std::rand() % RANKS), suit(std::rand() % SUITS)
        { std::cout << "--> Card()\n"; }
    Card(int card)
        {
            if( 0 <= card && card < 52 ){
                rank = card / SUITS;
                suit = card % SUITS;
            }
            else{
                rank = std::rand() % RANKS;
                suit = std::rand() % 4;
            }
        }
    Card(int r, int s)
        : rank(r), suit(s)
        { std::cout <<"--> Card(int, int)\n"; }
    friend std::ostream& operator<<(std::ostream& os, const Card& c);
}


const char* Card::ranks[Card::RANKS] =
                          { "Ace", "1", "2", "3", "4", "5", "6", "7", "8",
                            "9", "10", "Jack", "Queen", "King" };
const char* Card::suits[Card::SUITS] =
                          { "Clubs", "Dimonds", "Hearts", "Spades" };


std::ostream& operator<<(std::ostream& os, const Card& c)
{
    return os << ranks[rank] << " of " << suits[suit];
}


class PokerPlayer : virtual public Person
{
protected:
    virtual void Info() const { }
public:
    PokerPlayer(const char* fname="NULLPOKER", const char* lname="NULLPOKER")
        : Person(fname, lname)
        { std::cout << "--> PokerPlayer(const char*, const char*)\n"; }
    Card Draw() const
        { return Card(); }
};


class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude(const char* fname="NULLBAD", const char* lname="NULLBAD",
            double dtime=-1, int n=0)
        : Person(fname, lname)
        , Gunslinger(fname, lname, dtime, n)
        , PokerPlayer(fname, lname)
        { std::cout << "--> BadDude(const char*, const char*, double, int)\n"; }
    double Gdraw() const
        { Gunslinger::Draw(); }
    Card Cdraw() const
        { PokerPlayer::Draw(); }
    void Show() const;
};

void BadDude::Show() const
{
    std::cout << "BadDude:\n";
    Person::Info();
    Gunslinger::Info();
    PokerPlayer::Info();
}

#endif /*PERSON_H_*/
