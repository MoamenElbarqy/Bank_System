#ifndef FINDCURRENCY_H
#define FINDCURRENCY_H

#include "Currency.h"
#include "HeaderScreen.h"

class FindCurrencuey : public HeaderScreen
{
private:
    static void Print(Currency MyCurrency);

public:
    static void ShowFindCurrencueyScreen();
};

#endif  // FINDCURRENCY_H