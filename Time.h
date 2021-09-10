#ifndef TIME_CLASS
#define TIME_CLASS
#include <string>

class Time 
{
public:
    Time(); 
    Time(int hour, int minute, int second);
    int get_hour();
    int get_minute();
    int get_second();

private:
    int hour{};
    int minute{};
    int second{};
};

#endif