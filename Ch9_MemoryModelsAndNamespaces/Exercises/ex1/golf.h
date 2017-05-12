// golf.h -- for pe9_1.cpp
#ifndef GOLF_H_
#define GOLF_H_


const int LEN = 40;
struct golf
{
    char fullname[LEN];
    int handicap;
};

// non-interactive version:
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
void setgolf(golf& g, const char* name, int hc);

// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns the length of the name entered
int setgolf(golf& g);

// function resets handicap to new value
void handicap(golf& g, int hc);

// function displays contents of golf structure
void showgolf(const golf& g);


#endif /* GOLF_H_ */
