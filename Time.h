#ifndef TIME_CLASS
#define TIME_CLASS
#include <string>

class Time 
{
public:
    Time(); 
    Time(int h, int m, int s);
    Time(std::string time);
    bool is_am();
    std::string to_string (bool const twelve_format = 0);
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    //Time operator + (Time & rhs);
    Time operator + (int const rhs);
    Time operator + (int lhs, Time const & rhs);
    Time operator - (int rhs);



private:
    int hour{};
    int minute{};
    int second{};
    void assignTime(int h, int m, int s);
    void checkIllegalString(std::string time); 
    std::string formatString(int h, int m, int s); 
};

#endif