#ifndef UPDATERATE_H
#define UPDATERATE_H

#include "HeaderScreen.h"
#include "Currency.h"

class UpdateRate : private HeaderScreen
{
private:
	static void PrintCurrency(Currency MyCurrency);
public:
	static void ShowUpdateRateScreen();
};

#endif // UPDATERATE_H