#include "User.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

User User::ConvertRecordToObject(string line)
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

string User::ConvertUserObjectToLine(User User, string Seperator)
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

void User::SaveUsersDataToFile(vector<User> &MyUsers)
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

void User::Update()
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

void User::AddNewUserToTheFile()
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

User::User() : Person("", "", "", "")
{
    Mode = UserMode::EmptyMode;
    Permissions = 0;
    Password = "";
}

User::User(UserMode mode, string firstname, string lastname, string email,
           string phone_number, string UserName, string password, int permissions)
    : Person(firstname, lastname, email, phone_number)
{
    Mode = mode;
    Permissions = permissions;
    Password = password;
    this->UserName = UserName;
}

// Getters
string User::GetPassword() { return Password; }
int User::GetPermissions() { return Permissions; }
string User::GetUserName() { return UserName; }

// Setters
void User::SetPassword(string password) { Password = password; }
void User::SetPermissions(int permissions) { Permissions = permissions; }
void User::SetUserName(string username) { UserName = username; }
void User::SetMode(UserMode UserMode) { Mode = UserMode; }

vector<User> User::LoadDataUsersFromFile()
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

bool User::isEmpty() { return Mode == UserMode::EmptyMode; }

User User::Find(string UserName)
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

User User::Find(string Username, string Password)
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

bool User::isUserExisted(string UserName)
{
    User User = User::Find(UserName);
    return (!User.isEmpty());
}

bool User::Save()
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

User User::GetEmptyUser(string UserName)
{
    return User(UserMode::EmptyMode, "", "", "", "", UserName, "", 0);
}

bool User::Delete()
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

User User::GetAddNewModeUser(string UserName)
{
    return User(UserMode::AddNewMode, "", "", "", "", UserName, "", 0);
}

string User::_ConvertLoginStatusToRecord(string separator)
{
    string record = "";
    record += Date::current_date_in_days_months_years() + separator;
    record += Date::current_time() + separator;
    record += UserName + separator;
    record += Util::EncryptText(Password) + separator;
    record += to_string(Permissions);
    return record;
}

void User::SaveLoginStatus()
{
    fstream MyFile;

    MyFile.open("TextFiles/LoginLog.txt", ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << _ConvertLoginStatusToRecord() << endl;
        MyFile.close();
    }
} 