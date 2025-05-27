#pragma once
#include "../Screens/HeaderScreen.h"
#include "../Client/Client.h"
#include "../Misc/Input.h"
#include "../Misc/Global.h"
using namespace std;

class AddClient : private HeaderScreen
{
private:
	Client newClient;
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
		cout << "\nPin Code       : " << MyClient.GetPinCode();
		cout << "\nBalance        : " << MyClient.GetBalance();
		cout << "\n___________________\n";
	}

public:
	static void AddNewClient()
	{
		if (!hasAccess(User::UsersPermission::AddClient))
			return; // Acceess Check

		DrawScreenHeader("\t Add New Client Screen");

		cout << "Enter New Client Account Number :";
		string AccountNumber = Input::ReadString();

		while (Client::isClientExisted(AccountNumber))
		{
			cout << "This Account Already Existed,Enter a new one :";
			AccountNumber = Input::ReadString();
		}
		Client newClient = Client::GetAddNewModeClient(AccountNumber);

		ReadClientInfo(newClient);

		if (Util::ContinueOperation())
		{
			if (newClient.Save())
			{
				cout << "\n===============================\n";
				cout << " Account Added Successfully :-)\n";
				cout << "===============================\n";
				Print(newClient);
			}
			else
			{
				cout << "\n===============================\n";
				cout << " We Can't Save Empty Client :-(\n";
				cout << "===============================\n";
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