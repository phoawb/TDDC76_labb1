#ifndef TIME_CLASS
#define TIME_CLASS
#include <string>

class Time 
{
public:
    Time(); 
    Time(int h, int m, int s);
    Time(std::string time);
    void assignTime(int h, int m, int s); // Hur kan jag göra denna privat? 
    void checkIllegalString(std::string time);
    int get_hour();
    int get_minute();
    int get_second();

private:
    int hour{};
    int minute{};
    int second{};
};

#endif