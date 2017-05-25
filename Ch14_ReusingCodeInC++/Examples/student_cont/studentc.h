// studentc.h -- defining a Student class using containment
#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray>


class Student
{
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;       // contained object
    ArrayDb scores;
    // private method for scores output
    std::ostream& arr_out(std::ostream& os) const;

public:
    Student()
        : name("Null Student")
        , scores()
        { std::cout << "--> Student()\n"; }
    explicit Student(const std::string& s)
        : name(s)
        , scores()
        { std::cout << "--> Student(const std::string&)\n"; }
    explicit Student(int n)
        : name("Nully")
        , scores(n)
        { std::cout << "--> Student(int)\n"; }
    Student(const std::string& s, const ArrayDb& a)
        : name(s)
        , scores(a)
        { std::cout << "--> Student(const std::string&, const ArrayDb&)\n"; }
    Student(const char* str, const double* pd, int n)
        : name(str)
        , scores(pd, n)
        { std::cout << "--> Student(const char*, const double*, int)\n"; }
    ~Student()
        { std::cout << "--> ~Student()\n"; }
    double Average() const;
    const std::string& Name() const
        { return name; }
    double& operator[](int i);
    double operator[](int i) const;

// friends
    // input
    friend std::istream& operator>>(std::istream& is, Student& stu);    // 1 word
    friend std::istream& getline(std::istream& is, Student& stu);   // 1 line

    // output
    friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};


#endif /*STUDENT_H_*/
