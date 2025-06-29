#include "UpdateUser.h"
#include <iostream>
using namespace std;

void UpdateUser::ReadUserInfo(User &User)
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

        if (Util::ContinueOperation("\nDo You Want To Give Access To Show List Clients Screen (y / n) : "))
            permissions += User::UsersPermission::ListClients;
        if (Util::ContinueOperation("\nDo You Want To Give Access To Add New Client Screen (y / n) : "))
            permissions += User::UsersPermission::AddClient;
        if (Util::ContinueOperation("\nDo You Want To Give Access To Delete Client Screen  (y / n) : "))
            permissions += User::UsersPermission::DeleteClient;
        if (Util::ContinueOperation("\nDo You Want To Give Access To Update Client Screen  (y / n) : "))
            permissions += User::UsersPermission::UpdateClient;
        if (Util::ContinueOperation("\nDo You Want To Give Access To Find Client Screen (y / n) : "))
            permissions += User::UsersPermission::FindClient;
        if (Util::ContinueOperation("\nDo You Want To Give Access To Transactions Screen (y / n) : "))
            permissions += User::UsersPermission::Transactions;
        if (Util::ContinueOperation("\nDo You Want To Give Access To Mange Users Screen (y / n) : "))
            permissions += User::UsersPermission::MangeUsers;

        User.SetPermissions(permissions);
    }
}

void UpdateUser::Print(User MyUser)
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

void UpdateUser::Update()
{
    DrawScreenHeader("\tUpdate User Screen");
    string UserName = "";
    cout << "Please Enter User Name : ";
    UserName = Input::ReadString();

    while (!User::isUserExisted(UserName))
    {
        cout << "User is not Found , Enter a valid one : ";
        UserName = Input::ReadString();
    }

    User Client = User::Find(UserName);
    Print(Client);
    cout << "\nUpdate Info:\n";
    cout << "---------------\n";
    ReadUserInfo(Client);

    if (Util::ContinueOperation())
    {
        if (Client.Save())
        {

            cout << "\n===============================\n";
            cout << " User Updated Successfully :-)\n";
            cout << "===============================\n";
            Print(Client);
        }
        else
        {

            cout << "\n=======================================\n";
            cout << " User Was't Saved Because It's Empty :-(\n";
            cout << "=======================================\n";
        }
    }
    else
    {
        cout << "\n========================\n";
        cout << " Operation Denied :-(\n";
        cout << "========================\n";
    }
} 