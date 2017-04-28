// assign_st.cpp -- assigning structures
#include <iostream>
#include <typeinfo>


struct inflatable
{
    char name[20];
    float volume;
    double price;
};


int main()
{
    using namespace std;
    inflatable bouquet{"sunflowers", 0.20, 12.49};
    inflatable choice;

    cout << "bouquet: " << bouquet.name << " for $ " << bouquet.price
         << endl;

    choice = bouquet;

    cout << "choice: " << choice.name << " for $ " << choice.price
         << endl;

    cout << "\nAddresses:";
    cout << "\n&bouquet = " << &bouquet
         << "\n&choice = " << &choice
         << "\n&bouquet.name = " << &(bouquet.name)
         << "\n&choice.name = " << &(choice.name)
         << "\ntypeof(bouquet.name) = " << typeid(bouquet.name).name()
         << "\ntypeof(choice.name) = " << typeid(choice.name).name()
         << "\n&bouquet.name[0] = " << (int*)&(bouquet.name[0])
         << "\n&choice.name[0] = " << (int*)&(choice.name[0])
         << endl;

    return 0;
}
