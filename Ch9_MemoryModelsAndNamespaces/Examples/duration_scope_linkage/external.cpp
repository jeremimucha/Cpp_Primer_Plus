// external.cpp -- external variables
// compile with suppoert.cpp
#include <iostream>
using namespace std;

// external variable
double warming = 0.3;   // definition

// function prototypes
void update(double dt);
void local();


int main()
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);    // cal function to change warming
    cout << "Global warming is " << warming << " degrees.\n";
    local();        // call function with local warming
    cout << "Global warming is " << warming << " degrees.\n";

    return 0;
}
