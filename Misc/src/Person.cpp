#include "Person.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

Person::Person()
{
    // Empty constructor
}

Person::Person(string firstname, string lastname, string email, string phone)
{
    FirstName = firstname;
    LastName = lastname;
    Email = email;
    PhoneNumber = phone;
}

// Setters
void Person::SetFirstName(string str) { FirstName = str; }
void Person::SetLastName(string str) { LastName = str; }
void Person::SetEmail(string str) { Email = str; }
void Person::SetPhoneNumber(string str) { PhoneNumber = str; }

// getters
string Person::GetFirstName() { return FirstName; }
string Person::GetLastName() { return LastName; }
string Person::GetEmail() { return Email; }
string Person::GetPhoneNumber() { return PhoneNumber; } 