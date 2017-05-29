// tmp2tmp.cpp -- template friends to a template class
#include <iostream>
using std::cout;
using std::endl;


// template prototypes
template<typename T> void counts();
template<typename T> void report(T&);

// template class
template<typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT& i)
        : item(i)
        { ++ct; }
    ~HasFriendT()
        { --ct; }
    // declare functions as friends
    friend void counts<TT>();
    // why not this?
    // friend void counts<HasFriend<TT>>();
    friend void report<>(HasFriendT<TT>&);
    // or
    // friend void report< HasFriend<TT> >(HasFriend<TT>&);
};

// initalize the static varialbe
template<typename T>
int HasFriendT<T>::ct = 0;

// template friend functions definitions
template<typename T>
void counts()
{
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

// why not this?
/*template<typename T>    // T = HasFriend<?>
void counts()
{
    cout << "template size: " << sizeof(T) << "; ";
    cout << "template counts(): " << T::ct << endl;
}*/

template<typename T>
void report(T& hf)  // T == HasFriendT<TT> -- e.g. HasFriendT<int>, HasFriendT<double> etc.
{
    cout << hf.item << endl;
}


int main()
{
    counts<int>();
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);
    report(hfi1);   // generate report(HasFriendT<int>&);
    report(hfi2);   // generate report(HasFriendT<int>&);
    report(hfdb);   // generate report(HasFriendT<double>&);
    cout << "counts<int>() output:\n";
    counts<int>();
    cout << "conts<double>() output:\n";
    counts<double>();
}
