#include "UsersList.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void UsersList::ShowUsersListScreen()
{
    vector<User> MyUsers = User::LoadDataUsersFromFile();
    string subTitle = "  (" + to_string(MyUsers.size()) + ")" + " clinet(s)";
    if (MyUsers.size() == 0)
        subTitle = "No Users Available";
    DrawScreenHeader("\tUsers List Screen ", subTitle);

    cout << "\t--------------------------------------------------------------------------------------------------\n";
    cout << "\t|    UserName     |    Full Name         |     Phone      |       Email           |  Permissions  \n";
    cout << "\t--------------------------------------------------------------------------------------------------\n";
    for (User CurrentUser : MyUsers)
    {
        cout << "\t|" << setw(17) << left << CurrentUser.GetUserName();
        cout << "|" << setw(22) << left << CurrentUser.GetFirstName() + " " + CurrentUser.GetLastName();
        cout << "|" << setw(16) << left << CurrentUser.GetPhoneNumber();
        cout << "|" << setw(23) << left << CurrentUser.GetEmail();
        cout << "|" << setw(14) << left << CurrentUser.GetPermissions();
        cout << endl;
    }
    cout << "\t--------------------------------------------------------------------------------------------------\n";
} 