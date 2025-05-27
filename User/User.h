#pragma once
#include "../Misc/Person.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "../Misc/Global.h"
#include "../Misc/Date.h"
#include "../Misc/Util.h"
using namespace std;

class User : public Person
{
private:
	enum UserMode
	{
		EmptyMode = 0,
		UpdateMode = 1,
		AddNewMode = 2
	};

	string UserName;
	string Password;
	int Permissions;
	UserMode Mode;

	static User ConvertRecordToObject(string line)
	{
		// We Use It When We Want To Load Data From the File
		User User;
		vector<string> UserData = Util::SplitRecord(line);
		User.SetMode(UserMode::UpdateMode);
		User.SetFirstName(UserData[0]);
		User.SetLastName(UserData[1]);
		User.SetEmail(UserData[2]);
		User.SetPhoneNumber(UserData[3]);
		User.SetUserName(UserData[4]);
		User.SetPassword(Util::DecryptText(UserData[5]));
		User.SetPermissions(stoi(UserData[6]));

		return User;
	}
	static string ConvertUserObjectToLine(User User, string Seperator = "#//#")
	{
		string stUserRecord = "";
		stUserRecord += User.GetFirstName() + Seperator;
		stUserRecord += User.GetLastName() + Seperator;
		stUserRecord += User.GetEmail() + Seperator;
		stUserRecord += User.GetPhoneNumber() + Seperator;
		stUserRecord += User.GetUserName() + Seperator;
		stUserRecord += Util::EncryptText(User.GetPassword()) + Seperator;
		stUserRecord += to_string(User.GetPermissions());

		return stUserRecord;
	}
	void SaveUsersDataToFile(vector<User> &MyUsers)
	{
		fstream MyFile;
		MyFile.open("TextFiles/Users.txt", ios::out); // overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (User &C : MyUsers)
			{
				DataLine = ConvertUserObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}
	void Update()
	{
		vector<User> MyUsers = LoadDataUsersFromFile();

		for (User &C : MyUsers)
		{
			if (C.GetUserName() == GetUserName())
			{
				C = *this;
				break;
			}
		}
		SaveUsersDataToFile(MyUsers);
	}

	void AddNewUserToTheFile()
	{
		string line = ConvertUserObjectToLine(*this);
		fstream MyFile;

		MyFile.open("TextFiles/Users.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << line << endl;
			MyFile.close();
		}
	}

public:
	// (P) is abbreviation for permission
	enum UsersPermission
	{
		All = -1,
		ListClients = 1,
		AddClient = 2,
		DeleteClient = 4,
		UpdateClient = 8,
		FindClient = 16,
		Transactions = 32,
		MangeUsers = 64,
		LoginLog = 128,
		CurrencyExchange = 256
	};

	// Empty User
	User() : Person("", "", "", "")
	{
		Mode = UserMode::EmptyMode;
		Permissions = 0;
		Password = "";
	}
	// User With data

	User(UserMode mode, string firstname, string lastname, string email,
		 string phone_number, string UserName, string password, int permissions)
		: Person(firstname, lastname, email, phone_number)
	{
		Mode = mode;
		Permissions = permissions;
		Password = password;
		this->UserName = UserName;
	}

	// Getters
	string GetPassword() { return Password; }
	int GetPermissions() { return Permissions; }
	string GetUserName() { return UserName; }
	// Setters
	void SetPassword(string password) { Password = password; }
	void SetPermissions(int permissions) { Permissions = permissions; }
	void SetUserName(string username) { UserName = username; }
	void SetMode(UserMode UserMode) { Mode = UserMode; }
	static vector<User> LoadDataUsersFromFile()
	{
		vector<User> MyUsers;

		fstream MyFile;

		MyFile.open("TextFiles/Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				User User = ConvertRecordToObject(line);
				MyUsers.push_back(User);
			}
			MyFile.close();
		}
		return MyUsers;
	}

	bool isEmpty() { return Mode == UserMode::EmptyMode; }

	static User Find(string UserName)
	{
		vector<string> UsersData;

		fstream MyFile;
		MyFile.open("TextFiles/Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				UsersData = Util::SplitRecord(line);
				if (UsersData[4] == UserName)
				{
					MyFile.close();
					return User(UserMode::UpdateMode, UsersData[0], UsersData[1], UsersData[2],
								UsersData[3], UsersData[4], UsersData[5], stoi(UsersData[6]));
				}
			}
		}

		MyFile.close();

		return User(); // if we reached here we did't find the user and returning empty user
	}
	static User Find(string Username, string Password)
	{
		vector<string> UsersData;

		fstream MyFile;
		User CurrentUser;
		string line;
		MyFile.open("TextFiles/Users.txt", ios::in);

		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				UsersData = Util::SplitRecord(line);
				CurrentUser.SetUserName(UsersData[4]);
				CurrentUser.SetPassword(Util::DecryptText(UsersData[5]));
				if (CurrentUser.GetUserName() == Username && Password == CurrentUser.GetPassword())
				{
					CurrentUser.SetMode(UserMode::UpdateMode);
					CurrentUser.SetFirstName(UsersData[0]);
					CurrentUser.SetLastName(UsersData[1]);
					CurrentUser.SetEmail(UsersData[2]);
					CurrentUser.SetPhoneNumber(UsersData[3]);
					CurrentUser.SetPermissions(stoi(UsersData[6]));
					MyFile.close();
					return CurrentUser;
				}
			}
			MyFile.close();
		}

		return User();
	}

	static bool isUserExisted(string UserName)
	{
		User User = User::Find(UserName);
		return (!User.isEmpty());
	}

	bool Save()
	{
		switch (Mode)
		{
		case UserMode::EmptyMode:
		{
			return false;
		}
		case UserMode::UpdateMode:
		{
			Update();
			return true;
		}
		case UserMode::AddNewMode:
		{
			AddNewUserToTheFile();
			Mode = UserMode::UpdateMode; // Changing The User Mode After Becoming Exsisted In The File
			return true;
		}
		}
		return false; // Defualt Value for UnKnown Behaviours
	}

	static User GetEmptyUser(string UserName)
	{
		return User(UserMode::EmptyMode, "", "", "", "", UserName, "", 0);
	}
	bool Delete()
	{
		vector<User> MyUsers = LoadDataUsersFromFile();
		vector<User>::iterator it;

		for (it = MyUsers.begin(); it != MyUsers.end(); ++it)
		{
			if (it->GetUserName() == this->GetUserName())
			{
				MyUsers.erase(it);
				break;
			}
		}
		SaveUsersDataToFile(MyUsers);
		*this = GetEmptyUser(UserName); // Making The Current Object Empty From Its Data
		return true;
	}
	static User GetAddNewModeUser(string UserName)
	{
		return User(UserMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	string _ConvertLoginStatusToRecord(string separator = "#//#")
	{
		string record = "";
		record += Date::current_date_in_days_months_years() + separator;
		record += Date::current_time() + separator;
		record += UserName + separator;
		record += Util::EncryptText(Password) + separator;
		record += to_string(Permissions);
		return record;
	}

	void SaveLoginStatus()
	{
		fstream MyFile;

		MyFile.open("TextFiles/LoginLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << _ConvertLoginStatusToRecord() << endl;
			MyFile.close();
		}
	}
};