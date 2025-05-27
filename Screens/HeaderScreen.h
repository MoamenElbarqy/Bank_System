#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "../Misc/Global.h"
#include "../User/User.h"
#include "../Misc/Date.h"
using namespace std;

class HeaderScreen
{

protected:
    static void DrawScreenHeader(string Title, string subtitle = "")
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
    static bool hasAccess(User::UsersPermission CurrentPermission)
    {
        if (SystemUser.GetPermissions() == User::UsersPermission::All)
            return true;

        if ((CurrentPermission & SystemUser.GetPermissions()) == CurrentPermission)
            return true;

        DrawScreenHeader("Access Denied! Contact Your Admin.");
        return false;
    }
};