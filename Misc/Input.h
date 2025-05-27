#pragma once
#include <string>
#include <iostream>
#include <limits>
#include "../Misc/Global.h"
using namespace std;
class Input
{
public:
    static float ReadFloatNumber(string msg = "Invalid Number, Enter again : ")
    {
        float num = 0;
        cin >> num;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << msg;
            cin >> num;
        }
        return num;
    }
    static string ReadString()
    {
        string str;
        getline(cin >> ws, str);
        return str;
    }
    static int ReadNumberBetween(int from, int to)
    {
        int number;
        do
        {
            cin >> number;
        } while (number < from || number > to);
        return number;
    }
    static int ReadNumber()
    {
        int num = 0;
        cin >> num;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invaild Number , Enter a Valid Number : ";
            cin >> num;
        }
        return num;
    }
};