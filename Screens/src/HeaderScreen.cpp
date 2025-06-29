#include "HeaderScreen.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void HeaderScreen::DrawScreenHeader(string Title, string subtitle)
{
    cout << "\t\t\t\t\t______________________________________";
    cout << "\n\n\t\t\t\t\t   " << Title;
    if (subtitle != "")
    {
        cout << "\n\t\t\t\t\t\t" << subtitle;
    }
    cout << "\n\t\t\t\t\t______________________________________\n";

    cout << "\n\t\t\t\t\tUser : " << SystemUser.GetUserName() << "\n";
    // Printing Day / Month / Year
    cout << "\n\t\t\t\t\tDate :" << Date::current_date_in_days_months_years() << "\n\n";
}

bool HeaderScreen::hasAccess(User::UsersPermission CurrentPermission)
{
    if (SystemUser.GetPermissions() == User::UsersPermission::All)
        return true;

    if ((CurrentPermission & SystemUser.GetPermissions()) == CurrentPermission)
        return true;

    DrawScreenHeader("Access Denied! Contact Your Admin.");
    return false;
} 