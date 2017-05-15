// mytime1.h -- Time class before operator overloading
#ifndef MYTIME2_H_
#define MYTIME2_H_


class Time
{
private:
    int hours;
    int minutes;
public:
    Time()
        :hours(0), minutes(0) { }
    Time(int h, int m=0)
        :hours(h), minutes(m) { }
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h=0, int m=0);
    Time operator+(const Time& t) const;    // operator overloading function
    Time operator-(const Time& t) const;
    Time operator*(double n) const;
    void Show() const;
};


#endif /* MYTIME_H_ */
