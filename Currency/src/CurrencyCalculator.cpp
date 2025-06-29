#include "CurrencyCalculator.h"
#include <iostream>
using namespace std;

void CurrencyCalculator::ShowCurrencyCalculatorScreen()
{
    string Currency1 = "";
    string Currency2 = "";
    DrawScreenHeader("\tCurrency Calculator Screen");

    cout << "Enter Currency1 Code : ";
    Currency1 = Input::ReadString();
    while (!Currency::isCurrencyExsisted(Currency1))
    {
        cout << "Invalid Currency, Enter a Valid one : ";
        Currency1 = Input::ReadString();
    }
    Currency first_currency = Currency::FindByCode(Currency1);
    cout << "Enter Currency2 Code : ";
    Currency2 = Input::ReadString();

    while (!Currency::isCurrencyExsisted(Currency2))
    {
        cout << "Invalid Currency, Enter a Valid one : ";
        Currency2 = Input::ReadString();
    }
    Currency second_currency = Currency::FindByCode(Currency2);
    cout << "Please Enter Amount Of ExChange : ";
    float amount = Input::ReadFloatNumber();
    while (amount < 0)
    {
        cout << "You Can't Change Negative Number, Please Enter a Positive one : ";
        amount = Input::ReadFloatNumber();
    }
    float MoneyAfterExchange = amount / first_currency.GetRate() * second_currency.GetRate();
    // formatin the output to be like -> 1 Usd = 50 EGP
    cout << amount << " " << first_currency.GetCode() << " = " << MoneyAfterExchange << " " << second_currency.GetCurrencyName();
} 