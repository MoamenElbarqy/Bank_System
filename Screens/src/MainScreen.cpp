#include "MainScreen.h"
#include <iostream>
#include <iomanip>
using namespace std;

void MainScreen::GoBackToMainMenue()
{
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";
    system("pause>0");
    ShowMainMenueScreen();
}

void MainScreen::ShowAllClientsScreen()
{
    ClientList::ShowClientsListScreen();
}

void MainScreen::ShowAddNewClientsScreen()
{
    AddClient::AddNewClient();
}

void MainScreen::ShowDeleteClientScreen()
{
    DeleteClient::Delete();
}

void MainScreen::ShowUpdateClientScreen()
{
    UpdateClient::Update();
}

void MainScreen::ShowFindClientScreen()
{
    FindClient::FindClientScreen();
}

void MainScreen::ShowTransactionsMenue()
{
    Transactions::ShowTransactionsScreen();
}

void MainScreen::ShowManageUsersMenue()
{
    MangeUsers::ShowMangeUsersScreen();
}

void MainScreen::ShowLoginRegisterScreen()
{
    LoginLog::ShowLoginRegisterScreen();
}

void MainScreen::ShowShowCurrencyExchangeMenue()
{
    CurrencyExchange::ShowCurrencyExchangeScreen();
}

void MainScreen::Logout()
{
    SystemUser = User::Find(""); // Make The System User Empty Until The User Loged In Again
}

void MainScreen::PerfromMainMenueOptions(MainMenuChoices choice)
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

void MainScreen::ShowMainMenueScreen()
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