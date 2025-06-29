#include <iostream> 
#include <algorithm>
#include <string>  
#include <vector>  
#include <fstream>
#include "Client.h"

using namespace std;

Client Client::ConvertRecordToObject(string line)
{
    Client MyClient;
    vector<string> ClientData = Util::SplitRecord(line);
    MyClient.SetMode(Mode::UpdateMode);
    MyClient.SetFirstName(ClientData[0]);
    MyClient.SetLastName(ClientData[1]);
    MyClient.SetEmail(ClientData[2]);
    MyClient.SetPhoneNumber(ClientData[3]);
    MyClient.SetAccNumber(ClientData[4]);
    MyClient.SetPinCode(ClientData[5]);
    MyClient.SetBalance(stof(ClientData[6]));

    return MyClient;
}

string Client::ConverClientObjectToLine(Client Client, string Seperator)
{
    string stClientRecord = "";
    stClientRecord += Client.GetFirstName() + Seperator;
    stClientRecord += Client.GetLastName() + Seperator;
    stClientRecord += Client.GetEmail() + Seperator;
    stClientRecord += Client.GetPhoneNumber() + Seperator;
    stClientRecord += Client.GetAccNumber() + Seperator;
    stClientRecord += Client.GetPinCode() + Seperator;
    stClientRecord += to_string(Client.GetBalance());

    return stClientRecord;
}

void Client::SaveClientsDataToFile(vector<Client> &MyClients)
{
    fstream MyFile;
    MyFile.open("TextFiles/ClientsData.txt", ios::out); // overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (Client &C : MyClients)
        {
            DataLine = ConverClientObjectToLine(C);
            MyFile << DataLine << endl;
        }
        MyFile.close();
    }
}

void Client::Update()
{
    vector<Client> MyClients = LoadDataClientsFromFile();

    for (Client &C : MyClients)
    {
        if (C.GetAccNumber() == GetAccNumber())
        {
            C = *this;
            break;
        }
    }
    SaveClientsDataToFile(MyClients);
}

void Client::AddNewClientToTheFile()
{
    string line = ConverClientObjectToLine(*this);
    fstream MyFile;

    MyFile.open("TextFiles/ClientsData.txt", ios::app | ios::out);

    if (MyFile.is_open())
    {
        MyFile << line << endl;
        MyFile.close();
    }
}

Client::Client() : Person("", "", "", "")
{
    ClientMode = Mode::EmptyMode;
    AccountNumber = "";
    PinCode = "";
    Balance = 0;
}

Client::Client(Mode mode, string firstname, string lastname, string email,
               string phone_number, string acc_number, string pin_code, float acc_balacne)
    : Person(firstname, lastname, email, phone_number)
{
    ClientMode = mode;
    AccountNumber = acc_number;
    PinCode = pin_code;
    Balance = acc_balacne;
}

vector<Client> Client::LoadDataClientsFromFile()
{
    vector<Client> MyClients;

    fstream MyFile;

    MyFile.open("TextFiles/ClientsData.txt", ios::in);

    if (MyFile.is_open())
    {
        string line;

        while (getline(MyFile, line))
        {
            Client Client = ConvertRecordToObject(line);
            MyClients.push_back(Client);
        }
        MyFile.close();
    }
    return MyClients;
}

double Client::CountTotalBalances(vector<Client> &MyClients)
{
    double total = 0;
    for (Client &CurrentClient : MyClients)
    {
        total += CurrentClient.GetBalance();
    }
    return total;
}

bool Client::isEmpty() { return ClientMode == Mode::EmptyMode; }

// Setters
void Client::SetPinCode(string pin) { PinCode = pin; }
void Client::SetBalance(float balance) { this->Balance = balance; }
void Client::SetMode(Mode ClientMode) {this->ClientMode = ClientMode;}
void Client::SetAccNumber(string AccountNumber) {this->AccountNumber = AccountNumber;}

// Getters
float Client::GetBalance() { return Balance; }
string Client::GetAccNumber() { return AccountNumber; }
string Client::GetPinCode() { return PinCode; }

Client Client::Find(string acc_number)
{
    vector<string> ClientData;

    fstream MyFile;
    MyFile.open("TextFiles/ClientsData.txt", ios::in);

    if (MyFile.is_open())
    {
        string line;
        while (getline(MyFile, line))
        {
            ClientData = Util::SplitRecord(line);
            if (ClientData[4] == acc_number)
            {
                MyFile.close();
                return Client(Mode::UpdateMode, ClientData[0], ClientData[1], ClientData[2],
                                ClientData[3], ClientData[4], ClientData[5], stof(ClientData[6]));
            }
        }
    }
    MyFile.close();

    return Client(); // if we reached here we did't find the client and returning empty client
}

Client Client::Find(string acc_number, string PinCode)
{
    vector<string> ClientData;

    fstream MyFile;
    MyFile.open("TextFiles/ClinetsData.txt", ios::in); // Typo: ClinetsData.txt should be ClientsData.txt

    if (MyFile.is_open())
    {
        string line;
        while (getline(MyFile, line))
        {
            ClientData = Util::SplitRecord(line);
            if (ClientData[4] == acc_number && PinCode == ClientData[5])
                return Client(Mode::UpdateMode, ClientData[0], ClientData[1], ClientData[2], ClientData[3], ClientData[4], ClientData[5], stof(ClientData[6]));
        }
        MyFile.close();
    }

    return Client();
}

bool Client::isClientExisted(string AccNumber)
{
    Client Client = Client::Find(AccNumber);
    return (!Client.isEmpty());
}

bool Client::Save()
{
    switch (ClientMode)
    {
    case Mode::EmptyMode:
        return false;

    case Mode::UpdateMode:
        Update();
        return true;

    case Mode::AddNewMode:
        AddNewClientToTheFile();
        ClientMode = Mode::UpdateMode; // Changing The Client Mode After Becoming Exsisted In The File
        return true;
    }
    return false; // Defualt Value for UnKnown Behaviours
}

Client Client::GetEmptyClient(string AccountNumber)
{
    return Client(Mode::EmptyMode, "", "", "", "", AccountNumber, "", 0);
}

bool Client::Delete()
{
    vector<Client> vMyClients = LoadDataClientsFromFile();
    vector<Client>::iterator it;

    for (it = vMyClients.begin(); it != vMyClients.end(); ++it)
    {
        if (it->GetAccNumber() == this->GetAccNumber())
        {
            vMyClients.erase(it);
            break;
        }
    }
    SaveClientsDataToFile(vMyClients);

    *this = Client(); // Making The Current Object Empty From Its Data After Deleting Him From The File
    return true;
}

Client Client::GetAddNewModeClient(string AccountNumber)
{
    return Client(Mode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
}

void Client::Deposit(float val)
{
    Balance += val;
    Save();
}

void Client::WithDraw(float val)
{
    Balance -= val;
    Save();
}