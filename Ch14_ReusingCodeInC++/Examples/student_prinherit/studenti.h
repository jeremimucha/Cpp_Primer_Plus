// studentc.h -- defining a Student class using containment
#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <iostream>
#include <string>
#include <valarray>


class Student : private std::string, private std::valarray<double>
{
private:
    typedef std::valarray<double> ArrayDb;

    // no explicit contained objects; 
    // uses string and valarray<double> subobjects internally

    // private method for scores output
    std::ostream& arr_out(std::ostream& os) const;

public:
    Student()
        : std::string("Null Student")
        , ArrayDb()
        { std::cout << "--> Student()\n"; }
    explicit Student(const std::string& s)
        : std::string(s)
        , ArrayDb()
        { std::cout << "--> Student(const std::string&)\n"; }
    explicit Student(int n)
        : std::string("Nully")
        , ArrayDb(n)
        { std::cout << "--> Student(int)\n"; }
    Student(const std::string& s, const ArrayDb& a)
        : std::string(s)
        , ArrayDb(a)
        { std::cout << "--> Student(const std::string&, const ArrayDb&)\n"; }
    Student(const char* str, const double* pd, int n)
        : std::string(str)
        , ArrayDb(pd, n)
        { std::cout << "--> Student(const char*, const double*, int)\n"; }
    ~Student()
        { std::cout << "--> ~Student()\n"; }
    double Average() const;
    const std::string& Name() const
        { return (const std::string&)*this; }

    // define operators
    double& operator[](int i);
    double operator[](int i) const;
    // or bring the base class operator into scope
    // using std::valarray<double>::operator[];

// friends
    // input
    friend std::istream& operator>>(std::istream& is, Student& stu);    // 1 word
    friend std::istream& getline(std::istream& is, Student& stu);   // 1 line

    // output
    friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};


#endif /*STUDENTI_H_*/
