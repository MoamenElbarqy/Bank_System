#ifndef DELETEUSER_H
#define DELETEUSER_H

#include "HeaderScreen.h"
#include "Global.h"

class DeleteUser : private HeaderScreen
{
private:
    static void Print(User MyUser);

public:
    static void Delete();
};

#endif // DELETEUSER_H