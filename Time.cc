#ifndef TIME_CLASS
#define TIME_CLASS
#include "Time.h"

Time::Time()
: hour{0}, minute{0}, second{0}
{   
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

#endif
