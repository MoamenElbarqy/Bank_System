#pragma once
#include "HeaderScreen.h"
#include "Input.h"
#include "Client.h"
#include "Global.h"
using namespace std;

class UpdateClient : private HeaderScreen
{
private:
	static void ReadClientInfo(Client &Client)
	{
		cout << "Enter First Name : ";
		Client.SetFirstName(Input::ReadString());

		cout << "Enter Last Name : ";
		Client.SetLastName(Input::ReadString());

		cout << "Enter Email : ";
		Client.SetEmail(Input::ReadString());

		cout << "Enter Phone : ";
		Client.SetPhoneNumber(Input::ReadString());

		cout << "Enter Pin Code : ";
		Client.SetPinCode(Input::ReadString());

		cout << "Enter your Balance : ";
		Client.SetBalance(Input::ReadFloatNumber());
	}
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
	static void Update()
	{
		// This Will Show Access Denied Screen Internaly If The user Dosen't Have Permission To Do This
		if (!hasAccess(User::UsersPermission::UpdateClient))
			return;

		DrawScreenHeader("\tUpdate Client Info Screen");
		string AccountNumber = "";
		cout << "Please Enter Account Number : ";
		AccountNumber = Input::ReadString();

		while (!Client::isClientExisted(AccountNumber))
		{
			cout << "Account Number is not Found , Enter a valid one : ";
			AccountNumber = Input::ReadString();
		}

		Client Client = Client::Find(AccountNumber);
		Print(Client);
		cout << "\nUpdate Info:\n";
		cout << "---------------\n";
		ReadClientInfo(Client);
		if (Util::ContinueOperation())
		{
			if (Client.Save())
			{
				cout << "\n===============================\n";
				cout << " Account Updated Successfully :-)\n";
				cout << "===============================\n";
				Print(Client);
			}
			else
			{
				cout << "\n==================================================\n";
				cout << "Error Account Wasn't Saved Because It's Empty :-(\n";
				cout << "==================================================\n";
			}
		}
		else
		{
			cout << "\n===============================\n";
			cout << " Operation Denied :-(\n";
			cout << "===============================\n";
		}
	}
};