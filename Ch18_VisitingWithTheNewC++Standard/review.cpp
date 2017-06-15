// review.cpp -- Chapter 18 review
#include <iostream>
#include <string>
#include <array>


// #1
/* ------------------------------------------------------------------------- */
class Z200
{
private:
    int j;
    char ch;
    double z;
public:
    Z200(int jv, char chv, zv)
        : j(jv), ch(chv), z(zv) { }
};
/* ------------------------------------------------------------------------- */

// #2
/* ------------------------------------------------------------------------- */
double up(double x) { return 2.0 * x; }
void r1(const double &rx) { std::cout << rx << std::endl; }
void r2(double &rx) { std::cout << rx << std::endl; }
void r3(double &&rx) { std::cout << rx << std::endl; }
/* ------------------------------------------------------------------------- */

// #6
/* ------------------------------------------------------------------------- */
template<typename T>
void show2(double x, T& fp) { std::cout << x << " -> " << fp(x) << '\n'; }
double f1(double x) { return 1.8 * x + 32; }
/* ------------------------------------------------------------------------- */

// #7
/* ------------------------------------------------------------------------- */
const int Size = 5;
template<typename T>
void sum(std::array<double, Size> a, T& fp)
{
    for(auto pt=a.begin(); pt!=a.end(), ++pt)
        fp(*pt);
}
class Adder
{
    double tot;
public:
    Adder(double q=0) : tot(q) { }
    void operator()(double w) { tot += w; }
    double tot_v() const { return tot; }
};
/* ------------------------------------------------------------------------- */


int main()
{
// #1
/* ------------------------------------------------------------------------- */
    double x{8.8};
    std::string s{"What a bracing effect!"};
    int k{99};
    Z200 zip{200, 'Z', 0.675};
    std::vector<int> ai{3, 9, 4, 7, 1};
/* ------------------------------------------------------------------------- */

// #2
/* ------------------------------------------------------------------------- */
double w{10.0};
r1(w);      
r1(w+1);    
r1(up(w));  
r2(w);      
r2(w+1);    
r2(up(w));  
r3(w);      // error
r3(w+1);    // OK rvalue ref
r3(up(w));  // OK rvalue ref
/* ------------------------------------------------------------------------- */

// #6
/* ------------------------------------------------------------------------- */
// without lambdas
show2(18.8, f1);
// with lambdas
show2(18.8, [](double x){ return 1.8 * x + 32; });
/* ------------------------------------------------------------------------- */

// #7
/* ------------------------------------------------------------------------- */
double total = 0.0;
std::array<double, Size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7 };
// no lambdas
Adder ad(total);
sum(temp_c, add);
total = ad.tot_v();
std::cout << "total: " << add.tot_v() << '\n';
// with lambdas
double totall{0.0};
sum(temp_c, [&totall](double x){ total += x; });
std::cout << "total using lambdas: " << totall << '\n';
/* ------------------------------------------------------------------------- */
}
