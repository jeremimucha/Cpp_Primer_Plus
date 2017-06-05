// lotto.cpp -- Chapter 16 pe7 -- generating a random pattern of numbers
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::vector;
using std::cin;
using std::cout;

vector<int> Lotto(int max, int selections);


int main()
{
    cout << "Lotto game.\n";

    while(true){
        cout << "Enter the number of spots: ";
        int max;
        cin >> max;
        cout << "Enter the number of selections: ";
        int sel;
        cin >> sel;
        vector<int> numbers = Lotto(max, sel);
        cout << "Your random numbers: ";
        std::copy(numbers.begin(), numbers.end(),
                  std::ostream_iterator<int, char>(cout, ", "));
        cout << std::endl;
    }
}


vector<int> Lotto(int max, int selections)
{
    std::vector<int> card(max);
    for(int i=0; i<max; ++i)
        card[i] = i+1;
    
    std::random_shuffle(card.begin(), card.end());
    std::vector<int> sel(card.begin(), card.begin()+selections);
    std::sort(sel.begin(), sel.end());
    return sel;
}
