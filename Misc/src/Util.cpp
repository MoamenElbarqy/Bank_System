#include "Util.h"
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string Util::DecryptText(string Text, short EncryptionKey)
{
    for (char &c : Text)
    {
        c -= EncryptionKey;
    }
    return Text;
}

string Util::EncryptText(string Text, short EncryptionKey)
{
    for (char &c : Text)
    {
        c += EncryptionKey;
    }
    return Text;
}

bool Util::ContinueOperation(string msg)
{
    char status = 'n';
    cout << msg;
    cin >> status;
    while (status != 'n' && status != 'N' && status != 'y' && status != 'Y')
    {
        cout << "Invalid Character, You Have Only Two Options [ Yes = Y , y ] &  [ No = N , n ] : ";
        cin >> status;
    }
    return status == 'y' || status == 'Y';
}

vector<string> Util::SplitRecord(string str, string delimiter)
{
    vector<string> result;
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != delimiter[0])
        {
            temp += str[i];
        }
        else
        {
            result.push_back(temp);
            temp = "";
            i += int(delimiter.length()) - 1; // This Line Will Treat The Long Delimiter Like #//# not only the white space
        }
    }
    result.push_back(temp);
    return result;
}

string Util::UpperAll(string str)
{
    for (char &c : str)
    {
        if (islower(c))
            c = toupper(c);
    }
    return str;
} 