#ifndef USER_H
#define USER_H

#include "Person.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "Global.h"
#include "Date.h"
#include "Util.h"
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

	static User ConvertRecordToObject(string line);
	static string ConvertUserObjectToLine(User User, string Seperator = "#//#");
	void SaveUsersDataToFile(vector<User> &MyUsers);
	void Update();
	void AddNewUserToTheFile();

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
	User();
	// User With data
	User(UserMode mode, string firstname, string lastname, string email,
		 string phone_number, string UserName, string password, int permissions);

	// Getters
	string GetPassword();
	int GetPermissions();
	string GetUserName();
	// Setters
	void SetPassword(string password);
	void SetPermissions(int permissions);
	void SetUserName(string username);
	void SetMode(UserMode UserMode);
	static vector<User> LoadDataUsersFromFile();
	bool isEmpty();
	static User Find(string UserName);
	static User Find(string Username, string Password);
	static bool isUserExisted(string UserName);
	bool Save();
	static User GetEmptyUser(string UserName);
	bool Delete();
	static User GetAddNewModeUser(string UserName);
	string _ConvertLoginStatusToRecord(string separator = "#//#");
	void SaveLoginStatus();
};

#endif  USER_H