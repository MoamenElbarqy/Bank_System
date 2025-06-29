#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Global.h"
using namespace std;

class Person
{
private:
	string FirstName;
	string LastName;
	string Email;
	string PhoneNumber;

public:
	// Constructors
	Person();
	Person(string firstname, string lastname, string email, string phone);
	// Setters
	void SetFirstName(string str);
	void SetLastName(string str);
	void SetEmail(string str);
	void SetPhoneNumber(string str);
	// getters
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	string GetPhoneNumber();
};

#endif // PERSON_H