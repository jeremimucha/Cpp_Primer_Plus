// funadap.cpp -- using function adapters
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>


void Show(double);
const int LIM = 6;


int main()
{
    using namespace std;
    double arr1[LIM] = {28,29,30,35,38,59};
    double arr2[LIM] = {63,65,69,75,80,99};
    vector<double> gr8(arr1, arr1+LIM);
    vector<double> m8(arr2, arr2+LIM);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8:\t";
    for_each(gr8.begin(), gr8.end(), Show);
    cout << endl;
    cout << "m8: \t";
    for(double x : m8) Show(x);
    cout << endl;

    vector<double> sum(LIM);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
    cout << "sum:\t";
    for(double x : sum) Show(x);
    cout << endl;

    vector<double> prod(LIM);
    transform(gr8.begin(), gr8.end(), prod.begin(),
              bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for(double x : prod) Show(x);
    cout << endl;
    vector<double> prod2;
    transform(gr8.begin(), gr8.end(),
              back_insert_iterator<vector<double>>(prod2),
              bind1st(multiplies<double>(), 2.5));
    cout << "using a back_insert_iterator:\n";
    cout << "prod2:\t";
    for(double x : prod2) Show(x);
    cout << endl;
    cout << "using ostream_iterator:\n";
    cout << "prod:\t";
    transform(gr8.begin(), gr8.end(), ostream_iterator<double, char>(cout, " "),
             bind2nd(multiplies<double>(), 2.5));

    return 0;
}

void Show(double v)
{
    std::cout.width(6);
    std::cout << v << ' ';
}
