// ex2.cpp -- Get up to 10 golf scores from the user. Store them in an array.
// Display the scores on one line and report the average score.
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;


int get_scores(istream& is, double scores[], int max);
void print_scores(ostream& os, double* begin, double* end);
double average_score(double* begin, double* end);
void skip_to_double(istream& is);


constexpr unsigned int SIZE = 10;

int main()
{
    double scores[SIZE];
    int size = get_scores(cin, scores, SIZE);
    cout << "# of scores entered: " << size
         << "\nScores: ";
    print_scores(cout, scores, scores + size);
    cout << "\nThe average score = " << average_score(scores, scores + size)
         << endl;
    
    return 0;
}


int get_scores(istream& is, double scores[], int max)
{
    cout << "Please enter up to " << max << " Golf scores (doubles). Empty line to quit.\n";

    int i = 0;
    string line;
    while( i < max && cout << ">> " && getline(is, line) && !line.empty() ){
        istringstream iss{line};
        double score;
        while( i < max && iss ){
            if( iss >> score )
                scores[i++] = score;
            else{
                skip_to_double(iss);
            }
        }
    }

    return i;
}

void skip_to_double(istream& is)
{
    if( is.bad() ) throw runtime_error("<skip_to_double>: istream in bad() state.\n");
    if( is.fail() ){
        is.clear();
        for( char ch; is >> ch; ){
            if( isdigit(ch) || ch == '-' ){
                is.putback(ch);
                break;
            }
        }
    }
}

void print_scores(ostream& os, double* begin, double* end)
{
    while( begin != end ){
        cout << *begin++ << ", ";
    }
}

double average_score(double* begin, double* end)
{
    double average{0};
    int n{0};
    while( begin != end ){
        average += *begin++;
        ++n;
    }
    return average / n;
}