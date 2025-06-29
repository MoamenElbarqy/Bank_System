#ifndef FINDCLIENT_H
#define FINDCLIENT_H

#include "HeaderScreen.h"
#include "Client.h"

class FindClient : private HeaderScreen
{
private:
    static void Print(Client MyClient);

public:
    static void FindClientScreen();
};

#endif  // FINDCLIENT_H