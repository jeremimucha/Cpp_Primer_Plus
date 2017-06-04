// vect_arr_valarr.cpp -- comparison between vector array and valarray interfaces
#include <iostream>
#include <vector>
#include <valarray>
#include <array>
#include <algorithm>
#include <cmath>
using namespace std;


double calculation(double a, double b);


int main()
{
    vector<double> ved1 = {1,2,3,4,5,6,7,8,9,10};
    vector<double> ved2 = {1,3,5,7,9,11,13,15,17,19};
    vector<double> ved3 = {2,4,6,8,10,12,14,18,20,22};
    vector<double> ved4(10);

    array<double, 10> vod1 = {1,2,3,4,5,6,7,8,9,10};
    array<double, 10> vod2 = {1,3,5,7,9,11,13,15,17,19};
    array<double, 10> vod3 = {2,4,6,8,10,12,14,18,20,22};
    array<double, 10> vod4;

    valarray<double> vad1 = {1,2,3,4,5,6,7,8,9,10};
    valarray<double> vad2 = {1,3,5,7,9,11,13,15,17,19};
    valarray<double> vad3 = {2,4,6,8,10,12,14,18,20,22};
    valarray<double> vad4(10);

    vad4 = 10.0 * ((vad1+vad2) / 2.0 + vad1 * cos(vad2));
    cout << "vad4:\n";
    for(int i=0; i<10; ++i)
        cout << vad4[i] <<' ';
    cout << endl;

    transform(ved1.begin(), ved1.end(), ved2.begin(), ved4.begin(),
              calculation);
    cout << "vad4:\n";
    for(double d : ved4) cout << d << ' ';
    cout << endl;
}

inline double calculation(double a, double b)
{
    return 10.0 * ((a + b) / 2.0 + a * cos(b));
}
