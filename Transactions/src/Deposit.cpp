#include "Deposit.h"
#include <iostream>
using namespace std;

void Deposit::Print(Client MyClient)
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

void Deposit::DepositClient()
{
    DrawScreenHeader("\tDeposit Screen");
    string AccNumber = "";
    cout << "Please Enter Account Number : ";
    AccNumber = Input::ReadString();
    while (!Client::isClientExisted(AccNumber))
    {
        cout << "Client is Not Found, Enter a Valid Client : ";
        AccNumber = Input::ReadString();
    }
    Client MyClient = Client::Find(AccNumber);
    Print(MyClient);
    float DepositAmount = 0;
    cout << "\nPlease Enter Deposit Amount : ";
    cin >> DepositAmount;
    if (Util::ContinueOperation())
    {
        MyClient.Deposit(DepositAmount);
        cout << "\n===============================\n";
        cout << " Account Deposited Succssfly.\n";
        cout << "===============================\n";
        cout << "\nNew Balance is : [ " << MyClient.GetBalance() << " ] " << endl;
    }
    else
    {
        cout << "\n===============================\n";
        cout << " Account Deposited Succssfly.\n";
        cout << "===============================\n";
    }
} 