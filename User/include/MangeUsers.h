#ifndef MANAGEUSERS_H
#define MANAGEUSERS_H

#include "HeaderScreen.h"
#include "Global.h"

class MangeUsers : private HeaderScreen
{
private:
    enum ManageUsersChoices
    {
        ListUsers = 1,
        AddNewUser = 2,
        DeleteUser = 3,
        UpdateUser = 4,
        FindUser = 5,
        MainMenu = 6
    };
    static void GoBackToManageUsersMenue();
    static void ShowListUsersScreen();
    static void ShowAddNewUserScreen();
    static void ShowDeleteUserScreen();
    static void ShowUpdateUserScreen();
    static void ShowFindUserScreen();
    static void PerfromManageUsersMenueOptions(ManageUsersChoices choice);

public:
    static void ShowMangeUsersScreen();
};

#endif  // MANAGEUSERS_H