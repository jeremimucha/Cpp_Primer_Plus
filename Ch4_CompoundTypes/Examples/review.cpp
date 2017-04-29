// review.cpp -- Chapter 14 review
#include <array>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;


// 8
struct fish_t
{
    char kind[20];
    int weight; // whole ounces
    double length;  // inches
};


// 13
int get_int(istream& is);


// 10
enum Response
{ No, Yes, Maybe };


int main()
{
    // 1
    char actors[30];
    short betsie[100];
    float chuck[13];
    long double dispea[64];

    // 2
    array<char, 30> actors2;
    array<short, 100> betsie2;
    array<float, 13> chuck2;
    array<long double, 64> dipsea2;

    // 3
    int fiveints[5]{1,2,3,4,5};

    // 4
    int even = fiveints[0] + fiveints[4];

    // 5
    float ideas[3]{1.1,2.2,3.3};
    cout << "#5: idead[1] = " << ideas[1] << '\n';

    // 6
    char ar5[] = "cheeseburger";
    // 7
    string s5{"Waldorf Salad"};

    // 9
    fish_t afish{"Foo", 42, 24.2};

    // 11
    double ted = 11.1;
    double* pd = &ted;
    cout << "#11: *pd = " << *pd << '\n';

    // 12
    float treacle[10]{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
    float* pf = treacle;
    cout << "#12: *pf = " << *pf <<", *(pf+9) = " << *(pf+9) << '\n';

    // 13
    cout << "#13:\nPlease enter array size: ";
    int arsize = get_int(cin);
    int* dynarray = new int[arsize];
    delete[] dynarray;
    vector<int> v{arsize};

    // 14
    cout << "\n#14: " << (int*)"Home of the jolly bytes";

    // 15
    fish_t* dynfish = new fish_t;
    cout << "\n15:\nPlease enter fish_t kind: ";
    string fkind;
    cin >> fkind;
    strncpy(dynfish->kind, fkind.c_str(), 20);
    dynfish->kind[19] = '\0';
    delete dynfish;

    // 17
    constexpr int nstrings = 10;
    std::vector<string> vs{nstrings};
    std::array<string, nstrings> arr_string;
}


int get_int(istream& is){
    int res{0};
    while(true){
        cout << ">> ";
        if(is >> res && res >= 0){
            return res;
        }
        is.clear();
        cout << "Invalid input. Please enter a positive integer.\n";
    }
}
