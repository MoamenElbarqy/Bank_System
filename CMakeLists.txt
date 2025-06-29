cmake_minimum_required(VERSION 3.20)
project(BankSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/Client/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/User/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/Misc/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/Screens/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/Transactions/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/Currency/include"
)

add_executable(BankSystem
     main.cpp
    # Client
    Client/src/AddClient.cpp
    Client/src/Client.cpp
    Client/src/ClientsList.cpp
    Client/src/DeleteClient.cpp
    Client/src/FindClient.cpp
    Client/src/UpdateClient.cpp

    #  Currency
    Currency/src/CurrenciesList.cpp
    Currency/src/Currency.cpp
    Currency/src/CurrencyCalculator.cpp
    Currency/src/CurrencyExchange.cpp
    Currency/src/FindCurrency.cpp
    Currency/src/UpdateRate.cpp

    #  Misc
    Misc/src/Date.cpp
    Misc/src/Global.cpp
    Misc/src/Input.cpp
    Misc/src/LoginLog.cpp
    Misc/src/Person.cpp
    Misc/src/Util.cpp

    #  Screens
    Screens/src/HeaderScreen.cpp
    Screens/src/LoginScreen.cpp
    Screens/src/MainScreen.cpp

    #  Transactions
    Transactions/src/Deposit.cpp
    Transactions/src/TotalBalances.cpp
    Transactions/src/Transactions.cpp
    Transactions/src/Transfer.cpp
    Transactions/src/TransferLog.cpp
    Transactions/src/Withdraw.cpp

    #  User
    User/src/AddUser.cpp
    User/src/DeleteUser.cpp
    User/src/FindUser.cpp
    User/src/MangeUsers.cpp
    User/src/UpdateUser.cpp
    User/src/User.cpp
    User/src/UsersList.cpp
)