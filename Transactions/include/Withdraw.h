#ifndef WITHDRAW_H
#define WITHDRAW_H

#include "HeaderScreen.h"
#include "Global.h"
#include "../Client/Client.h"
#include "../Misc/Input.h"
using namespace std;

class WithDarw : private HeaderScreen
{
private:
	static void Print(Client MyClient);

public:
	static void WithdrawClient();
};

#endif // WITHDRAW_H