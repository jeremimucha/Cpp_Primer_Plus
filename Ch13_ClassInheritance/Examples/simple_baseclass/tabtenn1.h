// tabtenn1.h -- a table-tennis base class
#ifndef TABTENN1_H_
#define TABTENN1_H_
#include <string>
using std::string;


// simple base class
class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string& fn="none",
                      const string& ln="none", bool ht = false)
        :firstname(fn), lastname(ln), hasTable(ht)
        { }
    void Name() const;
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v) { hasTable = v; }
};


// simple derived class
class RatedPlayer : public TableTennisPlayer
{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r=0, const string& fn="none",
                const string& ln="none", bool ht=false)
        :TableTennisPlayer(fn, ln, ht), rating(r)
        { }
    RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
        :TableTennisPlayer(tp), rating(r)
        { }
    unsigned int Rating() const { return rating; }
    void ResetRating(unsigned int r) { rating = r; }
};


#endif /*TABTENN0_H_*/
