// exc_mean.h -- exception classes for hmean(), gmean()
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>


class bad_mean : public std::logic_error
{
private:
    double v1, v2;
    std::string info;
protected:
    double V1() const { return v1; }
    double V2() const { return v2; }
public:
    bad_mean(const char* msg, double a=0, double b=0)
        : std::logic_error(msg), v1(a), v2(b)
        {
            std::ostringstream oss;
            oss << logic_error::what() << ": a = " << v1 <<", b = " << v2 << '.';
            info = oss.str();
        }
    const char* what() const noexcept;
};

inline const char* bad_mean::what() const noexcept
{
    return info.c_str();
}


class bad_hmean : public bad_mean
{
public:
    bad_hmean(double a=0, double b=0, const char* msg="Bad arguments to hmean()")
        : bad_mean(msg, a, b) { }
};

class bad_gmean : public bad_mean
{
public:
    bad_gmean(double a=0, double b=0, const char* msg="Bad arguments to gmean()")
        : bad_mean(msg, a, b) { }
};


#endif /*EXC_MEAN_H_*/
