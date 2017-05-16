// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_


class Stonewt
{
private:
    enum {Lbs_per_stn = 14};        // pounds per stone
    int stone;                      // whole stones
    double pds_left;                // fractional pounds
    double pounds;                  // entire weight in pounds
public:
    Stonewt(double lbs)             // constructor for double pounds
        :stone( int(lbs) / Lbs_per_stn )
        ,pds_left( int(lbs) % Lbs_per_stn + lbs - int(lbs) )
        ,pounds( lbs )
        { }
    Stonewt(int stn, double lbs)   // constructor for stone, lbs
        :stone(stn)
        ,pds_left(lbs)
        ,pounds(stn * Lbs_per_stn + lbs)
        { }
    Stonewt()
        :stone(0), pds_left(0), pounds(0) { }
    ~Stonewt() { }
    void show_lbs() const;          // show weight in pounds format
    void show_stn() const;          // show weight in stone format
// conversion functions
    operator int() const;
    operator double() const;
// chapter review #1
    Stonewt operator*(double n) const
        { return Stonewt(stone * n, pds_left * n); }
    friend Stonewt operator*(double n, const Stonewt& s)
        { return s * n; }
};


#endif /* STONEWT_H_ */
