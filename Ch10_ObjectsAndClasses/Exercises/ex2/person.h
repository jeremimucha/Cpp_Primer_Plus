// person.h -- chapter 10 pe2
#ifndef PERSON_H_
#define PERSON_H_
#include <string>


class Person
{
private:
    static const int LIMIT = 25;
    std::string lname;       // Person's last name
    char fname[LIMIT];  // Person's first name
public:
    Person()
        :lname("")
        { fname[0] = '\0'; }
    Person(const std::string& ln, const char* fn="Heyyou")
        :lname(ln)
        {
            int i{0};
            for(; i<LIMIT && fn[i]; ++i)
                fname[i] = fn[i];
            for(; i<LIMIT; ++i)
                fname[i] = '\0';
        }
// the following methods display lname and fname
    void Show() const;          // firstname lastname format
    void FormalShow() const;    // lastname, firstname format
};

#endif /* PERSON_H_ */
