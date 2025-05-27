#pragma once
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
	// Costractors
	Person()
	{

	}
	Person(string firstname, string lastname, string email, string phone)
	{
		FirstName = firstname;
		LastName = lastname;
		Email = email;
		PhoneNumber = phone;
	}
	// Setters
	void SetFirstName(string str) { FirstName = str; }
	void SetLastName(string str) { LastName = str; }
	void SetEmail(string str) { Email = str; }
	void SetPhoneNumber(string str) { PhoneNumber = str; }
	// getters
	string GetFirstName() { return FirstName; }
	string GetLastName() { return LastName; }
	string GetEmail() { return Email; }
	string GetPhoneNumber() { return PhoneNumber; }

};