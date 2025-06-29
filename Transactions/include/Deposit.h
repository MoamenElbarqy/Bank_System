#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "HeaderScreen.h"
#include "Global.h"
#include "Client.h"
#include "Input.h"
using namespace std;

class Deposit : private HeaderScreen
{
private:
    static void Print(Client MyClient)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName      : " << MyClient.GetFirstName();
        cout << "\nLastName       : " << MyClient.GetLastName();
        cout << "\nFull Name      : " << MyClient.GetFirstName() + " " + MyClient.GetLastName();
        cout << "\nEmail          : " << MyClient.GetEmail();
        cout << "\nPhone          : " << MyClient.GetPhoneNumber();
        cout << "\nAccount Number : " << MyClient.GetAccNumber();
        cout << "\nPassword       : " << MyClient.GetPinCode();
        cout << "\nBalance        : " << MyClient.GetBalance();
        cout << "\n___________________\n";
    }

public:
    static void DepositClient();
};

#endif DEPOSIT_H