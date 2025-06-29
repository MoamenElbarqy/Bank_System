#ifndef LOGINLOG_H
#define LOGINLOG_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "HeaderScreen.h"
#include "Global.h"
#include "User.h"
using namespace std;

class LoginLog : private HeaderScreen
{
private:
    struct LoginData
    {
        string date = "";
        string time = "";
        string user_name = "";
        string password = "";
        int permissions = 0;
    };

    static vector<LoginData> LoadLoginRegisterFile();
    static void PrintLoginRegisterData(vector<LoginData> LoginRegisterData);

public:
    static void ShowLoginRegisterScreen();
};

#endif // LOGINLOG_H