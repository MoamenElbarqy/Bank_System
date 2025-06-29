#include "FindUser.h"
#include <iostream>
using namespace std;

void FindUser::Print(User MyUser)
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

void FindUser::FindUserScreen()
{
    DrawScreenHeader("\tFind Users Screen");
    cout << "Please Enter UserName : ";
    string UserName = Input::ReadString();
    if (!User::isUserExisted(UserName))
    {
        cout << "\n===============================\n";
        cout << " User Is't Found :-(\n";
        cout << "===============================\n";
    }
    else
    {
        User MyUser = User::Find(UserName);
        Print(MyUser);
    }
} 