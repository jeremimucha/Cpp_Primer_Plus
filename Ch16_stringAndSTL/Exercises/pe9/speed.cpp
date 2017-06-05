// speed.cpp -- Ch16 pe9 -- comparing vector and list sorting
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
using std::vector;
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;


int main(int argc, char* argv[])
{
    if( argc != 3 ){
        cout << "USAGE: speed.exe container_size num_of_repetitions\n";
        exit(EXIT_FAILURE);
    }

// seed random number gen
    std::srand(std::time(nullptr));

    stringstream ss;
    ss << argv[1];
    unsigned int ELEM_CNT;
    ss >> ELEM_CNT;
    stringstream(argv[2]).swap(ss);
    int REPS;
    ss >> REPS;

// create containers
    vector<int> v0(ELEM_CNT);
    list<int> li;
    vector<int> vi(ELEM_CNT);
// init containers to random numbers
    for( int& elem : v0 )
        elem = std::rand();

    // std::copy(v0.begin(), v0.end(), std::back_insert_iterator<list<int>>(li));
    // std::copy(v0.begin(), v0.end(), vi.begin();

    int rep = REPS;
    double total{0.0};
// timing vector sort
    while(rep--){
        vector<int> vi(v0.begin(), v0.end());
        clock_t start = std::clock();
        std::sort(vi.begin(), vi.end());
        clock_t end = std::clock();
        total += (double)(end - start) / CLOCKS_PER_SEC;
    }
    cout << "VECTOR:\n";
    cout << "Total time to sort a vector of " << ELEM_CNT << " ints a " << REPS << " times:\n"
         << "===> " << total
         << endl;
    cout << "Time to sort a vector of " << ELEM_CNT << " ints:\n"
         << "===> " << total / REPS
         << endl;

    rep = REPS;
    total = 0.0;
// timing list sort
    while(rep--){
        list<int> li(v0.begin(), v0.end());
        clock_t start = std::clock();
        // std::sort(li.begin(), li.end());
        li.sort();
        clock_t end = std::clock();
        total += (double)(end - start) / CLOCKS_PER_SEC;
    }
    cout << "\nLIST:\n";
    cout << "Total time to sort a list of " << ELEM_CNT << " ints a " << REPS << " times:\n"
         << "===> " << total
         << endl;
    cout << "Time to sort a list of " << ELEM_CNT << " ints:\n"
         << "===> " << total / REPS
         << endl;

    rep = REPS;
    total = 0.0;
// timing list copy to vector + vector sort + copy back to list
    while(rep--){
        list<int> li(v0.begin(), v0.end());
        vector<int> vi(v0.size());
        clock_t start = std::clock();
        std::copy(li.begin(), li.end(), vi.begin());
        std::sort(vi.begin(), vi.end());
        std::copy(vi.begin(), vi.end(), li.begin());
        clock_t end = std::clock();
        total += (double)(end - start) / CLOCKS_PER_SEC;
    }
    cout << "\nLIST\\VECTOR:\n";
    cout << "Total time to copy a list to a vector, sort the vector, copy sorted vector back over the list\n" 
         << "for " << ELEM_CNT << " ints a " << REPS << " times:\n"
         << "===> " << total
         << endl;
    cout << "Total time to copy a list to a vector, sort the vector, copy sorted vector back over the list\n"
         << "for " << ELEM_CNT << " ints:\n"
         << "===> " << total/REPS
         << endl;

    return 0;
}
