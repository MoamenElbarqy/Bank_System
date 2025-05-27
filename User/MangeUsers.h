#pragma once
#include <iomanip>
#include "../Screens/HeaderScreen.h"
#include "UsersList.h"
#include "AddUser.h"
#include "DeleteUser.h"
#include "UpdateUser.h"
#include "FindUser.h"
#include "../Misc/Input.h"
#include "../Misc/Global.h"
using namespace std;

class MangeUsers : private HeaderScreen
{
private:
    enum MangeUsersMenueOptions
    {
        ShowUsersList = 1,
        AddNewUser = 2,
        DeleteUser = 3,
        UpdateUser = 4,
        FindUser = 5,
        MainMenue = 8
    };
    static void BackToMangeUsersScreen()
    {
        cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Mange Users Menue...\n";
        system("pause>0");
        ShowMangeUsersScreen();
    }
    static void ShowUsersListScreen()
    {
        UsersList::ShowUsersListScreen();
    }
    static void ShowAddNewUsersScreen()
    {
        AddUser::AddNewUser();
    }
    static void ShowDeleteUsersScreen()
    {
        DeleteUser::Delete();
    }
    static void ShowUpdateUsersScreen()
    {
        UpdateUser::Update();
    }
    static void ShowFindUsersScreen()
    {
        FindUser::FindUserScreen();
    }
    static void PerfromMangeUsersOptions(MangeUsersMenueOptions Choice)
    {
        switch (Choice)
        {
        case MangeUsers::ShowUsersList:
        {
            system("cls");
            ShowUsersListScreen();
            BackToMangeUsersScreen();
            break;
        }
        case MangeUsers::AddNewUser:
        {
            system("cls");
            ShowAddNewUsersScreen();
            BackToMangeUsersScreen();
            break;
        }
        case MangeUsers::DeleteUser:
        {
            system("cls");
            ShowDeleteUsersScreen();
            BackToMangeUsersScreen();
            break;
        }
        case MangeUsers::UpdateUser:
        {
            system("cls");
            ShowUpdateUsersScreen();
            BackToMangeUsersScreen();
            break;
        }
        case MangeUsers::FindUser:
        {
            system("cls");
            ShowFindUsersScreen();
            BackToMangeUsersScreen();
            break;
        }
        }
    }

public:
    static void ShowMangeUsersScreen()
    {
        if (!hasAccess(User::UsersPermission::MangeUsers))
            return; // This Will Show Access Denied Screen Internaly

        system("cls");
        DrawScreenHeader("\t\tMange Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMange Users\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show User List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "Choose What Do you Want to Do :";

        PerfromMangeUsersOptions((MangeUsersMenueOptions)Input::ReadNumberBetween(1, 6));
    }
};