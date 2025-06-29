#ifndef UPDATECLIENT_H
#define UPDATECLIENT_H

#include "HeaderScreen.h"
#include "Client.h"

class UpdateClient : private HeaderScreen
{
private:
	static void ReadClientInfo(Client &Client);
	static void Print(Client MyClient);
public:
	static void Update();
};

#endif  UPDATECLIENT_H