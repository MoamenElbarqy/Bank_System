#ifndef ADDUSER_H
#define ADDUSER_H

#include "HeaderScreen.h"
#include "Global.h"

class AddUser : private HeaderScreen
{
private:
	static void ReadUserInfo(User &User);
	static void Print(User MyUser);

public:
	static void AddNewUser();
};

#endif // ADDUSER_H