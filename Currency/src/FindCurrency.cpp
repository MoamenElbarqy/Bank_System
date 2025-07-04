#include "FindCurrency.h"
#include <iostream>
#include "Input.h"
using namespace std;

void FindCurrencuey::Print(Currency MyCurrency)
{
    cout << "\nCurrency Data:";
    cout << "\n___________________";
    cout << "\nCountry       : " << MyCurrency.GetCountryName();
    cout << "\nCode          : " << MyCurrency.GetCode();
    cout << "\nCurrency Name : " << MyCurrency.GetCurrencyName();
    cout << "\nRate          : " << MyCurrency.GetRate();
    cout << "\n___________________\n";
}

void FindCurrencuey::ShowFindCurrencueyScreen()
{
    Currency MyCuurency;
    DrawScreenHeader("\tFind Currencuey Screen");

    cout << "Find By Country Code [1] or Country Name [2] : ";
    short UserChoice = Input::ReadNumberBetween(1, 2);
    switch (UserChoice)
    {
    case 1:
    {
        cout << "Please Enter Country Code : ";
        string CountryCode = Input::ReadString();

        CountryCode = Util::UpperAll(CountryCode);

        MyCuurency = Currency::FindByCode(CountryCode);

        if (MyCuurency.isEmpty())
        {
            cout << "\n===============================\n";
            cout << " Currency is Not Found :-(\n";
            cout << "================================\n";
        }
        else
        {
            Print(MyCuurency);
        }
        break;
    }

    case 2:

    {
        cout << "Please Enter Country Name : ";
        string CountryName = Input::ReadString();

        CountryName = Util::UpperAll(CountryName);

        MyCuurency = Currency::FindByName(CountryName);

        if (MyCuurency.isEmpty())
        {
            cout << "\n===============================\n";
            cout << " Currency is Not Found :-(\n";
            cout << "===============================\n";
        }
        else
        {
            Print(MyCuurency);
        }
        break;
    }
    }
} 