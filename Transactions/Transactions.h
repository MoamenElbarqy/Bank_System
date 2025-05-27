#pragma once
#include <iomanip>
#include "../Screens/HeaderScreen.h"
#include "../Misc/Input.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "TotalBalances.h"
#include "Transfer.h"
#include "TransferLog.h"
#include "../Misc/Global.h"
#include "../User/User.h"
using namespace std;

class Transactions : private HeaderScreen
{
private:
	static void GoBackToTranactionsMenue()
	{

		cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowTransactionsScreen();
	}
	static void ShowDepositScreen()
	{
		Deposit::DepositClient();
	}
	static void ShowWithdraw()
	{
		WithDarw::WithdrawClient();
	}
	static void ShowTotalBalances()
	{
		TotalBalacnes::TotalBalances();
	}
	static void ShowTransferScreen()
	{
		Transfer::ShowTransferScreen();
	}
	static void ShowTransferLogScreen()
	{
		TransferLog::ShowTransferLog();
	}
	enum TransactionType
	{
		Deposit = 1,
		Withdraw = 2,
		TotalBalances = 3,
		Transfer = 4,
		TransferLog = 5,
		MainMenu = 6
	};
	static void PerfromTransactionsMenueOptions(TransactionType choice)
	{
		switch (choice)
		{
		case TransactionType::Deposit:
			system("cls");
			ShowDepositScreen();
			GoBackToTranactionsMenue();
			break;
		case TransactionType::Withdraw:
			system("cls");
			ShowWithdraw();
			GoBackToTranactionsMenue();
			break;
		case TransactionType::TotalBalances:
			system("cls");
			ShowTotalBalances();
			GoBackToTranactionsMenue();
			break;
		case TransactionType::Transfer:
			system("cls");
			ShowTransferScreen();
			GoBackToTranactionsMenue();
			break;
		case TransactionType::TransferLog:
			system("cls");
			ShowTransferLogScreen();
			GoBackToTranactionsMenue();
			break;
		}
	}

public:
	static void ShowTransactionsScreen()
	{
		if (!hasAccess(User::UsersPermission::Transactions))
			return; // This Will Show Access Denied Screen Internaly

		system("cls");
		DrawScreenHeader("\tTransactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Data.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "Choose What Do you Want to Do :";

		PerfromTransactionsMenueOptions((TransactionType)Input::ReadNumberBetween(1, 6));
	}
};