#pragma once

#include "Person.h"
#include <string> 
#include <vector>


class Client : public Person
{
private:
    enum Mode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };

    string AccountNumber;
    string PinCode;
    float Balance;
    Mode ClientMode;

    static Client ConvertRecordToObject(string line);
    static string ConverClientObjectToLine(Client Client, string Seperator = "#//#");
    void SaveClientsDataToFile(vector<Client> &MyClients);
    void Update();
    void AddNewClientToTheFile();

protected:
public:
    Client();
    Client(Mode mode, string firstname, string lastname, string email,
           string phone_number, string acc_number, string pin_code, float acc_balacne);
    static vector<Client> LoadDataClientsFromFile();
    static double CountTotalBalances(vector<Client> &MyClients);
    bool isEmpty();

    // Setters
    void SetPinCode(string pin);
    void SetBalance(float balance);
    void SetMode(Mode ClientMode);
    void SetAccNumber(string AccountNumber);

    // Getters
    float GetBalance();
    string GetAccNumber();
    string GetPinCode();

    static Client Find(string acc_number);
    static Client Find(string acc_number, string PinCode);
    static bool isClientExisted(string AccNumber);
    bool Save();
    static Client GetEmptyClient(string AccountNumber);
    bool Delete();
    static Client GetAddNewModeClient(string AccountNumber);
    void Deposit(float val);
    void WithDraw(float val);
};