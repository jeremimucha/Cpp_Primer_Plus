// rw2.cpp -- Chapter 14 review question 2
#include <iostream>
#include <cstring>


class Frabjous
{
private:
    char fab[20];
public:
    Frabjous(const char* s="C++")
        {
            std::strncpy(fab, s, 20-1);
            fab[20-1] = '\0';
        }
    virtual void tell()
        { std::cout << fab; }
};

class Gloam
{
private:
    int glip;
    Frabjous fb;
public:
    Gloam(int g=0, const char* s="C++")
        : glip(g), fb(s) { }
    Gloam(int g, const Frabjous& f)
        : glip(g), fb(f) { }
    void tell()
        {
            fb.tell();
            std::cout <<", " << glip;
        }
};


int main()
{
    Frabjous f1;
    Frabjous f2("Foobar");
    Gloam g1(42, "BarFoo");
    Gloam g2(11, f1);
    std::cout << "f1: ";
    f1.tell();
    std::cout << "\nf2: ";
    f2.tell();
    std::cout << "\ng1: ";
    g1.tell();
    std::cout << "\ng2: ";
    g2.tell();
}
