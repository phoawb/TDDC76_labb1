#include "Time.h"
#include <string>
#include <iostream>

Time::Time()
: hour{0}, minute{0}, second{0}
{   
};
Time::Time(int h, int m, int s)
{
    Time::assignTime(h, m, s);
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
void Time::assignTime(int h, int m, int s)
{
    try
    {
        if (h < 0 || h > 23)
        {
            std::cout << "I AM throwing hour! ";
            throw h;
        } else if (m < 0 || m > 59)
        {
            std::cout << "I AM throwing minute! ";
            throw m;
        } else if (s < 0 || s > 59)
        {
            std::cout << "I AM throwing second! ";
            throw s;
        }
        hour = h; 
        minute = m;
        second = s;
    }
    catch(int exception)
    {
        std::cout << "Illegal time entered: " << exception << std::endl;
    }
    
}