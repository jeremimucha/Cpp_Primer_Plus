// ifelse.cpp -- using the if else statement
#include <iostream>


int main()
{
    char ch;

    std::cout << "Type, and I shall repeat.\n";

    while(std::cin.get(ch) && ch != '.'){
        if(ch == '\n')
            std::cout << ch;
        else
            std::cout << ++ch;
            // ch + 1 would have the result promoted to int,
            // thus displaying a string of ints
    }

    std::cout << "\nPlease excuse the slight confusion.\n";

    return 0;
}