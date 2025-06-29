#ifndef DATE_H
#define DATE_H

#include <string>
#include <ctime>
using namespace std;

class Date
{
public:
    static string current_date_in_days_months_years();
    static string current_time();
};

#endif // DATE_H