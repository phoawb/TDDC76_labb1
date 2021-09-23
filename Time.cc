#include "Time.h"  
#include "Time.h"  
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <stdexcept>

/* -- --- --
 * Komplettering: Ni har en stor mängd kodupprepning i er kod. 
 * Detta gäller framförallt kod ni använder i era 
 * operatoröverlagningsfunktioner (ex. operator+(...)).
 * Flytta ut denna kod till en egen funktion för att undvika 
 * onödig kodupprepning.
 * 
 * Komplettering: Ni dubbelinkluderar vissa headers. Tänk på att headers som 
 * inkluderas i en headerfil som i sin tur inkluderas i er .cc-fil blir 
 * att inkluderas automatiskt i .cc-filen. 
 * Ex. inkluderas <string> både i .h och i .cc för time.
 * 
 * Komplettering: Variabler i konstruktorn MÅSTE initialiseras genom 
 * konstruktorns datamedlemsinitieringslista (initializer list).
 * Just nu initialiseras variablerna på ett icke-säkert sätt.
 * Tips: Det är möjligt att initialisera en variabel till ett värde
 * med en specifik variabeltyp för att sedan tilldela variabeln ett annat 
 * värde i konstruktorns body.
 * 
 * Kommentar: Otroligt bra kod i övrigt - lättöverskådlig, lättförståelig,
 * med i regel bra variabelnamngivning. Fokusera på att eliminera kodupprepning
 * och fortsätt håll denna kvalité så kommer det gå strålande 
 * fortsättningsvis för er. 
 * -- --- -- */

// Assigna 0 till alla tider i klassen
Time::Time()
: hour{0}, minute{0}, second{0}
{   
}

// Ta in tre integers och lägg till de till klassen om de är inom tillåtet spann för tid
Time::Time(int h, int m, int s)
{
    Time::assignTime(h, m, s);
}

// Ta in en sträng och omvandla den till integers för klassen om den är på rätt format (hh:mm:ss)
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

int Time::get_hour() const
{
    return hour;
}

int Time::get_minute() const
{
    return minute;
}

int Time::get_second() const
{
    return second;
}

// kolla om tiderna är olagliga och kasta de isåfall, annars lägg till de i klassen
void Time::assignTime(int h, int m, int s)
{
    if (h < 0 || h > 23)
    {
        throw std::logic_error("Timmar måste vara mellan 0-23!");
    } else if (m < 0 || m > 59)
    {
        throw std::logic_error("Minuter måste vara mellan 0-59!");
    } else if (s < 0 || s > 59)
    {
        throw std::logic_error("Sekunder måste vara mellan 0-59!");
    }
    hour = h; 
    minute = m;
    second = s;
}

// Ta in en sträng och kasta om den inte är på det exakta formatet "hh:mm:ss"
void Time::checkIllegalString(std::string time) const
{   
    if (time.length() != 8) // kasta strängen om den inte är rätt längd
    {
        throw std::logic_error("Tiden måste anges på formatet hh:mm:ss");
    }
    
    bool hour_check{std::all_of(time.begin(), time.end() - 6, ::isdigit)}; // Kolla om varje visare bara innehåller siffor
    bool minute_check{std::all_of(time.begin() + 3, time.end() - 3, ::isdigit)};
    bool second_check{std::all_of(time.begin() + 6, time.end(), ::isdigit)};
    std::string colon{":"}; // Kolla om det är kolon mellan visarna
    bool colon_check1{colon.find(time.substr(2,1)) != std::string::npos};
    bool colon_check2{colon.find(time.substr(5,1)) != std::string::npos};

    if (!hour_check) // kasta om tiden var felaktigt angiven
    {
        throw std::logic_error("Timvisaren får bara innehålla siffor!");
    } else if (!minute_check)
    {
        throw std::logic_error("Minutvisaren får bara innehålla siffor!");
    } else if (!second_check)
    {
        throw std::logic_error("Sekundvisaren får bara innehålla siffor!");
    } else if (!colon_check1 || !colon_check2)
    {
        throw std::logic_error("Det måste vara kolon mellan tiderna!");
    }
}

// returnera true om hour < 12 (det är förmiddag)
bool Time::is_am() const
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
std::string Time::to_string (bool const twelve_format) const
{
    std::string time_str{};
    if (twelve_format) // formatera 12h-formatet
    {
        if (hour < 12)
        {
            if (hour == 0)
            {
                time_str = formatString(hour + 12) + "am";
            }else
            {
                time_str = formatString(hour) + "am";
            }
        }else
        {
            if (hour == 12)
            {
                time_str = formatString(hour) + "pm";
            }else
            {
                time_str = formatString(hour - 12) + "pm";
            }
        }
    }else // formatera 24h-formatet 
    {
        time_str = formatString(hour);
    }
    return time_str;
}

// Kommentar: Ni tar endast in en variabel h, och verkar plocka resterande
// variabler från objektets privata variabler - är detta tanken?
// Ta in tre integers (h, m, s) och returnera en sträng på hh:mm:ss format 
std::string Time::formatString(int h) const
{
    std::string time_string{};
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << h;
    ss << ":";
    ss << std::setw(2) << std::setfill('0') << minute;
    ss << ":";
    ss << std::setw(2) << std::setfill('0') << second;
    ss >> time_string;
    return time_string;
}

// Addera med en integer på höger sida och returnera ett nytt tidsobjekt med adderade tider
Time Time::operator+(int const rhs)
{
    int second2{0};
    int minute2{0};
    int hour2{0};

    int total_time = hour*3600 + minute*60 + second + rhs; // Lägg allting till sekunder efter midnatt
    if (total_time >= 0) // om positivt omvandla till respektive tid och kör relevant modulo
    {
        second2 = total_time % 60;
        minute2 = (total_time/60) % 60;
        hour2 = (total_time/3600) % 24;
    } else // om negativt, gör först om till positiva sekunder efter midnatt
    {
        total_time = 86400 + (total_time % 86400);
        second2 = total_time % 60;
        minute2 = (total_time/60) % 60;
        hour2 = (total_time/3600) % 24;
    }

    Time time2{hour2, minute2, second2};
    return time2;
}

// Addera med en integer på vänster sida och returnera ett nytt tidsobjekt med adderade tider
Time operator+(int lhs, Time const & rhs)
{
    int second2{0};
    int minute2{0};
    int hour2{0};

    int total_time = rhs.get_hour()*3600 + rhs.get_minute()*60 + rhs.get_second() + lhs; // Lägg allting till sekunder efter midnatt
    if (total_time >= 0) // om positivt omvandla till respektive tid och kör relevant modulo
    {
        second2 = total_time % 60;
        minute2 = (total_time/60) % 60;
        hour2 = (total_time/3600) % 24;
    } else // om negativt, gör först om till positiva sekunder efter midnatt
    {
        total_time = 86400 + (total_time % 86400);
        second2 = total_time % 60;
        minute2 = (total_time/60) % 60;
        hour2 = (total_time/3600) % 24;
    }

    Time time2{hour2, minute2, second2};
    return time2;
}

Time Time::operator-(int rhs)
{
    int second2{0};
    int minute2{0};
    int hour2{0};

    int total_time = hour*3600 + minute*60 + second - rhs; // Lägg allting till sekunder efter midnatt
    if (total_time >= 0) // om positivt omvandla till respektive tid och kör relevant modulo
    {
        second2 = total_time % 60;
        minute2 = (total_time/60) % 60;
        hour2 = (total_time/3600) % 24;
    } else // om negativt, gör först om till positiva sekunder efter midnatt
    {
        total_time = 86400 + (total_time % 86400);
        second2 = total_time % 60;
        minute2 = (total_time/60) % 60;
        hour2 = (total_time/3600) % 24;
    }

    Time time2{hour2, minute2, second2};
    return time2;
}

Time operator-(int lhs, Time const & rhs)
{
    int second2{0};
    int minute2{0};
    int hour2{0};

    int total_time = lhs - rhs.get_hour()*3600 - rhs.get_minute()*60 - rhs.get_second(); // Lägg allting till sekunder efter midnatt
    if (total_time < 0) // om negativt, gör först om till positiva sekunder efter midnatt 
    {
        total_time = 86400 + (total_time % 86400);
        second2 = total_time % 60;
        minute2 = (total_time/60) % 60;
        hour2 = (total_time/3600) % 24;
    } else // om positivt omvandla till respektive tid och kör relevant modulo
    {
        second2 = total_time % 60;
        minute2 = (total_time/60) % 60;
        hour2 = (total_time/3600) % 24;
    }

    Time time2{hour2, minute2, second2};
    return time2;
}

Time& Time::operator++()
{   
    ++second;
    minute = minute + second/60;
    hour = hour + minute/60;
    second = second % 60;
    minute = minute % 60;
    hour = hour % 24;

    return *this;
}

Time Time::operator++(int)
{
    const Time old = *this;
    ++(*this);
    return old;
}

Time& Time::operator--()
{   
    --second;
    int total_time = hour*3600 + minute*60 + second; // Lägg allting till sekunder efter midnatt
    if (total_time >= 0) // om positivt omvandla till respektive tid och kör relevant modulo
    {
        second = total_time % 60;
        minute = (total_time/60) % 60;
        hour = (total_time/3600) % 24;
    } else // om negativt, gör först om till positiva sekunder efter midnatt
    {
        total_time = 86400 + (total_time % 86400);
        second = total_time % 60;
        minute = (total_time/60) % 60;
        hour = (total_time/3600) % 24;
    }

    return *this;
}

Time Time::operator--(int)
{
    Time old = *this;
    --(*this);
    return old;
}

bool Time::operator<(Time const & rhs)
{   
    int time_lhs = hour*3600 + minute*60 + second;
    int time_rhs = rhs.get_hour()*3600 + rhs.get_minute()*60 + rhs.get_second();

    return time_lhs < time_rhs;
}

bool Time::operator>(Time const & rhs)
{
    int time_lhs = hour*3600 + minute*60 + second;
    int time_rhs = rhs.get_hour()*3600 + rhs.get_minute()*60 + rhs.get_second();

    return time_lhs > time_rhs;
}

bool Time::operator<=(Time const & rhs)
{
    int time_lhs = hour*3600 + minute*60 + second;
    int time_rhs = rhs.get_hour()*3600 + rhs.get_minute()*60 + rhs.get_second();

    return time_lhs <= time_rhs;
}

bool Time::operator>=(Time const & rhs)
{
    int time_lhs = hour*3600 + minute*60 + second;
    int time_rhs = rhs.get_hour()*3600 + rhs.get_minute()*60 + rhs.get_second();

    return time_lhs >= time_rhs;
}

bool Time::operator==(Time const & rhs)
{
    int time_lhs = hour*3600 + minute*60 + second;
    int time_rhs = rhs.get_hour()*3600 + rhs.get_minute()*60 + rhs.get_second();

    return time_lhs == time_rhs;
}

bool Time::operator!=(Time const & rhs)
{
    int time_lhs = hour*3600 + minute*60 + second;
    int time_rhs = rhs.get_hour()*3600 + rhs.get_minute()*60 + rhs.get_second();

    return time_lhs != time_rhs;
}

std::ostream& operator<<(std::ostream& os, Time const & time)
{
    os << time.to_string();
    return os;
}

std::istream& operator>>(std::istream& is, Time & time) {
std::string time_str{};
is >> time_str;
time = Time{time_str};
return is; 
}
