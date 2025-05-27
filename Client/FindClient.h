#pragma once
#include "../Screens/HeaderScreen.h"
#include "../Client/Client.h"
#include "../Misc/Input.h"
#include "../Misc/Global.h"
using namespace std;

class FindClient : private HeaderScreen
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
    static void FindClientScreen()
    {
        if (!hasAccess(User::UsersPermission::FindClient))
            return; // This Will Show Access Denied Screen Internaly

        DrawScreenHeader("\tFind Client Screen");
        cout << "Please Enter Client Account Number : ";
        string acc_number = Input::ReadString();
        if (!Client::isClientExisted(acc_number))
        {
            cout << "\n===============================\n";
            cout << " Account Number is not found :-(\n";
            cout << "===============================\n";
        }
        else
        {
            Client MyClient = Client::Find(acc_number);
            Print(MyClient);
        }
    }
};