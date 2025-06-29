#ifndef FINDUSER_H
#define FINDUSER_H

#include "HeaderScreen.h"
#include "Global.h"

class FindUser : private HeaderScreen
{
private:
    static void Print(User MyUser);

public:
    static void FindUserScreen();
};

#endif // FINDUSER_H