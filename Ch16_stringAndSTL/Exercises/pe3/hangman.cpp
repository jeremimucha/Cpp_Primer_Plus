// hangman.cpp -- some string methods
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
using std::string;


// const int NUM = 26;
// const string wordlist[NUM] ={"apiary", "beetle", "cereal",
//         "danger", "ensign", "florid", "garage", "health", "insult",
//         "jackal", "keeper", "loaner", "manage", "nonce", "onset",
//         "plaid", "quilt", "remote", "stolid", "train", "useful",
//         "valid", "whence", "xenon", "yearn", "zippy"};


int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    using std::endl;
    using std::vector;
    using std::copy;
    using std::back_insert_iterator;
    using std::istream_iterator;
    using std::ostream_iterator;
    std::srand(std::time(nullptr));

    std::ifstream ifs("words.txt");
    if(!ifs.is_open()){
        std::cerr << "Could not open the file.\n";
        exit(EXIT_FAILURE);
    }

    vector<string> wordlist;
    copy(istream_iterator<string, char>(ifs),
         istream_iterator<string, char>(),
         back_insert_iterator<vector<string>>(wordlist));
    int NUM = wordlist.size();
    cout << "Wordlist:\n";
    copy(wordlist.begin(), wordlist.end(),
         ostream_iterator<string, char>(cout, " "));

    char play;
    cout << "Will you play a word game? <y/n> ";
    // cin >> play;
    // play = tolower(play);
    while(cin >> play && tolower(play) == 'y' ){
        string target = wordlist[std::rand() % NUM];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my sevret word. It has " << length
             << " letters, and you guess\n"
             << "one letter at a time. You get " << guesses
             << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while(guesses > 0 && attempt != target){
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if(badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos){
                cout << "You already guesses that. Try again.\n";
                continue;
            }
            string::size_type loc = target.find(letter);
            if(loc == string::npos){
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            }
            else{
                cout << "Good guess!\n";
                attempt[loc] = letter;
                // check if letter appears again
                while( (loc = target.find(letter, loc+1)) != string::npos ){
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout << "Your word: " << attempt << endl;
            if( attempt != target){
                if(badchars.length() > 0){
                    cout << "Bad choices: " << badchars << endl;
                }
                cout << guesses << " bad guesses left\n";
            }
        }
        if(guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";
        
        cout << "Will you play another? <y/n> ";
    }

    cout << "Bye!\n";

    return 0;
}
