#pragma once
#include <string>
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

    static Currency ConvertRecordToCurrencyObject(string line)
    {
        vector<string> CurrencyData = Util::SplitRecord(line);
        return Currency(CurrencyMode::UpdateMode, CurrencyData[0], CurrencyData[1], CurrencyData[2], stof(CurrencyData[3]));
    }

public:
    Currency()
    {
        _CurrencyMode = CurrencyMode::EmptyMode;
        _Country = "";
        _Code = "";
        _CurrencyName = "";
        _Rate = 0;
    }
    Currency(CurrencyMode mode, string country, string code, string name, float rate)
    {
        _CurrencyMode = mode;
        _Country = country;
        _Code = code;
        _CurrencyName = name;
        _Rate = rate;
    }
    static Currency GetEmptyCurrency()
    {
        return Currency();
    }
    static string _ConvertCurrenyObjectToLine(Currency Currency, string Seperator = "#//#")
    {
        string record = "";
        record += Currency._Country + Seperator;
        record += Currency._Code + Seperator;
        record += Currency._CurrencyName + Seperator;
        record += to_string(Currency._Rate);

        return record;
    }

    void LoadCurrenciesToFile(vector<Currency> vMyCurrencies)
    {
        fstream MyFile;
        MyFile.open("TextFiles/CurrenciesData.txt", ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (Currency C : vMyCurrencies)
            {
                DataLine = _ConvertCurrenyObjectToLine(C);
                MyFile << DataLine << endl;
            }
            MyFile.close();
        }
    }
    void Save()
    {
        vector<Currency> vMyCurrencies = LoadCurrenciesFromFile();
        for (Currency &currenct_currency : vMyCurrencies)
        {
            if (this->GetCode() == currenct_currency.GetCode())
            {
                currenct_currency = *this;
                LoadCurrenciesToFile(vMyCurrencies);
                return;
            }
        }
    }
    void SetRate(float rate)
    {
        _Rate = rate;
        Save();
    }
    // getters
    string GetCountryName() { return _Country; }
    string GetCode() { return _Code; }
    string GetCurrencyName() { return _CurrencyName; }
    CurrencyMode GetCurrencyMode() { return _CurrencyMode; }
    float GetRate() { return _Rate; }
    static vector<Currency> LoadCurrenciesFromFile()
    {
        vector<Currency> vMyCurrencies;

        fstream MyFile;

        MyFile.open("TextFiles/CurrenciesData.txt", ios::in);

        if (MyFile.is_open())
        {
            string line;

            while (getline(MyFile, line))
            {
                Currency Currency = ConvertRecordToCurrencyObject(line);
                vMyCurrencies.push_back(Currency);
            }
            MyFile.close();
        }
        return vMyCurrencies;
    }

    bool isEmpty() { return _CurrencyMode == CurrencyMode::EmptyMode; }

    static Currency FindByCode(string country_code)
    {
        country_code = Util::UpperAll(country_code); // to make the code case insistive

        fstream MyFile;
        MyFile.open("TextFiles/CurrenciesData.txt", ios::in);
        string line;

        if (MyFile.is_open())
        {
            while (getline(MyFile, line))
            {
                Currency CurrentCurrency = ConvertRecordToCurrencyObject(line);
                if (CurrentCurrency.GetCode() == country_code)
                {
                    MyFile.close();
                    return CurrentCurrency;
                }
            }
        }
        MyFile.close();
        return GetEmptyCurrency();
    }
    static Currency FindByName(string country_name)
    {
        country_name = Util::UpperAll(country_name); // to make the code case insistive

        fstream MyFile;
        MyFile.open("TextFiles/CurrenciesData.txt", ios::in);
        string line;

        if (MyFile.is_open())
        {
            while (getline(MyFile, line))
            {
                Currency CurrentCurrency = ConvertRecordToCurrencyObject(line);
                if (Util::UpperAll(CurrentCurrency.GetCountryName()) == country_name)
                {
                    MyFile.close();
                    return CurrentCurrency;
                }
            }
        }
        MyFile.close();
        return GetEmptyCurrency();
    }

    static bool isCurrencyExsisted(string CurrencyCode)
    {
        return FindByCode(CurrencyCode).GetCurrencyMode() != EmptyMode;
    }
};