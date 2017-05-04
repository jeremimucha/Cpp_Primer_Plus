// arrfun3.cpp -- array functions and const
#include <iostream>


const int Max = 5;


// function prototypes
int fill_array(double arr[], int limit);
void show_array(const double arr[], int n);
void revalue(double r, double ar[], int n);


int main()
{
    using namespace std;
    double properties[Max];

    int size = fill_array(properties, Max);
    show_array(properties, size);
    if(size > 0){
        cout << "Enter revaluation factor: ";
        double factor;
        while( !(cin >> factor) ){      // bad input 
            cin.clear();
            while( cin.get() != '\n' )
                ;
            cout << "Bad input. Please enter a number: ";
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";
    return 0;
}


int fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i{0};
    for( i=0; i<limit; ++i ){
        cout << "Enter value #" << (i+1) << ": ";
        if( !(cin>>temp) ){     // bad input
            cin.clear();
            while( cin.get() != '\n' )
                ;
            cout << "Bad input. Input process terminated.\n";
            break;
        }
        else if( temp < 0 ) // signal to terminate
            break;

        ar[i] = temp;
    }

    return i;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], int n)
{
    using namespace std;
    for( int i=0; i<n; ++i ){
        cout << "Property #" << (i+1) << ": $"
             << ar[i]
             << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double r, double ar[], int n)
{
    for( int i=0; i<n; ++i )
        ar[i] *= r;
}
