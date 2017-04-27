// strings.cpp -- storing strings in an array
#include <iostream>
#include <cstring>      // for strlen() function


int getstrlen(char* str);


int main()
{
    using namespace std;

    constexpr int Size = 15;
    char name1[Size];
    char name2[Size] = "C++owboy";
    char name3[] = "25 character test string";
    

    cout << "Howdy! I'm " << name2
         << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << ", your name has "
         << getstrlen(name1) << " letters and is stored\n"
         << "in an array of " << sizeof(name1) << " bytes.\n"
         << "Your initial is "<< name1[0] <<".\n"
         << "strlen(name1) == " << strlen(name1)
         << "\nsizeof(name3) / sizeof(name3[0]) == " <<sizeof(name3) / sizeof(name3[0])
         << "\nname3[sizeof(name3)/sizeof(name3[0])-2] == " << name3[sizeof(name3)/sizeof(name3[0])-2]
         << endl;

    return 0;
}


int getstrlen(char* str)
{
    int len = 0;
    while( *str++ != '\0')
        ++len;
    
    return len;
}
