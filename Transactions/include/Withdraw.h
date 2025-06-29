#ifndef WITHDRAW_H
#define WITHDRAW_H
#include "Client.h"
#include "HeaderScreen.h"


class WithDarw : private HeaderScreen
{
private:
	static void Print(Client MyClient);

public:
	static void WithdrawClient();
};

#endif  WITHDRAW_H