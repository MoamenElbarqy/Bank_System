#ifndef TRANSFER_H
#define TRANSFER_H

#include "HeaderScreen.h"
#include "Global.h"
#include "../Misc/Input.h"
#include "../Client/Client.h"
using namespace std;

class Transfer : private HeaderScreen
{
private:
	static void Print(Client MyClient)
	{
		cout << "\nClient Card:";
		cout << "\n----------------------------";
		cout << "\nFull Name   : " << MyClient.GetFirstName() + " " + MyClient.GetLastName();
		cout << "\nAccount Number : " << MyClient.GetAccNumber();
		cout << "\nBalance     : " << MyClient.GetBalance();
		cout << "\n----------------------------\n";

	}
	static string ConvertDataTransferToRecord(Client TransferFrom, Client TransferTo, float Amount, string seprator = "#//#")
	{
		string record = "";
		record += Date::current_date_in_days_months_years() + seprator;
		record += Date::current_time() + seprator;
		record += TransferFrom.GetAccNumber() + seprator;
		record += TransferTo.GetAccNumber() + seprator;
		record += to_string(Amount) + seprator;
		record += to_string(TransferFrom.GetBalance()) + seprator;
		record += to_string(TransferTo.GetBalance()) + seprator;
		record += SystemUser.GetUserName();
		return record;
	}
	static void SaveTransferingOperation(Client TransferFrom, Client TransferTo, float Amount, string seprator = "#//#")
	{
		fstream MyFile;

		MyFile.open("TextFiles/TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << ConvertDataTransferToRecord(TransferFrom, TransferTo, Amount) << endl;
			MyFile.close();
		}
	}
	static void PrintTransfer(Client Sender, Client Receiver, float Amount)
	{
		cout << "\n===============================\n";
		cout << " Transfer Done Successfully :-)\n";
		cout << "===============================\n";

		Print(Sender); cout << "\n";
		Print(Receiver); cout << "\n";
	}
public:
	static void ShowTransferScreen()
	{
		DrawScreenHeader("\tTransfer Screen");

		cout << "PLease Enter Account Number To Transfer From : ";
		string FirstClientAccNumber = Input::ReadString();

		while (!Client::isClientExisted(FirstClientAccNumber))
		{
			cout << "Client Isn't Found Please Enter a Valid Client : ";
			FirstClientAccNumber = Input::ReadString();
		}
		Client FirstClient = Client::Find(FirstClientAccNumber);
		Print(FirstClient);

		cout << "PLease Enter Account Number To Transfer To : ";
		string SecondClientAccNumber = Input::ReadString();

		while (!Client::isClientExisted(SecondClientAccNumber) || FirstClientAccNumber == SecondClientAccNumber)
		{
			if (FirstClientAccNumber == SecondClientAccNumber)
			{
				cout << "You Can't Transfer To The Same Account, Please Enter another Account : ";
				SecondClientAccNumber = Input::ReadString();
				continue;
			}
			else
			{
				cout << "Client Isn't Found Please Enter a Valid Client : ";
				SecondClientAccNumber = Input::ReadString();
			}
		}
		Client SecondClient = Client::Find(SecondClientAccNumber);
		Print(SecondClient);

		float TransferAmount = 0;
		cout << "Enter Transfer Amount : ";
		TransferAmount = Input::ReadFloatNumber();

		while (TransferAmount > FirstClient.GetBalance())
		{
			cout << "Amount Exceeds Available Balance, Enter another Amount : ";
			TransferAmount = Input::ReadFloatNumber();
		}

		if (Util::ContinueOperation())
		{
			FirstClient.WithDraw(TransferAmount);
			SecondClient.Deposit(TransferAmount);

			PrintTransfer(FirstClient, SecondClient, TransferAmount);

			SaveTransferingOperation(FirstClient, SecondClient, TransferAmount); // Saving Transfer Data in File
		}
		else
		{
			cout << "\n===============================\n";
			cout << " Operation Denied :-(\n";
			cout << "===============================\n";
		}
	}

};

#endif // TRANSFER_H