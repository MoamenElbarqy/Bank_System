#ifndef HEADERSCREEN_H
#define HEADERSCREEN_H

#include <iostream>
#include <string>
#include <ctime>
#include "Global.h"
#include "User.h"
#include "Date.h"

class HeaderScreen
{
protected:
    static void DrawScreenHeader(string Title, string subtitle = "");
    static bool hasAccess(User::UsersPermission CurrentPermission);
};

#endif  HEADERSCREEN_H