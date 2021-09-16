#include "Time.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

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
    checkIllegalString(time);
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

// Ta in en sträng och kasta om den inte är på det exakta formatet "hh:mm:ss"
void Time::checkIllegalString(std::string time)
{   
    if (time.length() != 8) // kasta strängen om den inte är rätt längd
    {
        throw time;
    }
    std::string hour_str{time.substr(0,2)}; // dela upp strängen i sifferdelar och kolon
    std::string colon_str1{time.substr(2,1)};
    std::string minute_str{time.substr(3,2)};
    std::string colon_str2{time.substr(5,1)};
    std::string second_str{time.substr(6,2)};
    
    // bool hour_check{std::all_of(time.begin(), time.end() - 6, ::isdigit)}; // Gör checkar för varje del av strängen
    bool minute_check{std::all_of(hour_str.begin(), hour_str.end(), ::isdigit)};
    bool second_check{std::all_of(hour_str.begin(), hour_str.end(), ::isdigit)};
    std::string colon{":"};
    bool colon_check1{colon.find(colon_str1) != std::string::npos};
    bool colon_check2{colon.find(colon_str2) != std::string::npos};

    if (!std::all_of(time.begin(), time.end() - 6, ::isdigit))
    {
        throw hour_str;
    } else if (!minute_check)
    {
        throw minute_str;
    } else if (!second_check)
    {
        throw second_str;
    } else if (!colon_check1 || !colon_check2)
    {
        throw;
    }
}

bool Time::is_am()
{   bool am_check{};
    if (hour < 12)
    {
        am_check = 1;
    }else
    {
        am_check = 0;
    }
    return am_check;
}

// ta in en bool och returnera en formaterad string på 12h- eller 24h-format
std::string Time::to_string (bool const twelveh_format)
{
    std::string time_str{};
    if (twelveh_format) // formatera 12h-formatet
    {
        if (hour < 12)
        {
            if (hour == 0)
            {
                time_str = formatString(hour + 12, minute, second) + "am";
            }else
            {
                time_str = formatString(hour, minute, second) + "am";
            }
        }else
        {
            if (hour == 12)
            {
                time_str = formatString(hour, minute, second) + "pm";
            }else
            {
                time_str = formatString(hour - 12, minute, second) + "pm";
            }
        }
    }else // formatera 24h-formatet 
    {
        time_str = formatString(hour, minute, second);
    }
    return time_str;
}

std::string Time::formatString(int h, int m, int s)
{
    std::string hour_str{};
    std::string minute_str{};
    std::string second_str{};
    if (h < 10)
    {
        hour_str = "0" + std::to_string(h);
    }else
    {
        hour_str = std::to_string(h);
    }
    if (m < 10)
    {
        minute_str = "0" + std::to_string(m);
    }else
    {
        minute_str = std::to_string(m);
    }
    if (s < 10)
    {
        second_str = "0" + std::to_string(s);
    }else
    {
        second_str = std::to_string(s);
    }
    return hour_str + ":" + minute_str + ":" + second_str;
}


    