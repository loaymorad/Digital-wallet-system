#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include "Transaction.h"
using namespace std;

class User {
public: 
    string username;
    string password;
    double balance = 0.0;

    stack<Transaction> transactions;  

    queue<Transaction> pendingRequests;  

    bool isSuspended = false;

    User();
    User(string username, string password);
    User(string username, string password, double balance, bool isSuspended);

    // Authentication
    User registerUser();
    User loginUser();
    void logoutUser();

    // Features
    double viewBalance();
    bool sendMoney(const string& to, double amount);
    bool requestMoney(const string& from, double amount);
    void viewTransactionHistory();
    void editProfile();
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
