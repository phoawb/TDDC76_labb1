#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
    Time empty{};
    if (empty.get_hour() == 5)
    {
        cout << "det var 0" << endl;
    }else{
        cout << "det var inte 0" <<endl;
    }
    return 0;
};
