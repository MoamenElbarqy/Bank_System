#include "UpdateRate.h"
#include <iostream>
using namespace std;

void UpdateRate::PrintCurrency(Currency MyCurrency)
{
    cout << "\nCurrency Card:";
    cout << "\n___________________";
    cout << "\nCountry       : " << MyCurrency.GetCountryName();
    cout << "\nCode          : " << MyCurrency.GetCode();
    cout << "\nCurrency Name : " << MyCurrency.GetCurrencyName();
    cout << "\nRate          : " << MyCurrency.GetRate();
    cout << "\n___________________\n";
}

void UpdateRate::ShowUpdateRateScreen()
{
    DrawScreenHeader("\tUpdate Rate Screen");

    cout << "Please Enter Currecy Code : ";
    string CurrencyCode = Input::ReadString();

    CurrencyCode = Util::UpperAll(CurrencyCode); // To Make It Case Insistive

    while (!Currency::isCurrencyExsisted(CurrencyCode))
    {
        cout << "We Can't Find The Currency, Please Enter a Valid Currency : ";
        CurrencyCode = Input::ReadString();
        CurrencyCode = Util::UpperAll(CurrencyCode);
    }
    Currency MyCurrency = Currency::FindByCode(CurrencyCode);
    PrintCurrency(MyCurrency);

    cout << "Please Enter New Rate : ";
    float newRate = Input::ReadFloatNumber();
    while (newRate <= 0)
    {
        cout << "The Rate of The Currency Can't be Negative Number, Enter a positive one : ";
        newRate = Input::ReadFloatNumber();
    }
    if (Util::ContinueOperation("Are You Sure Do You Want To Update Rate (y / n) : "))
    {
        MyCurrency.SetRate(newRate);
        PrintCurrency(MyCurrency);
    }
    else
    {
        cout << "\n===============================\n";
        cout << " Operation Denied :-(\n";
        cout << "===============================\n";
    }
} 