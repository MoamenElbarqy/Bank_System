#pragma once
#include "../Screens/HeaderScreen.h"
#include "../Misc/Input.h"
#include "../Client/Client.h"
#include "../Misc/Global.h"
using namespace std;

class DeleteClient : private HeaderScreen
{
private:
    static void Print(Client MyClient)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << MyClient.GetFirstName();
        cout << "\nLastName    : " << MyClient.GetLastName();
        cout << "\nFull Name   : " << MyClient.GetFirstName() + " " + MyClient.GetLastName();
        cout << "\nEmail       : " << MyClient.GetEmail();
        cout << "\nPhone       : " << MyClient.GetPhoneNumber();
        cout << "\nAccount Number : " << MyClient.GetAccNumber();
        cout << "\nPassword    : " << MyClient.GetPinCode();
        cout << "\nBalance     : " << MyClient.GetBalance();
        cout << "\n___________________\n";
    }

public:
    static void Delete()
    {
        if (!hasAccess(User::UsersPermission::DeleteClient))
            return; // This Will Show Access Denied Screen Internaly

        DrawScreenHeader("\tDelete Client Screen");

        cout << "Please Enter Account Number You Want To Delete :";
        string AccountNumber = Input::ReadString();

        if (!Client::isClientExisted(AccountNumber))
        {
            cout << "\n===============================\n";
            cout << " Client is not found :-)\n";
            cout << "===============================\n";
            return;
        }
        Client Client = Client::Find(AccountNumber);
        Print(Client);

        if (Util::ContinueOperation())
        {
            if (Client.Delete())
            {
                cout << "\n===============================\n";
                cout << " Client Deleted Successfully :-)\n";
                cout << "===============================\n";
            }
        }
        else
        {
            cout << "\n===============================\n";
            cout << " Client Deleted Denied :-(\n";
            cout << "===============================\n";
        }
    }
};