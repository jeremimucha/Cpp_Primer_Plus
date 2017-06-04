// review_ch16.cpp -- Chapter 16 review
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;


// #1
/* ------------------------------------------------------------------------- */
class RQ1
{
private:
    char* st;
public:
    RQ1()
        { st = new char[1]; strcpy(st,""); }
    RQ1(const char* s)
        { st = new char[strlen(s) + 1]; strcpy(st,s); }
    RQ1(const RQ1& rq)
        { st = new char[strlen(rq.st) + 1]; strcpy(st,rq.st); }
    ~RQ1() { delete[] st; }
    RQ& operator=(const RQ& rq);
};

class RQ2
{
private:
    string st;
public:
    RQ2()
        : st() { }
    RQ2(const char* s)
        : st(s) { }
    RQ2(const RQ2& rq)              // not needed
        : st(rq.st) { }
    ~RQ2() { }                      // not needed
    RQ2& operator=(const RQ& rq);   // not needed
};
/* ------------------------------------------------------------------------- */

// #3
/* ------------------------------------------------------------------------- */
char toUpper(char c) { return toupper(c); }
void ToUpper(string& s)
{
    transform(s.begin(), s.end(), s.begin(), toUpper);
}
/* ------------------------------------------------------------------------- */

// #4
/* ------------------------------------------------------------------------- */
/* 
    auto_ptr<int> pia(new int[20]); // not ok - can not be used with new[]
    auto_ptr<string> (new string);  // ok
    int rigue = 7;
    auto_ptr<int> pr(&rigue);       // not ok - will delete non-heap memory
    auto_ptr dbl (new double);      // invalid syntax
*/
/* ------------------------------------------------------------------------- */


int main()
{

}
