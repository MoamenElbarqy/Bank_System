#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include "HeaderScreen.h"

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
    static void GoBackToMainMenue();
    static void ShowAllClientsScreen();
    static void ShowAddNewClientsScreen();
    static void ShowDeleteClientScreen();
    static void ShowUpdateClientScreen();
    static void ShowFindClientScreen();
    static void ShowTransactionsMenue();
    static void ShowManageUsersMenue();
    static void ShowLoginRegisterScreen();
    static void ShowShowCurrencyExchangeMenue();
    static void Logout();
    static void PerfromMainMenueOptions(MainMenuChoices choice);

public:
    static void ShowMainMenueScreen();
};

#endif MAINSCREEN_H