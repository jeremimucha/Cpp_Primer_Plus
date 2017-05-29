//  manyfrnd.cpp -- unbound template friend to a template class
#include <iostream>
using std::cout;
using std::endl;


template<typename T>
class ManyFriend
{
private:
    T item;
public:
    ManyFriend(const T& i)
        : item(i)
        { }
    
    template<typename C, typename D> friend void show2(C&, D&);
};

template<typename C, typename D>
void show2(C& c, D& d)
{
    cout << c.item << ", " << d.item << endl;
}


int main()
{
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);
    cout << "hfi1, hfi2: ";
    // template< ManyFriend<int>, ManyFriend<int> >
    // show< ManyFriend<int>, ManyFriend<int> >(ManyFriend<int>& c, ManyFriend<int>& d)
    show2(hfi1, hfi2);
    cout << "hfdb, hfi2: ";
    // template< ManyFriend<double>, ManyFriend<int> >
    // show< ManyFriend<double>, ManyFriend<int> >(ManyFriend<double>& c, ManyFriend<int>& d)
    show2(hfdb, hfi2);
}
