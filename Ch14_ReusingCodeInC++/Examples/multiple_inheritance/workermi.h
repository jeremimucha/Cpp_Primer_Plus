// workermi.h -- working classes with MI
#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>
#include <iostream>


class Worker
{
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker()
        : fullname("no one")
        , id(0L)
        { std::cout << "--> Worker()\n"; }
    Worker(const std::string& s, long n)
        : fullname(s)
        , id(n)
        { std::cout << "--> Worker(const string&, long)\n"; }
    virtual ~Worker() = 0;      // pure virtual destructor
    virtual void Set() = 0;
    virtual void Show() const = 0;
};


// virtual base class will be inherited once if two derived classes
// are inherited in a multiple-inheritance scenario by a 'third-generation'
// derived class (deriving from the derived classes).
// This means that the 'third-generation' derived class will contain only one
// base class subobject
class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter()
        : Worker()
        , panache(0)
        { std::cout << "--> Waiter()\n"; }
    Waiter(const std::string& s, long n, int p=0)
        : Worker(s, n)
        , panache(p)
        { std::cout << "--> Waiter(const string&, long, int)\n"; }
    Waiter(const Worker& wk, int p=0)
        : Worker(wk)
        , panache(p)
        { std::cout << "--> Waiter(const Worker&, int)\n"; }
    ~Waiter()
        { std::cout << "--> ~Waiter()\n"; }
    void Set();
    void Show() const;
};


class Singer : virtual public Worker
{
protected:
    enum { other, alto, contralto, soprano, bass, baritone, tenor };
    enum { Vtypes=7 };
    void Data() const;
    void Get();
private:
    static const char* pv[Vtypes];    // string equivs of voice types
    int voice;
public:
    Singer()
        : Worker()
        , voice(other)
        { std::cout << "--> Singer()\n"; }
    Singer(const std::string& s, long n, int v=other )
        : Worker(s, n)
        , voice(v)
        { std::cout << "--> Singer(const string&, long, int)\n"; }
    Singer(const Worker& wk, int v=other)
        : Worker(wk)
        , voice(v)
        { std::cout << "--> Singer(const Worker&, int)\n"; }
    ~Singer()
        { std::cout << "--> ~Singer()\n"; }
    void Set();
    void Show() const;
};


// multiple inheritance
class SingingWaiter : public Waiter, public Singer
{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter()
        { std::cout << "--> SingingWaiter()\n"; }
    SingingWaiter(const std::string& s, long n, int p=0, int v=other)
        : Worker(s, n)      // need to call the virtual base class constructor explicitly
        , Waiter(s, n, p)   // base classes won't call the virtually-inherited base class
        , Singer(s, n, v)   // i.e. Waiter and Singer won't call Worker(s, n) like
                            // they would in non-virtual inheritance scenario
        { std::cout << "--> SingingWaiter(const string&, long, int, int)\n"; }
    SingingWaiter(const Waiter& wt, int v=other)
        : Worker(wt)        // implicitly upcast to Worker type
        , Waiter(wt)
        , Singer(wt, v)     // implicitly upcast to Worker type
        { std::cout << "--> SingingWaiter(const Waiter&, int)\n"; }
    SingingWaiter(const Singer& sr, int p=0)
        : Worker(sr)        // implicitly upcast to Worker type
        , Waiter(sr, p)     // implicitly upcast to Worker type
        , Singer(sr)
        { std::cout << "--> SingingWaiter(const Singer&, int)\n"; }
    ~SingingWaiter()
        { std::cout << "--> ~SingingWaiter()\n"; }
    void Set();
    void Show() const;
};


#endif /*WORKERMI_H_*/
