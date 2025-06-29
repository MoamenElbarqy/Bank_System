#include "TransferLog.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Util.h"
using namespace std;

TransferLog::TransferData TransferLog::ConvertVectorToTransferData(vector<string> LineData)
{
    TransferData MyTransferData;
    MyTransferData.date = LineData.at(0);
    MyTransferData.time = LineData.at(1);
    MyTransferData.source_account = LineData.at(2);
    MyTransferData.destrnation_account = LineData.at(3);
    MyTransferData.transfer_amount = stof(LineData.at(4));
    MyTransferData.source_balance = stof(LineData.at(5));
    MyTransferData.destrnation_balance = stof(LineData.at(6));
    MyTransferData.user_name = LineData.at(7);
    return MyTransferData;
}

vector<TransferLog::TransferData> TransferLog::LoadTransferDataFromFile()
{
    vector<TransferData> MyTransferData;
    vector<string> LineData;
    string line = "";
    fstream MyFile;
    MyFile.open("TextFiles/TransferLog.txt", ios::in);
    if (MyFile.is_open())
    {
        while (getline(MyFile, line))
        {
            LineData = Util::SplitRecord(line);
            TransferData CurrentData = ConvertVectorToTransferData(LineData);
            MyTransferData.push_back(CurrentData);
        }
        MyFile.close();
    }
    else
    {
        cout << "\n===============================\n";
        cout << " We Can't Open The File :-(\n";
        cout << "===============================\n";
    }
    return MyTransferData;
}

void TransferLog::PrintTransferLogScreen()
{
    cout << "\t-----------------------------------------------------------------------------------------------------\n";
    cout << "\t|    Date     |    Time    |   S.Acc  |   D.Acc  |   Amount    |  S.Balance  | D.Balance   | UserName\n";
    cout << "\t------------------------------------------------------------------------------------------------------\n";
    vector<TransferData> MyTransferData;
    MyTransferData = LoadTransferDataFromFile();
    for (TransferData CurrentData : MyTransferData)
    {
        cout << "\t|" << setw(13) << left << CurrentData.date;
        cout << "|" << setw(12) << left << CurrentData.time;
        cout << "|" << setw(10) << left << CurrentData.source_account;
        cout << "|" << setw(10) << left << CurrentData.destrnation_account;
        cout << "|" << setw(13) << left << CurrentData.transfer_amount;
        cout << "|" << setw(13) << left << CurrentData.source_balance;
        cout << "|" << setw(13) << left << CurrentData.destrnation_balance;
        cout << "|" << setw(9) << left << CurrentData.user_name;
        cout << endl;
    }
    cout << "\t-----------------------------------------------------------------------------------------------------\n";
}

void TransferLog::ShowTransferLog()
{
    vector<TransferData> MyTransferData = LoadTransferDataFromFile();
    string subTitle = "(" + to_string(MyTransferData.size()) + ")" + " Operation(s)";
    DrawScreenHeader("\t Transfer Log", subTitle);
    PrintTransferLogScreen();
} 