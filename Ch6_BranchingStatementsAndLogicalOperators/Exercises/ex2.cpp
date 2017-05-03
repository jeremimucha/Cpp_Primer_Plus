// ex2.cpp -- reads up to 10 double values into an array, stops on
// non-numeric input.
#include <iostream>
using namespace std;


constexpr int SIZE = 10;


int main()
{
    cout << "Enter up to " << SIZE << " doubles. Enter a non-numeric character to stop input"
         << "\nProgram reports the average ..."
         << endl;

    double darr[SIZE];
    int i{0};
    while(i<SIZE &&
          cout <<"#"<<i+1<<": "
          && cin >> darr[i]){
        ++i;
    }

    double total{0.0};
    for(int j=0; j<i; ++j){
        total += darr[j];
    }
    double avrg = total/i;
    int n_greater_average{0};
    for(int j=0; j<i; ++j){
        if( darr[j] > avrg )
            ++n_greater_average;
    }

    // report results
    if( i == 0 )
        cout << "No values entered.\n";
    else
        cout << "Average of " << i << " values: " << avrg
             << "\n# of values greater than the average: " << n_greater_average
             << endl;

    return 0;
}
