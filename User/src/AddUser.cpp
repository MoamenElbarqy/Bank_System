#include "AddUser.h"
#include <iostream>
#include "Input.h"
using namespace std;

void AddUser::ReadUserInfo(User &User)
{
    cout << "Enter First Name : ";
    User.SetFirstName(Input::ReadString());

    cout << "Enter Last Name : ";
    User.SetLastName(Input::ReadString());

    cout << "Enter Email : ";
    User.SetEmail(Input::ReadString());

    cout << "Enter Phone : ";
    User.SetPhoneNumber(Input::ReadString());

    cout << "Enter Password : ";
    User.SetPassword(Input::ReadString());

    if (Util::ContinueOperation("\nDo You Want To Give Full Access (y / n): "))
    {
        User.SetPermissions(-1);
    }
    else
    {
        int permissions = 0;
        cout << "\nDo You Want To Give Access To :-\n";

        if (Util::ContinueOperation("\nShow List Clients Screen (y / n) : "))
            permissions |= User::UsersPermission::ListClients;

        if (Util::ContinueOperation("\nAdd New Client Screen (y / n) : "))
            permissions |= User::UsersPermission::AddClient;

        if (Util::ContinueOperation("\nDelete Client Screen  (y / n) : "))
            permissions |= User::UsersPermission::DeleteClient;

        if (Util::ContinueOperation("\nUpdate Client Screen  (y / n) : "))
            permissions |= User::UsersPermission::UpdateClient;

        if (Util::ContinueOperation("\nFind Client Screen  (y / n) : "))
            permissions |= User::UsersPermission::FindClient;

        if (Util::ContinueOperation("\nTransactions Screen (y / n) : "))
            permissions |= User::UsersPermission::Transactions;

        if (Util::ContinueOperation("\nMange Users Screen (y / n) : "))
            permissions |= User::UsersPermission::MangeUsers;

        if (Util::ContinueOperation("\nLogin Register Screen (y / n) : "))
            permissions |= User::UsersPermission::LoginLog;

        if (Util::ContinueOperation("\nCurrency Exchange Screen (y / n) : "))
            permissions |= User::UsersPermission::CurrencyExchange;

        User.SetPermissions(permissions);
    }
}

void AddUser::Print(User MyUser)
{
    cout << "\nClient Card:";
    cout << "\n___________________";
    cout << "\nFirstName   : " << MyUser.GetFirstName();
    cout << "\nLastName    : " << MyUser.GetLastName();
    cout << "\nFull Name   : " << MyUser.GetFirstName() + " " + MyUser.GetLastName();
    cout << "\nEmail       : " << MyUser.GetEmail();
    cout << "\nPhone       : " << MyUser.GetPhoneNumber();
    cout << "\nUsername    : " << MyUser.GetUserName();
    cout << "\nPermissions  : " << MyUser.GetPermissions();
    cout << "\n___________________\n";
}

void AddUser::AddNewUser()
{
    DrawScreenHeader("\t Add New User Screen");
    cout << "Enter User Name : ";
    string UserName = Input::ReadString();

    while (User::isUserExisted(UserName))
    {
        cout << "This User Already Existed , Enter a new one :";
        UserName = Input::ReadString();
    }
    User newUser = User::GetAddNewModeUser(UserName);

    ReadUserInfo(newUser);

    if (Util::ContinueOperation())
    {
        if (newUser.Save())
        {
            cout << "\n===============================\n";
            cout << " User Added Successfully :-)\n";
            cout << "===============================\n";
            Print(newUser);
        }
        else
        {
            cout << "\n===============================\n";
            cout << " We Can't Save Empty User :-(\n";
            cout << "===============================\n";
        }
    }
    else
    {
        cout << "\n===============================\n";
        cout << " Operation Denied :-(\n";
        cout << "===============================\n";
    }
} 