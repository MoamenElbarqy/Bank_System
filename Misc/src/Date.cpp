#include "Date.h"
#include <string>
#include <ctime>
using namespace std;

string Date::current_date_in_days_months_years()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
}

string Date::current_time()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
} 