#include "User.h"
#include "Database.h"
#include "Transaction.h"
#include "Menu.h"
#include<string>
#include <iostream>
#include <iomanip> 

/*
    - don't forget to add error handling
*/



using namespace std;

// =======================
//          User
// =======================

User::User() {
    username = "";
    password = "";
    balance = 0.0;
    transactions = {};
    isSuspended = false; // Default to not suspended
}

User::User(string name, string pass) {
    username = name, password = pass;
    balance = 500.0; // Register bonus signup get 500 pound for free "i made that doctor to test that we check for upper limit for transaction"
    transactions = { };
    isSuspended = false;
}

User::User(string name, string pass, double bal, bool isSus) {
    username = name, password = pass;
    balance = bal;
    transactions = { };
    isSuspended = isSus;
}

// -------- Authentication -------- DONE

User User::registerUser() {
    string name, pass;
    
    cout << "Enter Username: ";
    getline(cin, name);
    cout << "Enter Password: ";
    getline(cin, pass);

    Database db;
    while (true) {
        User userFromDb = db.getUser(name); 
        if (userFromDb.username != "") { // Exists
            cout << "Sorry, this username is taken. Try another." << endl;
            cout << "Enter Username: ";
            getline(cin, name); // Prompt for a new username
        } else {
            User newUser = User(name, pass);
            db.addUser(newUser); // Consider adding error handling here
            return newUser;
        }
    }
}

User User::loginUser() {
    string name, pass;

    cout << "Enter Username: ";
    getline(cin, name);
    cout << "Enter Password: ";
    getline(cin, pass);

    Database db;
    User userFromDb = db.getUser(name); 

    if (userFromDb.username != "") {
        if (userFromDb.password == pass) {
            cout << "Logged in :)" << endl;
            return userFromDb;
        } else {
            cout << "Username or password is wrong, please try again :(" << endl;
            // Consider using a loop instead of recursion
            return loginUser(); // This could be replaced with a loop
        }
    } else {
        cout << "You are not logged in, please register." << endl;
        cout << "register Process" << endl;
        return registerUser(); // This could also be replaced with a loop
    }
}

void User::logoutUser() {
    Menu menu;
    menu.mainMenu();
}





// -------- Features --------

// DONE
double User::viewBalance() {
    return balance;
}

// DONE
bool User::sendMoney(const string& to, double amount) {
    Database db;

    // Check if receiver is in our db
    User userFromDb = db.getUser(to); // Should return a User object

    if (userFromDb.username != "") { // Check if user exists
        // Check if my balance covers the amount
        if (balance >= amount) {
            balance -= amount;
            Transaction transaction(username, to, amount); // Corrected instantiation

            // Add to database logs
            db.addTransaction(transaction);
            return true; // Indicate success
        } else {
            cout << "You do not have enough balance to send this amount!" << endl;
            cout << "Try a lower amount to send." << endl;
            return false; // Indicate failure
        }
    } else {
        cout << "Wrong receiver username." << endl;
        return false; // Indicate failure
    }
}


bool User::requestMoney(const string& from, double amount) { // not Implemented YET
    return false;
}

// DONE
void User::viewTransactionHistory() {
    if (transactions.empty()) {
        cout << "No transactions found." << endl;
        return;
    }

    cout << "Transaction History for " << username << ":" << endl;
    for (const auto& transaction : transactions) {
        cout << "Sender: " << transaction.sender 
             << ", Receiver: " << transaction.receiver 
             << ", Amount: " << fixed << setprecision(2) << transaction.amount << endl;
    }
}

// DONE
void User::editProfile() {
    string newUsername, newPassword;

    cout << "Enter new username (leave blank to keep current): ";
    getline(cin, newUsername);
    cout << "Enter new password (leave blank to keep current): ";
    getline(cin, newPassword);

    if (!newUsername.empty()) {
        username = newUsername;
    }

    if (!newPassword.empty()) {
        password = newPassword;
    }

    Database db;
    db.updateUser(*this);
    cout << "Profile updated successfully." << endl;
}

User::~User() {
}
