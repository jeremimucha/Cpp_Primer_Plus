// useless.cpp -- an otherwise useless class with move sematics
#include <iostream>
using namespace std;


// interface
class Useless
{
private:
    int n;          // number of elements
    char* pc;       // pointer to data
    static int ct;  // number of objects
    void ShowObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless& f);      // regular copy constructor
    Useless(Useless&& f);           // move constructor
    ~Useless();
    Useless operator+(const Useless& f) const;
// need operator=() in copy and move versions
    void ShowData() const;
};

// implementation
int Useless::ct = 0;

Useless::Useless()
    : n(0), pc(nullptr)
{
    ++ct;
    cout << "--> Useless() called; num of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k)
    : n(k), pc(new char[n])
{
    ++ct;
    cout << "--> Useless(int) called; num of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k, char ch)
    : n(k), pc(new char[n])
{
    ++ct;
    for(int i=0; i<n; ++i)
        pc[i] = ch;
    cout << "--> Useless(int, char) called; num of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(const Useless& f)
    : n(f.n), pc(new char[n])
{
    ++ct;
    for(int i=0; i<n; ++i)
        pc[i] = f.pc[i];
    cout << "--> Useless(const Useless&) called; num of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(Useless&& f)
    : n(f.n), pc(f.pc)  // steal data address
{
    // ct unaffected
    f.n = 0;            // old object empty
    f.pc = nullptr;     // null data
    cout << "--> Useless(Useless&&) called; num of objects: " << ct << endl;
    ShowObject();
}

Useless::~Useless()
{
    cout << "--> ~Useless() called; objects left: " << --ct << endl;
    cout << "deleted object:\n";
    ShowObject();
    delete[] pc;
}

Useless Useless::operator+(const Useless& f) const
{
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for(int i=0; i<n; ++i){
        temp.pc[i] = pc[i];
    }
    for(int i=n; i<temp.n; ++i)
        temp.pc[i] = f.pc[i-n];
    cout << "temp object:\n";
    cout << "Leaving operator+()\n";
    return temp;
}

void Useless::ShowObject() const
{
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void*)pc << endl;

}

void Useless::ShowData() const
{
    if(n == 0)
        cout << "(object empty)";
    else
        for(int i=0; i<n; ++i)
            cout << pc[i];
    cout << endl;
}


// application
int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;          // calls copy constructor
        Useless three(20, 'o');
        Useless four(one + three);  // calls operator+(), move constructor
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        cout << "object three: ";
        three.ShowData();
        cout << "object four: ";
        four.ShowData();
    }
    return 0;
}
