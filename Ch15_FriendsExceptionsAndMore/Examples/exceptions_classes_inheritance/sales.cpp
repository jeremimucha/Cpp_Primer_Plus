// sales.cpp -- Sales implementation
#include "sales.h"
using std::string;


Sales::bad_index::bad_index(int ix, const string& s)
    : std::logic_error(s), bi(ix)
{
    std::cout << "<-- Sales::bad_index(int, const string&) -->\n";
}

Sales::Sales(int yy)
    : year(yy)
{
    for(int i=0; i<MONTHS; ++i)
        gross[i] = 0;
}

Sales::Sales(int yy, const double* gr, int n)
    : year(yy)
{
    int lim = (n < MONTHS) ? n : MONTHS;
    int i;
    for(i=0; i<lim; ++i){
        gross[i] = gr[i];
    }
    // for i > n and i < MONTHS
    for( ; i < MONTHS; ++i ){
        gross[i] = 0;
    }

    std::cout << "<-- Sales(int, const double*, int) -->\n";
}

double Sales::operator[](int i) const
{
    if(i < 0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}

double& Sales::operator[](int i)
{
    if(i < 0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}

LabeledSales::nbad_index::nbad_index(const string& lb, int ix, const string&s)
    : Sales::bad_index(ix, s), lbl(lb)
{
    std::cout << "<-- LabeledSales::nbad_index(const string&, int, const string&) -->\n";
}

LabeledSales::LabeledSales(const string& lb, int yy)
    : Sales(yy), label(lb)
{
    std::cout << "<-- LabeledSales(const string&, int) -->\n";
}

LabeledSales::LabeledSales(const string& lb, int yy, const double* gr, int n)
    : Sales(yy, gr, n), label(lb)
{
    std::cout << "<-- LabeledSales(const string&, int, const double*, int) -->\n";
}

double LabeledSales::operator[](int i) const
{
    if(i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}

double& LabeledSales::operator[](int i)
{
    if(i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}
