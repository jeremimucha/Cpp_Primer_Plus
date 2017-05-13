// stock10.h -- Stock class declaration with constructor, destructor added
#ifndef STOCK20_H_
#define STOCK20_H_

#include <string>
#include <iostream>

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
// two constructors
    // default constructor
    Stock()
        :company("no name"), shares(0), share_val(0.0), total_val(0.0)
        { std::cout << "Default constructor called.\n"; }

    Stock(const std::string& co, long n=0, double pr=0.0)
        :company(co), share_val(pr)
        {
            std::cout << "Constructor using " << co << " called.\n";
            if(n < 0){
                std::cout << "Number of shares can't be negative; "
                          << company << " shares set to 0.\n";
                shares = 0;
            }
            else{
                shares = n;
            }
            set_tot();
        }
    ~Stock();   // noisy destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
    const Stock& topval(const Stock& s) const;
};


#endif /* STOCK20_H_ */
