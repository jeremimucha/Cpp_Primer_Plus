// personmi.cpp -- Chapter 14 pe4
#include <iostream>
#include <string>
#include "personmi.h"

// Person
/* ------------------------------------------------------------------------- */
void Person::Info() const
{
    std::cout << "First name: " << first << '\n'
              << "Last name: " << last << '\n';
}

void Person::Get()
{
    std::cout << "Enter first name: ";
    std::string fname;
    std::cin >> fname;
    std::cout << "Enter last name: ";
    std::string lname;
    std::cin >> lname;
    delete[] first;
    delete[] last;
    first = new char[fname.size()+1];
    std::strcpy(first, fname.c_str());
    last = new char[lname.size()+1];
    std::strcpy(last, lname.c_str());
}
/* ------------------------------------------------------------------------- */


// Gunslinger
/* ------------------------------------------------------------------------- */
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

void Gunslinger::Get()
{
    std::cout << "Enter gunslinger's drawtime: ";
    std::cin >> drawtime;
    std::cout << "Enter number of notches on gunslinger's gun: ";
    std::cin >> notches;
    while(std::cin.get() != '\n')
        ;
}

void Gunslinger::Set()
{
    std::cout << "Enter gunslinger's name:\n";
    Person::Get();
    Get();
}
/* ------------------------------------------------------------------------- */


// Card
/* ------------------------------------------------------------------------- */
const char* Card::ranks[Card::RANKS] =
                          { "Ace", "2", "3", "4", "5", "6", "7", "8",
                            "9", "10", "Jack", "Queen", "King" };
const char* Card::suits[Card::SUITS] =
                          { "Clubs", "Dimonds", "Hearts", "Spades" };


std::ostream& operator<<(std::ostream& os, const Card& c)
{
    return os << Card::ranks[c.rank] << " of " << Card::suits[c.suit];
}
/* ------------------------------------------------------------------------- */


// PokerPlayer
/* ------------------------------------------------------------------------- */
void PokerPlayer::Set()
{
    std::cout << "Enter poker player's name:\n";
    Person::Get();
    Get();
}

void PokerPlayer::Show() const
{
    std::cout << "PokerPlayer:\n";
    Person::Info();
    Info();
}

void PokerPlayer::Info() const
{
    std::cout << "Draws a " << Draw() << '\n';
}
/* ------------------------------------------------------------------------- */


// BadDude
/* ------------------------------------------------------------------------- */
void BadDude::Show() const
{
    std::cout << "BadDude:\n";
    Person::Info();
    Info();
}

void BadDude::Set()
{
    std::cout << "Enter bad dude's name:\n";
    Person::Get();
    Get();   
}

void BadDude::Get()
{
    Gunslinger::Get();
    PokerPlayer::Get();
}

void BadDude::Info() const
{
    Gunslinger::Info();
    PokerPlayer::Info();
}
/* ------------------------------------------------------------------------- */
