// golf.h -- chapter 10 pe3
#ifndef GOLF_H_
#define GOLF_H_


class Golf
{
private:
    static const int LEN{40};
    char fullname[LEN];
    int handicap;
public:
    Golf(bool interactive=false);
    Golf(const char* name, int hc)
        : handicap(hc)
        {
            std::cout << "Called Golf(" << name<<','<<hc<<")\n";
            int i{0};
            for(; i<LEN && name[i]; ++i)
                fullname[i] = name[i];
            for(; i<LEN; ++i)
                fullname[i] = '\0';
        }
    void set_handicap(int hc){ handicap = hc; }
    void show() const;
};


#endif /*GOLF_H_*/
