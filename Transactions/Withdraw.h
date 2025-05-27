#pragma once
#include "../Screens/HeaderScreen.h"
#include "../Client/Client.h"
#include "../Misc/Input.h"
#include "../Misc/Global.h"
using namespace std;

class WithDarw : private HeaderScreen
{
private:

	static void Print(Client MyClient)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName      : " << MyClient.GetFirstName();
		cout << "\nLastName       : " << MyClient.GetLastName();
		cout << "\nFull Name      : " << MyClient.GetFirstName() + " " + MyClient.GetLastName();
		cout << "\nEmail          : " << MyClient.GetEmail();
		cout << "\nPhone          : " << MyClient.GetPhoneNumber();
		cout << "\nAccount Number : " << MyClient.GetAccNumber();
		cout << "\nPassword       : " << MyClient.GetPinCode();
		cout << "\nBalance        : " << MyClient.GetBalance();
		cout << "\n___________________\n";

	}
public:
	static void WithdrawClient()
	{
		DrawScreenHeader("\tWithdraw Screen");

		string AccNumber = "";
		cout << "Please Enter Account Number : ";
		AccNumber = Input::ReadString();


		while (!Client::isClientExisted(AccNumber))
		{
			cout << "Client is Not Found, Enter a Valid Client : ";
			AccNumber = Input::ReadString();
		}
		Client MyClient = Client::Find(AccNumber);
		Print(MyClient);
		float WithDrawAmount = 0;

		cout << "\nPlease Enter Deposit Amount : ";
		cin >> WithDrawAmount;
		while (WithDrawAmount > MyClient.GetBalance())
		{
			cout << "You Can't Take More Than Your Balance (" << MyClient.GetBalance() << "), Enter a Valid Number : ";
			cin >> WithDrawAmount;
		}

		if (Util::ContinueOperation())
		{
			MyClient.WithDraw(WithDrawAmount);
			cout << "\n===============================\n";
			cout << " Account Withdrawed Succssfully.\n";
			cout << "===============================\n";

			cout << "\nNew Balance is : [ " << MyClient.GetBalance() << " ] " << endl;
		}
		else
		{
			cout << "\n===============================\n";
			cout << " Operation Denied :-(\n";
			cout << "===============================\n";
		}
	}
};