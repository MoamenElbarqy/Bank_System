#include "CurrencyExchange.h"
#include <iostream>
#include <iomanip>
using namespace std;

void CurrencyExchange::BackToCurrencyExchangeScreen()
{
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Currency Exchange Menue...\n";
    system("pause>0");
    ShowCurrencyExchangeScreen();
}

void CurrencyExchange::PerfromCurrencyExchangeOptions(CurrencyChoices Choice)
{
    switch (Choice)
    {
    case CurrencyExchange::ListCurrencies:
        system("cls");
        CurrenciesList::ShowListCurrenciesScreen();
        BackToCurrencyExchangeScreen();
        break;
    case CurrencyExchange::FindCurrencuey:
        system("cls");
        FindCurrencuey::ShowFindCurrencueyScreen();
        BackToCurrencyExchangeScreen();
        break;
    case CurrencyExchange::UpdateRate:
        system("cls");
        UpdateRate::ShowUpdateRateScreen();
        BackToCurrencyExchangeScreen();
        break;
    case CurrencyExchange::CurrencyCalculator:
        system("cls");
        CurrencyCalculator::ShowCurrencyCalculatorScreen();
        BackToCurrencyExchangeScreen();
        break;
    }
}

void CurrencyExchange::ShowCurrencyExchangeScreen()
{
    system("cls");
    if (!hasAccess(User::UsersPermission::AddClient))
        return; // Acceess Check
    DrawScreenHeader("Currency Exchange Main Screen");

    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\tCurrency Exchange Menue\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
    cout << setw(37) << left << "" << "\t[2] Find Currencuey.\n";
    cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
    cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
    cout << setw(37) << left << "" << "\t[5] Main Screen.\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "Choose What Do you Want to Do :";

    PerfromCurrencyExchangeOptions((CurrencyChoices)Input::ReadNumberBetween(1, 5));
} 