#include "User.h"
#include "Database.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

static Database db;

// ---------------------- Constructors ----------------------
User::User() {}

User::User(string username, string password) {
    this->username = username;
    this->password = password;
    this->balance = 0.0;
    this->isSuspended = false;
}

User::User(string username, string password, double balance, bool isSuspended) {
    this->username = username;
    this->password = password;
    this->balance = balance;
    this->isSuspended = isSuspended;
}

// ---------------------- Authentication ----------------------
User User::registerUser() {
    string uname, pass;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pass;

    User newUser(uname, pass, 0.0, false);
    if (db.addUser(newUser)) {
        cout << "User registered successfully!\n";
    }
    return newUser;
}

User User::loginUser() {
    string uname, pass;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pass;

    User dbUser = db.getUser(uname);
    if (uname == dbUser.username && pass == dbUser.password && !dbUser.isSuspended) {
        cout << "Login successful!\n";
        return dbUser;
    } else {
        cout << "Login failed. Invalid credentials or account suspended.\n";
        return User();
    }
}

void User::logoutUser() {
    cout << "User " << username << " logged out.\n";
}

// ---------------------- Features ----------------------
double User::viewBalance() {
    cout << "Current balance: " << balance << endl;
    return balance;
}

bool User::sendMoney(const string& to, double amount) {
    if (isSuspended) {
        cout << "Account is suspended. Cannot send money.\n";
        return false;
    }

    if (amount > balance) {
        cout << "Insufficient balance.\n";
        return false;
    }

    // Deduct from sender
    balance -= amount;
    db.updateUser(*this);

    // Record transaction
    Transaction tx(username, to, amount);
    transactions.push(tx);
    db.addTransaction(tx);

    cout << "Sent " << amount << " to " << to << ".\n";
    return true;
}

bool User::requestMoney(const string& from, double amount) {
    if (isSuspended) {
        cout << "Account is suspended. Cannot request money.\n";
        return false;
    }

    pendingRequests.push(Transaction(from, username, amount));
    db.updateUser(*this);

    cout << "Money request of " << amount << " sent to " << from << ".\n";
    return true;
}

void User::viewTransactionHistory() {
    vector<Transaction> txs = db.loadTransactionsFor(username);
    if (txs.empty()) {
        cout << "No transactions found for " << username << ".\n";
        return;
    }

    cout << "Transaction History for " << username << ":\n";
    for (auto& tx : txs) {
        tx.displayTransactionDetails();
    }
}

void User::editProfile() {
    cout << "Editing profile for " << username << endl;
    cout << "Enter new password: ";
    string newPass;
    cin >> newPass;
    password = newPass;
    db.updateUser(*this);
    cout << "Password updated successfully!\n";
}

// ---------------------- Destructor ----------------------
User::~User() {}

// ---------------------- Admin Methods ----------------------
Admin::Admin() {}

void Admin::loginAdmin() {
    string pass;
    cout << "Enter admin password: ";
    cin >> pass;
    if (pass == "admin123") {
        cout << "Admin login successful!\n";
    } else {
        cout << "Wrong admin password!\n";
    }
}

void Admin::viewAllUsers() {
    vector<User> users = db.loadUsers();
    cout << "All Users:\n";
    for (auto& u : users) {
        cout << " - " << u.username
             << " | Balance: " << u.balance
             << " | Suspended: " << (u.isSuspended ? "Yes" : "No") << endl;
    }
}

void Admin::editUser(const string& uname) {
    User u = db.getUser(uname);
    if (u.username.empty()) {
        cout << "User not found.\n";
        return;
    }
    cout << "Enter new password: ";
    string newPass;
    cin >> newPass;
    u.password = newPass;
    db.updateUser(u);
    cout << "User updated.\n";
}

void Admin::suspendUser(const string& uname) {
    User u = db.getUser(uname);
    if (!u.username.empty()) {
        u.isSuspended = true;
        db.updateUser(u);
        cout << "User suspended: " << uname << endl;
    }
}

void Admin::reactivateUser(const string& uname) {
    User u = db.getUser(uname);
    if (!u.username.empty()) {
        u.isSuspended = false;
        db.updateUser(u);
        cout << "User reactivated: " << uname << endl;
    }
}

void Admin::adjustBalance(const string& uname, double amount) {
    User u = db.getUser(uname);
    if (!u.username.empty()) {
        u.balance += amount;
        db.updateUser(u);
        cout << "Balance adjusted for " << uname << endl;
    }
}

void Admin::viewAllTransactions() {
    vector<User> users = db.loadUsers();
    for (auto& u : users) {
        vector<Transaction> txs = db.loadTransactionsFor(u.username);
        if (!txs.empty()) {
            cout << "\nTransactions for " << u.username << ":\n";
            for (auto& t : txs) {
                t.displayTransactionDetails();
            }
        }
    }
}

Admin::~Admin() {}
