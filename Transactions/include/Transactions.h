#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <iomanip>
#include "HeaderScreen.h"
#include "Input.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "TotalBalances.h"
#include "Transfer.h"
#include "TransferLog.h"
#include "Global.h"
#include "User.h"
using namespace std;

class Transactions : private HeaderScreen
{
private:
	static void GoBackToTranactionsMenue();
	static void ShowDepositScreen();
	static void ShowWithdraw();
	static void ShowTotalBalances();
	static void ShowTransferScreen();
	static void ShowTransferLogScreen();
	enum TransactionType
	{
		Deposit = 1,
		Withdraw = 2,
		TotalBalances = 3,
		Transfer = 4,
		TransferLog = 5,
		MainMenu = 6
	};
	static void PerfromTransactionsMenueOptions(TransactionType choice);

public:
	static void ShowTransactionsScreen();
};

#endif // TRANSACTIONS_H