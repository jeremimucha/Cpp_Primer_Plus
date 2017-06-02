// sales.h -- exceptions and inheritance
#ifndef SALES_H_
#define SALES_H_

#include <iostream>
#include <stdexcept>
#include <string>


class Sales
{
public:
    enum { MONTHS=12 };     // couls be a static const;
    class bad_index : public std::logic_error
    {
    private:
        int bi; // bad index value
    public:
        explicit bad_index(int ix,
                    const std::string& x="Index error in Sales object\n");
        int bi_val() const { return bi; }
        virtual ~bad_index() throw()    // C++98 exception specification
                                        // can be ommited under C++11 rules
            { std::cout << "<-- ~bad_index() -->\n"; }
    };

    explicit Sales(int yy=0);
    Sales(int yy, const double* gr, int n);
    virtual ~Sales()
        { std::cout << "<-- ~Sales() -->\n"; }
    int Year() const { return year; }
    virtual double operator[](int i) const;
    virtual double& operator[](int i);
private:
    double gross[MONTHS];
    int year;
};


class LabeledSales : public Sales
{
public:
    class nbad_index : public Sales::bad_index
    {
    private:
        std::string lbl;
    public:
        nbad_index(const std::string& lb, int ix,
            const std::string& s="Index error in LabeledSales object\n");
        const std::string& label_val() const
            { return lbl; }
        virtual ~nbad_index() throw()
            { std::cout << "<-- ~nbad_index() -->\n"; }
    };
    
    explicit LabeledSales(const std::string& lb="none", int yy=0);
    LabeledSales(const std::string& lb, int yy, const double* gr, int n);
    virtual ~LabeledSales()
        { std::cout << "<-- ~LabeledSales() -->\n"; }
    const std::string& Label() const
        { return label; }
    virtual double operator[](int i) const;
    virtual double& operator[](int i);
private:
    std::string label;
};


#endif /*SALES_H_*/
