#pragma once
#include <iostream>
#include <vector>
#include "Transaction.h"

class User {
public: 
    string username;
    string password;
    double balance;
    vector<Transaction> transactions;
    bool isSuspended;

    User();
    User(string username, string password);

    void registerUser();

    void loginUser();

    void logoutUser();

    double viewBalance();

    bool sendMoney(const string& to, double amount);

    bool requestMoney(const string& from, double amount);
    
    void   viewTransactionHistory(); // using database

    void   editProfile(); // username email password


    ~User();
};


class Admin : public User {
public:
    Admin();

    void loginAdmin();
    void viewAllUsers();
    
    void editUser(const string& username);
    
    void suspendUser(const string& username);
    
    void reactivateUser(const string& username);
    
    void adjustBalance(const string& username, double amount);

    void viewAllTransactions();

    ~Admin();
};
