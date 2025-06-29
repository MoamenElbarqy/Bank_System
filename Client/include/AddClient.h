#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include "HeaderScreen.h"
#include "Client.h"


class AddClient : private HeaderScreen
{
private:
    Client newClient;
    static void ReadClientInfo(Client &Client);
    static void void Print(Client MyClient);

public:
    static void AddNewClient();
};

#endif ADDCLIENT_H