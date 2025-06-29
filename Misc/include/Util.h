#ifndef UTIL_H
#define UTIL_H

#include <cctype>
#include <string>
#include <vector>
#include <iostream>

class Util
{
public:
	static string DecryptText(string Text, short EncryptionKey = 12 + 11);
	static string EncryptText(string Text, short EncryptionKey = 12 + 11);
	static bool ContinueOperation(string msg = "\nAre You Sure To Perform This Operation (y / n) : ");
	static vector<string> SplitRecord(string str, string delimiter = "#//#");
	static string UpperAll(string str);
};

#endif // UTIL_H

