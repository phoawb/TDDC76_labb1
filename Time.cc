#include "Time.h"
#include <string>

Time::Time()
: hour{0}, minute{0}, second{0}
{   
}
/*Time::Time(int hour, int minute, int second)
: hour{hour}, minute{minute}, second{second}
{
}*/
Time::Time(int hour, int minute, int second)
{
    if (hour < 0|| minute < 0 || second < 0)
    {
        throw "Tid kan ej vara negativ!"
    } else if (hour ) // fortsätt skriva if här! 
}
int Time::get_hour()
{
    return hour;
}

int Time::get_minute()
{
    return minute;
}

int Time::get_second()
{
    return second;
}


