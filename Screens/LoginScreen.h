#pragma once
#include "../Misc/Input.h"
#include "MainScreen.h"
#include "HeaderScreen.h"
#include "../User/User.h"
#include "../Misc/Global.h"
using namespace std;

class LoginScreen : private HeaderScreen
{
public:
    static void ShowLoginScreen()
    {
        system("cls");
        DrawScreenHeader("\tLogin Screen");

        short AvailableTrials = 3;
        bool LoginStatus = false;
        string UserName = "";
        string PassWord = "";

        while (!LoginStatus)
        {

            cout << "UserName : ";
            UserName = Input::ReadString();

            cout << "Password : ";
            PassWord = Input::ReadString();

            SystemUser = User::Find(UserName, PassWord);

            if (!SystemUser.isEmpty())
                LoginStatus = true;
            else
            {
                if (!--AvailableTrials)
                {
                    LockTheSystem = true;
                    return;
                }
                else
                {
                    cout << "\nInvalid UserName/Password, Enter a Valid User.\n";
                    cout << "AvailableTrials : " << AvailableTrials << "\n\n";
                }
            }
        }
        SystemUser.SaveLoginStatus(); // Saved The Login Info  Date, Time, UserName And User Permissions in login Register File
        MainScreen::ShowMainMenueScreen();
    }
};