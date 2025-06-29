#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "LoginLog.h"
using namespace std;

vector<LoginLog::LoginData> LoginLog::LoadLoginRegisterFile()
{
    vector<LoginData> vLoginData;
    vector<string> RecordData;
    LoginData CurrentData;
    fstream MyFile;
    string line;

    MyFile.open("TextFiles/LoginLog.txt", ios::in);
    if (MyFile.is_open())
    {
        while (getline(MyFile, line))
        {
            RecordData = Util::SplitRecord(line);
            CurrentData.date = RecordData[0];
            CurrentData.time = RecordData[1];
            CurrentData.user_name = RecordData[2];
            CurrentData.password = RecordData[3];
            CurrentData.permissions = stoi(RecordData[4]);
            vLoginData.push_back(CurrentData);
        }
        MyFile.close();
    }
    return vLoginData;
}

void LoginLog::PrintLoginRegisterData(vector<LoginData> LoginRegisterData)
{
    cout << "\t-----------------------------------------------------------------------------------------------------\n";
    cout << "\t|       Date       |      Time       |      UserName      |   Password (Encrepted)     |  Permissions \n";
    cout << "\t-----------------------------------------------------------------------------------------------------\n";

    for (LoginData CurrentData : LoginRegisterData)
    {
        cout << "\t|" << setw(18) << left << CurrentData.date;
        cout << "|" << setw(17) << left << CurrentData.time;
        cout << "|" << setw(20) << left << CurrentData.user_name;
        cout << "|" << setw(28) << left << CurrentData.password;
        cout << "|" << setw(15) << left << CurrentData.permissions;
        cout << endl;
    }
    cout << "\t--------------------------------------------------------------------------------------------\n";
}

void LoginLog::ShowLoginRegisterScreen()
{
    if (!hasAccess(User::UsersPermission::AddClient))
        return; // This Will Show Access Denied Screen Internaly
    vector<LoginData> LoginRegisterData = LoadLoginRegisterFile();
    string subTitle = "(" + to_string(LoginRegisterData.size()) + ")" + " Time(s)";

    DrawScreenHeader("\tLogin Register Screen", subTitle);
    PrintLoginRegisterData(LoginRegisterData);
} 