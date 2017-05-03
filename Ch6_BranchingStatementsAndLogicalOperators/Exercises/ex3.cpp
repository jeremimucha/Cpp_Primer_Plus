// ex3.cpp -- Displays a menu to the user. Prompts the user to input one of the 
// menu choices.
#include <iostream>
using namespace std;


void show_menu(const char* choices, const char** choice_descr, int size);
char get_choice(const char* prompt, const char* invalid_prompt);
bool is_valid(char input, const char* valid, int size);



const char  choices[]{ 'a', 'b', 'c', 'd', 'q' };
const char* choice_descr[]{ "Action a", "Action b",
                                "Action c", "Action d",
                                "Quit"
                              };
constexpr int SIZE = sizeof(choices) / sizeof(choices[0]);

int main()
{
    char choice;
    while( show_menu(choices, choice_descr, SIZE),
           (choice = get_choice(">> ",
                        "Invalid input. Please enter a, b, c, d, q")) != 'q'){
        // use choice to execute an action
    }
    cout << "Bye" << endl;
    return 0;
}


void show_menu(const char* choices, const char** choice_descr, int size)
{
    cout << "Please enter one of the following choices:\n";
    for(int i=0; i<size; ++i){
        cout << choices[i] <<") " << choice_descr[i] << endl;
    }
}

char get_choice(const char* prompt, const char* invalid_prompt)
{
    char ch;
    while( cout << prompt ){
        if( cin >> ch && !is_valid(ch, choices, SIZE) ){
            cout << invalid_prompt << endl;
            // clear stdin
            while(cin.get() != '\n')
                ;
        }else{
            while(cin.get() != '\n')
                ;
            return ch;
        }
    }
}

bool is_valid(char input, const char* valid, int size)
{
    for(int i=0; i<size; ++i){
        if(input == valid[i])
            return true;
    }
    return false;
}
