#include "MangeUsers.h"
#include <iostream>
#include <iomanip>
#include "UsersList.h"
#include "AddUser.h"
#include "DeleteUser.h"
#include "UpdateUser.h"
#include "FindUser.h"
#include "Input.h"
using namespace std;

void MangeUsers::GoBackToManageUsersMenue()
{
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Mange Users Menue...\n";
    system("pause>0");
    ShowMangeUsersScreen();
}

void MangeUsers::ShowListUsersScreen()
{
    UsersList::ShowUsersListScreen();
}

void MangeUsers::ShowAddNewUserScreen()
{
    AddUser::AddNewUser();
}

void MangeUsers::ShowDeleteUserScreen()
{
    DeleteUser::Delete();
}

void MangeUsers::ShowUpdateUserScreen()
{
    UpdateUser::Update();
}

void MangeUsers::ShowFindUserScreen()
{
    FindUser::FindUserScreen();
}

void MangeUsers::PerfromManageUsersMenueOptions(ManageUsersChoices choice)
{
    switch (choice)
    {
    case MangeUsers::ListUsers:
    {
        system("cls");
        ShowListUsersScreen();
        GoBackToManageUsersMenue();
        break;
    }
    case MangeUsers::AddNewUser:
    {
        system("cls");
        ShowAddNewUserScreen();
        GoBackToManageUsersMenue();
        break;
    }
    case MangeUsers::DeleteUser:
    {
        system("cls");
        ShowDeleteUserScreen();
        GoBackToManageUsersMenue();
        break;
    }
    case MangeUsers::UpdateUser:
    {
        system("cls");
        ShowUpdateUserScreen();
        GoBackToManageUsersMenue();
        break;
    }
    case MangeUsers::FindUser:
    {
        system("cls");
        ShowFindUserScreen();
        GoBackToManageUsersMenue();
        break;
    }
    }
}

void MangeUsers::ShowMangeUsersScreen()
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

    PerfromManageUsersMenueOptions((ManageUsersChoices)Input::ReadNumberBetween(1, 6));
} 