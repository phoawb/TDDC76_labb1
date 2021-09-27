#ifndef TIME_CLASS
#define TIME_CLASS
#include <string>
#include <iostream>

class Time 
{
public:
    Time(); 
    Time(int h, int m, int s);
    Time(std::string time);
    Time( int seconds_after_midnight);
    bool is_am() const;
    std::string to_string (bool const twelve_format = 0) const;
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    Time operator + (int const & rhs) const; 
    Time operator - (int const & rhs) const;
    Time& operator ++ ();
    Time operator ++ (int);
    Time& operator -- ();
    Time operator -- (int);

    /* Komplettering: const (korrekt) angivet i implementationsfil men ej i 
     * headerfil för nedanstående medlemsfunktioner. */
    bool operator == (Time const & rhs) const;
    bool operator < (Time const & rhs) const; 
    
    bool operator > (Time const & rhs) const;
    bool operator <= (Time const & rhs) const; 
    bool operator >= (Time const & rhs) const;
    bool operator != (Time const & rhs) const;


private:
    int hour{};
    int minute{};
    int second{};

    // Kommentar: Snyggt med privata medlemsfunktioner som endast
    // syftar till intern användning för andra medlemsfunktioner.
    // Tack <3
    void assignTime(int h, int m, int s);
    void checkIllegalString(std::string time) const; 
    std::string formatString(int h) const; 
};

Time operator + (int lhs, Time const & rhs);
Time operator - (int lhs, Time const & rhs);
std::ostream& operator << (std::ostream& os, Time const & time);
std::istream& operator >> (std::istream& is, Time & time);

#endif