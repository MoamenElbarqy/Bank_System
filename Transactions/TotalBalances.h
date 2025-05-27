#pragma once
#include <vector>
#include <iomanip>
#include "../Screens/HeaderScreen.h"
#include "../Client/Client.h"
#include "../Misc/Global.h"

using namespace std;

class TotalBalacnes : private HeaderScreen
{
private:
public:
    static void TotalBalances()
    {
        vector<Client> vMyClients = Client::LoadDataClientsFromFile();

        string subTitle = "   (" + to_string(vMyClients.size()) + ")" + " clinet(s)";
        DrawScreenHeader("\tTotal Balances Screen", subTitle);

        cout << "\t\t\t\t========================================\n";
        cout << "\t\t\t\t\t" << "Total Balances is : $" << Client::CountTotalBalances(vMyClients) << endl;
        cout << "\t\t\t\t========================================\n";

        cout << "\t--------------------------------------------------------------------------------------------\n";
        cout << "\t|          Account Number             |            Client Name           |      Balance     \n";
        cout << "\t--------------------------------------------------------------------------------------------\n";
        if (vMyClients.size() == 0)
        {
            cout << "\t\tNo Clients Available\n";
        }
        else
        {
            for (Client CurrentClient : vMyClients)
            {
                cout << "\t|" << setw(37) << left << CurrentClient.GetAccNumber();
                cout << "|" << setw(19 + 15) << left << CurrentClient.GetFirstName() + " " + CurrentClient.GetLastName();
                cout << "|" << setw(17) << left << CurrentClient.GetBalance();
                cout << endl;
            }
        }
        cout << "\t--------------------------------------------------------------------------------------------\n";
    }
};