#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include "../Misc/Input.h"
#include "MainScreen.h"
#include "HeaderScreen.h"
#include "../User/User.h"
#include "../Misc/Global.h"
using namespace std;

class LoginScreen : private HeaderScreen
{
public:
    static void ShowLoginScreen();
};

#endif // LOGINSCREEN_H