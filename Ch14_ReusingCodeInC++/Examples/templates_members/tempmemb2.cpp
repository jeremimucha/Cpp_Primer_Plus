// tempmemb.cpp -- template members - defining outside of class
#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;


template<typename T>
class beta
{
private:
    template<typename V>    // nested template class member declaration
    class hold;
    hold<T> q;      // template object
    hold<int> n;    // template object
public:
    beta(T t, int i)
        : q(t), n(i)
        { std::cout << "--> beta(" << typeid(T).name() << ", int)\n"; }
    
    template<typename U>    // template method declaration
    U blab(U u, T t);
    void Show() const
        { q.show(); n.show(); }
};


// nested template class member definition
template<typename T>
template<typename V>
class beta<T>::hold
{
Private:
    V val;
public:
    hold(V v=0)
        : val(v)
        { std::cout << "--> hold(" << typeid(V).name() << ")\n"; }
    void show() const
        { cout << val << endl; }
    V Value() const
        { return val; }
};

// template method definition
template<typename T>
template<typename U>
U beta<T>::blab(U u, T t)
{
    return (n.Value() + q.Value()) * u / t;
}


int main()
{
    beta<double> guy(3.5, 3);
    cout << "T was set to double\n";
    guy.Show();
    cout << "V was set to T, which is double, then V was set to int\n";
    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int\n";
    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double\n";
    cout << "Done\n";
    return 0;
}
