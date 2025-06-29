#include "Input.h"
#include <string>
#include <iostream>
#include <limits>
using namespace std;

float Input::ReadFloatNumber(string msg)
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

string Input::ReadString()
{
    string str;
    getline(cin >> ws, str);
    return str;
}

int Input::ReadNumberBetween(int from, int to)
{
    int number;
    do
    {
        cin >> number;
    } while (number < from || number > to);
    return number;
}

int Input::ReadNumber()
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