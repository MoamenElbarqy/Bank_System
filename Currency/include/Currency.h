#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Currency
{
private:
    enum CurrencyMode
    {
        UpdateMode = 1,
        EmptyMode = 2
    };
    CurrencyMode _CurrencyMode;
    string _Country;
    string _Code;
    string _CurrencyName;
    float _Rate;

    static Currency ConvertRecordToCurrencyObject(string line);

public:
    Currency();
    Currency(CurrencyMode mode, string country, string code, string name, float rate);
    
    static Currency GetEmptyCurrency();
    static string _ConvertCurrenyObjectToLine(Currency Currency, string Seperator = "#//#");
    void LoadCurrenciesToFile(vector<Currency> vMyCurrencies);
    void Save();
    void SetRate(float rate);
    
    // getters
    string GetCountryName();
    string GetCode();
    string GetCurrencyName();
    CurrencyMode GetCurrencyMode();
    float GetRate();
    
    static vector<Currency> LoadCurrenciesFromFile();
    bool isEmpty();
    static Currency FindByCode(string country_code);
    static Currency FindByName(string country_name);
    static bool isCurrencyExsisted(string CurrencyCode);
};

#endif CURRENCY_H