#pragma once
#include <iostream>
#include "HeaderScreen.h"
#include "../Client/ClientsList.h"
#include "../Client/AddClient.h"
#include "../Client/DeleteClient.h"
#include "../Client/UpdateClient.h"
#include "../Client/FindClient.h"
#include "../Transactions/Transactions.h"
#include "../User/MangeUsers.h"
#include "../Misc/LoginLog.h"
#include "../Currency/CurrencyExchange.h"
#include "../Misc/Global.h"
#include "../Misc/Input.h"
using namespace std;

class MainScreen : private HeaderScreen
{
private:
    enum MainMenuChoices
    {
        ShowClientList = 1,
        AddNewClient = 2,
        DeleteClient = 3,
        UpdateClient = 4,
        FindClient = 5,
        Transactions = 6,
        MangeUsers = 7,
        LoginLog = 8,
        CurrencyExchange = 9,
        SystemLogout = 10
    };
    static void GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenueScreen();
    }
    static void ShowAllClientsScreen()
    {
        ClientList::ShowClientsListScreen();
    }

    static void ShowAddNewClientsScreen()
    {
        AddClient::AddNewClient();
    }

    static void ShowDeleteClientScreen()
    {
        DeleteClient::Delete();
    }

    static void ShowUpdateClientScreen()
    {
        UpdateClient::Update();
    }

    static void ShowFindClientScreen()
    {
        FindClient::FindClientScreen();
    }

    static void ShowTransactionsMenue()
    {
        Transactions::ShowTransactionsScreen();
    }

    static void ShowManageUsersMenue()
    {
        MangeUsers::ShowMangeUsersScreen();
    }
    static void ShowLoginRegisterScreen()
    {
        LoginLog::ShowLoginRegisterScreen();
    }
    static void ShowShowCurrencyExchangeMenue()
    {
        CurrencyExchange::ShowCurrencyExchangeScreen();
    }
    static void Logout()
    {
        SystemUser = User::Find(""); // Make The System User Empty Until The User Loged In Again
    }
    static void PerfromMainMenueOptions(MainMenuChoices choice)
    {
        switch (choice)
        {
        case MainMenuChoices::ShowClientList:
            system("cls");
            ShowAllClientsScreen();
            GoBackToMainMenue();
            break;
        case MainMenuChoices::AddNewClient:
            system("cls");
            ShowAddNewClientsScreen();
            GoBackToMainMenue();
            break;
        case MainMenuChoices::DeleteClient:
            system("cls");
            ShowDeleteClientScreen();
            GoBackToMainMenue();
            break;
        case MainMenuChoices::UpdateClient:
            system("cls");
            ShowUpdateClientScreen();
            GoBackToMainMenue();
            break;
        case MainMenuChoices::FindClient:
            system("cls");
            ShowFindClientScreen();
            GoBackToMainMenue();
            break;
        case MainMenuChoices::Transactions:
            system("cls");
            ShowTransactionsMenue();
            GoBackToMainMenue();
            break;
        case MainMenuChoices::MangeUsers:
            system("cls");
            ShowManageUsersMenue();
            GoBackToMainMenue();
            break;
        case MainMenuChoices::LoginLog:
            system("cls");
            ShowLoginRegisterScreen();
            GoBackToMainMenue();
            break;
        case MainMenuChoices::CurrencyExchange:
            system("cls");
            ShowShowCurrencyExchangeMenue();
            GoBackToMainMenue();
            break;
        case MainMenuChoices::SystemLogout:
            system("cls");
            Logout();
            break;
        }
    }

public:
    static void ShowMainMenueScreen()
    {
        system("cls");
        DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "Choose What Do you Want to Do :";

        PerfromMainMenueOptions((MainMenuChoices)Input::ReadNumberBetween(1, 10));
    }
};