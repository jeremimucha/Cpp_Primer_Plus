// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>


class bad_hmean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a=0, double b=0, const char* msg="Bad arguments to hmean()")
        : std::logic_error(msg), v1(a), v2(b) { }
    void mesg();
    const char* what() const noexcept
        { return std::logic_error::what(); }
};

inline void bad_hmean::mesg()
{
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
              << "invalid arguments: a = -b\n";
}


class bad_gmean : public std::logic_error
{
public:
    double v1;
    double v2;
    bad_gmean(double a=0, double b=0, const char* msg="Bad arguments to gmean()")
        : std::logic_error(msg), v1(a), v2(b) { }
    const char* mesg();
    const char* what() const noexcept
        { return std::logic_error::what(); }
};

inline const char* bad_gmean::mesg()
{
    return "gmean() arguments should be >= 0\n";
}
