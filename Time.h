#include <string>

class Time 
{
public:
    Time(); 
    int get_hour();
    int get_minute();
    int get_second();

private:
    int hour{};
    int minute{};
    int second{};
};