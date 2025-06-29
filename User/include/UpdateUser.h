#ifndef UPDATEUSER_H
#define UPDATEUSER_H

#include "HeaderScreen.h"
#include "Global.h"

class UpdateUser : private HeaderScreen
{
private:
	static void ReadUserInfo(User &User);
	static void Print(User MyUser);

public:
	static void Update();
};

#endif // UPDATEUSER_H