#include "Time.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

/*bool is_digits(std::string str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}*/

int main()
{   
    std::istringstream istream{"89 2 3"};
    Time time{};
    istream >> time;
    std::cout << time << std::endl;
    
    
    
    
    
    
    /*Time t0{};
    Time t1 = t0++ ++;
    std::cout << t0.get_second() << std::endl;
    std::cout << t1.get_second() << std::endl;*/
    
    /*Time time{1,2,3};
    Time t0 = 3 + time;
    std::cout << t0.get_second() << std::endl;*/
    /*std::string time_str{};
    int hour{11};
    int minute{34};
    time_str = std::to_string(hour - 1) + ":" + std::to_string(minute);
    std::cout << time_str << std::endl;*/

    //string clock{"14:45:34e"};
    //cout << clock.length();
    //Time test{"14:35:34"};
    /*Time empty{};
    if (empty.get_hour() == 5)
    {
        cout << "det var 0" << endl;
    }else{
        cout << "det var inte 0" <<endl;
    }*/


    /*std::string time = "1d-30:54";
    
    std::string hour_str{time.substr(0,2)};
    std::string colon_str1{time.substr(2,1)};
    std::string minute_str{time.substr(3,2)};
    std::string colon_str2{time.substr(5,1)};
    std::string second_str{time.substr(6,2)};
    
    std::cout << is_digits(hour_str) << std::endl;
    std::cout << !std::all_of(hour_str.begin(), hour_str.end(), ::isdigit) << std::endl;

    bool check{std::all_of(hour_str.begin(), hour_str.end(), ::isdigit)};
    std::cout << check << std::endl;

    std::cout<< hour_str << std::endl;
    if (!check)
    {
        std::cout << "Det funkade!" << std::endl;
    }
    std::string colon{":"};
    bool colon_check1{colon.find(colon_str1) != std::string::npos};
    if (!colon_check1)
    {
        std::cout << "Hittade inte kolon!" << std::endl;
    }*/
    /*if (time.length != 8)
    {
        throw time;
    }else if (time.substr(0,2))*/
    
    return 0;
};
