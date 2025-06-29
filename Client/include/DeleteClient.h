#ifndef DELETECLIENT_H
#define DELETECLIENT_H

#include "HeaderScreen.h"
#include "Client.h"

class DeleteClient : private HeaderScreen
{
private:
    static void Print(Client MyClient);
public:
    static void Delete();
};

#endif  DELETECLIENT_H