#ifndef CURRENCYEXCHANGE_H
#define CURRENCYEXCHANGE_H

#include "HeaderScreen.h"
#include "CurrencyCalculator.h"


class CurrencyExchange : private HeaderScreen
{
private:
    enum CurrencyChoices
    {
        ListCurrencies = 1,
        FindCurrencuey = 2,
        UpdateRate = 3,
        CurrencyCalculator = 4,
        MainScreen = 5
    };
    static void BackToCurrencyExchangeScreen();
    static void PerfromCurrencyExchangeOptions(CurrencyChoices Choice);

public:
    static void ShowCurrencyExchangeScreen();
};

#endif // CURRENCYEXCHANGE_H