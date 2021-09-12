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

Time::Time(std::string time)
{
    std::string str_hour = time.substr(0,2); //lägg tiderna i en egen string och omvandla de till integers
    std::string str_minute = time.substr(3,2);
    std::string str_second = time.substr(6,2);
    int h = std::stoi(str_hour);
    int m = std::stoi(str_minute);
    int s = std::stoi(str_second);
    assignTime(h, m, s);
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

// kolla om tiderna är olagliga och kasta de isåfall, annars lägg till de i klassen
void Time::assignTime(int h, int m, int s)
{
    if (h < 0 || h > 23)
    {
        throw h;
    } else if (m < 0 || m > 59)
    {
        throw m;
    } else if (s < 0 || s > 59)
    {
        throw s;
    }
    hour = h; 
    minute = m;
    second = s;
}