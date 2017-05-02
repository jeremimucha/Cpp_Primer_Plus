// ex1.cpp -- Get two integers from the user, int a, b;
// Calculate the sum [a, b], assuming a <= b;
#include <iostream>
using namespace std;


int get_int(istream& is, const char* msg);

/* Calculates the sum in the range [a,b]. */
int sum_range(int a, int b);

template<class T>
void myswap(T& left, T& right);


int main()
{
    cout << "ex1.cpp - The program calculates the sum between two integers"
         << "\na, and b.\n\n";
    
    int a, b;
    a = get_int(cin, "Enter the 1st int: ");
    b = get_int(cin, "Enter the 2nd int: ");

    if( b < a ){
        myswap(a, b);
    }

    int total = sum_range(a, b);

    cout << "The sum of integers in the range [" << a <<','<< b <<"] = "
         << total
         << endl;

    return 0;
}


int get_int(istream& is, const char* msg)
{
    int res;
    while(cout << msg){
        if( is >> res ){
            while(is.get() != '\n')
                ;
            return res;
        }
        is.clear();
        cout << "Invalid input.\n";
    }
}

int sum_range(int a, int b)
{
    int total{0};
    while( a <= b ){
        total += a++;
    }
    return total;
}

template<class T>
void myswap(T& left, T& right)
{
    T temp = left;
    left = right;
    right = temp;
}
