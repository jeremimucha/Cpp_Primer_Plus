// personmi.h -- Chapter 14 pe 4 -- virtual inheritance
#ifndef PERSONMI_H_
#define PERSONMI_H_

#include <cstring>
#include <cstdlib>


class Person
{
private:
    char* first;
    char* last;
protected:
    virtual void Info() const;
    virtual void Get();
public:
    Person(const char* fname="NULL", const char* lname="NULL")
        : first(new char[std::strlen(fname) + 1])
        , last(new char[std::strlen(lname) + 1])
        {
            std::strcpy(first, fname);
            std::strcpy(last, lname);
            std::cout << "--> Person(const char*, const char*)\n";
        }
    virtual ~Person()
        {
            delete[] first;
            delete[] last;
        }
    virtual void Set() = 0;
    virtual void Show() const = 0;
};


class Gunslinger : virtual public Person
{
private:
    double drawtime;
    int notches;
protected:
    virtual void Info() const;
    virtual void Get();
public:
    Gunslinger(const char* fname="NULLGUN", const char* lname="NULLGUN",
               double dtime=-1, int n=0)
        : Person(fname, lname)
        , drawtime(dtime)
        , notches(n)
        {
            std::cout << "--> Gunslinger(const char*, const char*, double, int)\n";
        }
    virtual void Set();
    virtual void Show() const;
    double Draw() const
        { return drawtime; }
};


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
        { }
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
        { }

    friend std::ostream& operator<<(std::ostream& os, const Card& c);
};


class PokerPlayer : virtual public Person
{
protected:
    virtual void Info() const;
    virtual void Get() { }
public:
    PokerPlayer(const char* fname="NULLPOKER", const char* lname="NULLPOKER")
        : Person(fname, lname)
        { std::cout << "--> PokerPlayer(const char*, const char*)\n"; }
    virtual void Set();
    virtual void Show() const;
    Card Draw() const
        { return Card(); }
};


class BadDude : public Gunslinger, public PokerPlayer
{
protected:
    void Info() const;
    void Get();
public:
    BadDude(const char* fname="NULLBAD", const char* lname="NULLBAD",
            double dtime=-1, int n=0)
        : Person(fname, lname)
        , Gunslinger(fname, lname, dtime, n)
        , PokerPlayer(fname, lname)
        { std::cout << "--> BadDude(const char*, const char*, double, int)\n"; }
    double Gdraw() const
        { return Gunslinger::Draw(); }
    Card Cdraw() const
        { return PokerPlayer::Draw(); }
    void Set();
    void Show() const;
};

#endif /*PERSONMI_H_*/
