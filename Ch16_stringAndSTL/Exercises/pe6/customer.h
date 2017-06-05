// customer.h -- Ch16 pe6 - Customer class used in atm simulation
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <cstdlib>


class Customer
{
private:
    long arrive;
    int processtime;
public:
    Customer()
        : arrive(0), processtime(std::rand() % 3 + 1)
        { }
    explicit Customer(long arrive_time)
        : arrive(arrive_time), processtime(std::rand() % 3 + 1)
        { }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

inline void Customer::set(long when)
{
    arrive = when;
}

#endif /*CUSTOMER_H_*/
