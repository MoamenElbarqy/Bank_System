#include <iostream>
#include "Transactions.h"
#include "Input.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "TotalBalances.h"
#include "Transfer.h"
#include "TransferLog.h"
#include "Global.h"
#include "User.h"
using namespace std;

void Transactions::GoBackToTranactionsMenue()
{
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";
    system("pause>0");
    ShowTransactionsScreen();
}

void Transactions::ShowDepositScreen()
{
    Deposit::DepositClient();
}

void Transactions::ShowWithdraw()
{
    WithDarw::WithdrawClient();
}

void Transactions::ShowTotalBalances()
{
    TotalBalacnes::TotalBalances();
}

void Transactions::ShowTransferScreen()
{
    Transfer::ShowTransferScreen();
}

void Transactions::ShowTransferLogScreen()
{
    TransferLog::ShowTransferLog();
}

void Transactions::PerfromTransactionsMenueOptions(TransactionType choice)
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

void Transactions::ShowTransactionsScreen()
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