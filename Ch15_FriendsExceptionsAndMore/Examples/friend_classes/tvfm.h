// tvfm.h -- Tv and Remote classes using a friend member
#ifndef TVFM_H_
#define TVFM_H_


class Tv;       // forward declaration

class Remote
{
private:
    int mode;
public:
    Remote(int m=Tv::TV)
        : mode(m)
        { }
    bool volup(Tv& t);  // prototype only
    bool voldown(Tv& t);
    void onoff(Tv& t);
    void chanup(Tv& t);
    void chandown(Tv& t);
    void set_chan(Tv& t, int c);
    void set_mode(Tv& t);
    void set_input(Tv& t);
};


class Tv
{
public:
    friend void Remote::set_chan(Tv& t, int c);    // Remote::set_chan function is a friend
    enum {Off, On};
    enum {MinVal, MaxVal=20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s=Off, int mc=125)
        : state(s), volume(5), maxchannel(mc)
        , channel(2), mode(Cable), input(TV)
        { }
    void onoff()
        { state = (state == On) ? Off : On; }
    bool ison() const
        { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode()
        { mode = (mode == Antenna) ? Cable : Antenna; }
    void set_input()
        { input = (input == TV) ? DVD : TV; }
    void settings() const;  // display all settings
private:
    int state;          // on or off
    int volume;         // assumed to be digitized
    int maxchannel;     // maximum number of channels
    int channel;        // current channel settings
    int mode;           // broadcast or cable
    int input;          // TV or DVD
};


// Remote methods as inline functions
inline bool Remote::volup(Tv& t) { return t.volup(); }
inline bool Remote::voldown(Tv& t) { return t.voldown(); }
inline void Remote::onoff(Tv& t) { t.onoff(); }
inline void Remote::chanup(Tv& t) { t.chanup(); }
inline void Remote::chandown(Tv& t) { t.chandown(); }
inline void Remote::set_mode(Tv& t) { t.set_mode(); }
inline void Remote::set_input(Tv& t) { t.set_input(); }
inline void Remote::set_chan(Tv& t, int c) { t.channel = c; }


#endif /*TVFM_H_*/
