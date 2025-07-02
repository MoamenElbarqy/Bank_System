# 🏦 BankSystem  

**BankSystem** developed using **Object-Oriented Programming (OOP) in C++**.  
This project simulates real-world banking operations with a strong focus on **Account management, User management, Financial transactions**.  
The system ensures that users without the required permissions cannot perform restricted operations.  
##  Notes

Defualt user to login : 
~~~
Username : User1

Password : 1234
~~~

All Phone Numbers And Emails are fake 

The System Prevent You From Deleting The User You Have Entered With, No Meaning For Deleting Myself

Currencies Data is not up to date, But You Can Update its Rate in File Using The System

You May Have a Formatting Issues If You Run From Terminal, You Can Run The .exe file directly or From cmd



##  Installation & Usage

You should edit the files paths with your paths

- `CurrenciesData.txt`  
- `Users.txt`  
- `LoginLog.txt`  
- `TransferLog.txt`  
- `ClientsData.txt` 

Clone this repository or download the source files.


Compile and run the program.


##  Features  
[Click here to view the demo](https://drive.google.com/file/d/1b_9j9B_1EYfWbmuc04tWoWGSClYgrmi_/view?usp=drive_link)
###  Client Management  
- View all registered clients.  
- Add, delete, update, and search for clients.  

###  User Management  
- Manage system users with different access levels.  
- Add, delete, update, and list users.  

###  Transaction System  
- Deposit and withdraw funds.  
- Transfer money between accounts.  
- View transaction history and total balances.  

###  Currency Exchange Operations  
- Display a list of currencies from different countries.  
- Search for a specific currency by its code or country name.  
- Calculator for Converting Currencies (e.g., I have 1000 EGP and want to know how many Dollars or Euros that equals)
- Update exchange rates (relative to the US dollar).  

###  Security & Logging  
- **System Will Close After 3 Failed Login Attempts**  
- **Login Activity Tracking:** Stores login details, including the user, login time, and date in text files.  
- **Transaction Logging:** Records money transfers, including sender and receiver details, transfer time and date, and account balances before and after the transaction.  


##  User Interface  

###  Login Menu  

The login menu looks like this:  

~~~
===============================
         Login Screen      
===============================
 Enter Username: ________
 Enter Password: ________
-------------------------------
~~~
##  Main Menu

Once logged in, users are greeted with the Main Menu, which looks like this:
~~~
===================================
          Main Menu Screen
===================================
[1] Show Client List.  
[2] Add New Client.  
[3] Delete Client.  
[4] Update Client Info.  
[5] Find Client. 
[6] Transactions.  
[7] Manage Users.  
[8] Login Register.  
[9] Currency Exchange.
[10] Logout 
===================================
~~~

## Transactions Menue

Transactions Menue looks like this:
~~~
===================================
          Transactions Menue
===================================
[1] Deposit.  
[2] Withdraw.  
[3] Total Balances.  
[4] Transfer.  
[5] Transfer Data. 
[6] Main Menu.  
===================================
~~~
## Currency Exchange Menue

Currency Exchange Menue looks like this:

~~~
===================================
          Currency Exchange Menue
===================================
[1] List Currencies.  
[2] Find Currencuey.  
[3] Update Rate.  
[4] Currency Calculator. 
[5] Main Menu.   
===================================
~~~
