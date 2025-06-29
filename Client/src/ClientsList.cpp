#pragma once
#include <iomanip>
#include "Client.h"
#include "Global.h"
#include "HeaderScreen.h"

using namespace std;

class ClientList : private HeaderScreen
{
public:
    static void ShowClientsListScreen()
    {
        if (!hasAccess(User::UsersPermission::ListClients))
            return; // This Will Show Access Denied Screen Internaly

        vector<Client> MyClients = Client::LoadDataClientsFromFile();
        string subTitle = "(" + to_string(MyClients.size()) + ")" + " clinet(s)";
        if (MyClients.size() == 0)
            subTitle = "No Clients Available";
        DrawScreenHeader("\tClients List Screen ", subTitle);

        cout << "\t---------------------------------------------------------------------------------------------------------\n";
        cout << "\t|Account Number   | Pin Code  |  Client Name      | Phone          |       Email                | Balance \n";
        cout << "\t---------------------------------------------------------------------------------------------------------\n";
        for (Client CurrentClient : MyClients)
        {
            cout << "\t|" << setw(17) << left << CurrentClient.GetAccNumber();
            cout << "|" << setw(11) << left << CurrentClient.GetPinCode();
            cout << "|" << setw(19) << left << CurrentClient.GetFirstName() + " " + CurrentClient.GetLastName();
            cout << "|" << setw(16) << left << CurrentClient.GetPhoneNumber();
            cout << "|" << setw(28) << left << CurrentClient.GetEmail();
            cout << "|" << setw(7) << left << CurrentClient.GetBalance();
            cout << endl;
        }
        cout << "\t---------------------------------------------------------------------------------------------------------\n";
    }
};