cmake_minimum_required(VERSION 3.20)
project(BankSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/Client/include
    ${CMAKE_SOURCE_DIR}/User/include
    ${CMAKE_SOURCE_DIR}/Misc/include
    ${CMAKE_SOURCE_DIR}/Screens/include
    ${CMAKE_SOURCE_DIR}/Transactions/include
    ${CMAKE_SOURCE_DIR}/Currency/include
)

add_executable(BankSystem main.cpp
    # ملفات Client
    Client/src/AddClient.cpp
    Client/src/Client.cpp
    Client/src/ClientsList.cpp
    Client/src/DeleteClient.cpp
    Client/src/FindClient.cpp
    Client/src/UpdateClient.cpp

    # ملفات Currency
    Currency/src/CurrenciesList.cpp
    Currency/src/Currency.cpp
    Currency/src/CurrencyCalculator.cpp
    Currency/src/CurrencyExchange.cpp
    Currency/src/FindCurrency.cpp
    Currency/src/UpdateRate.cpp

    # ملفات Misc
    Misc/src/Date.cpp
    Misc/src/Global.cpp
    Misc/src/Input.cpp
    Misc/src/LoginLog.cpp
    Misc/src/Person.cpp
    Misc/src/Util.cpp

    # ملفات Screens
    Screens/src/HeaderScreen.cpp
    Screens/src/LoginScreen.cpp
    Screens/src/MainScreen.cpp

    # ملفات Transactions
    Transactions/src/Deposit.cpp
    Transactions/src/TotalBalances.cpp
    Transactions/src/Transactions.cpp
    Transactions/src/Transfer.cpp
    Transactions/src/TransferLog.cpp
    Transactions/src/Withdraw.cpp

    # ملفات User
    User/src/AddUser.cpp
    User/src/DeleteUser.cpp
    User/src/FindUser.cpp
    User/src/MangeUsers.cpp # ملاحظة: قد يكون هناك خطأ إملائي هنا، ربما "ManageUsers.cpp"
    User/src/UpdateUser.cpp
    User/src/User.cpp
    User/src/UsersList.cpp
)
    )