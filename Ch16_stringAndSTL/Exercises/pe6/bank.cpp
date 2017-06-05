// bank.cpp -- Chapter 16 pe6 - atm queue usage example using stl queue
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "customer.h"


const int MIN_PER_HR = 60;


bool newcustomer(double x)
{ return (std::rand() * x / RAND_MAX < 1); }


int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

// seed random number generation
    std::srand(std::time(nullptr));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    unsigned int cust_limit;
    cin >> cust_limit;
    std::queue<Customer> line;

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours;
    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust = MIN_PER_HR / perhour;

    Customer temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;
// running the simulation
    for(int cycle=0; cycle < cyclelimit; ++cycle){
        if(newcustomer(min_per_cust)){
            if(line.size() == cust_limit)
                ++turnaways;
            else{
                ++customers;
                line.push(Customer(cycle));
            }
        }
        if(wait_time <= 0 && !line.empty()){
            const Customer cust = line.front();
            line.pop();
            wait_time = cust.ptime();
            line_wait += cycle - cust.when();
            ++served;
        }
        if(wait_time > 0)
            --wait_time;
        sum_line += line.size();
    }
// reporting results
    if(customers > 0){
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: "
             << (double)line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}
