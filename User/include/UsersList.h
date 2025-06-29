#ifndef USERSLIST_H
#define USERSLIST_H

#include <iomanip>
#include "HeaderScreen.h"
#include "Global.h"

class UsersList : private HeaderScreen
{
public:
	static void ShowUsersListScreen();
};

#endif // USERSLIST_H
