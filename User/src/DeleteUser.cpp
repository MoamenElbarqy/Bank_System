#include "DeleteUser.h"
#include <iostream>
using namespace std;

void DeleteUser::Print(User MyUser)
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

void DeleteUser::Delete()
{
    DrawScreenHeader("\tDelete Users Screen");

    cout << "Please Enter User Name You Want To Delete :";
    string UserName = Input::ReadString();
    if (SystemUser.GetUserName() == UserName)
    {
        cout << "\n===============================\n";
        cout << " You Can't Delete the Current System User :-(\n";
        cout << "===============================\n";
        return;
    }
    if (!User::isUserExisted(UserName))
    {
        cout << "\n===============================\n";
        cout << " User is not found :-(\n";
        cout << "===============================\n";
        return;
    }
    User User = User::Find(UserName);
    Print(User);

    if (Util::ContinueOperation())
    {
        if (User.Delete())
        {
            cout << "\n===============================\n";
            cout << " User Deleted Sucssefully :-)\n";
            cout << "===============================\n";
        }
        else
        {
            cout << "\n===============================\n";
            cout << " User Deleted Denied :-(\n";
            cout << "===============================\n";
        }
    }
} 