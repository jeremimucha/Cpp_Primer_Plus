// stock10.cpp -- Stock class with constructors, destructor added
#include <iostream>
#include "stock20.h"


// Class destructor
Stock::~Stock()
{
    std::cout << "Bye, " << company << "!\n";
}

// other methods
void Stock::buy(long num, double price)
{
    if(num < 0){
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else{
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;

    if(num < 0){
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if(num > shares){
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else{
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company
         << "  Shares: " << shares << '\n'
         << "  Share Price: " << share_val;
    // set format to #.##
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock& Stock::topval(const Stock& s) const
{
    if(s.total_val > total_val)
        return s;
    else
        return *this;
}
