#include "User.h"
#include "Database.h"
#include "Transaction.h"
#include<string>

/*
    - don't forget to add error handling
*/



using namespace std;

// =======================
//          User
// =======================

User::User(){}

User::User(string name, string pass) {
    username = name, password = pass;
    balance = 0.0;
    transactions = { };
    isSuspended = false;
}

void User::registerUser() {
    string name, pass;
    
    cout << "Enter Username: ";
    getline(cin, name);
    cout << "Enter Password: ";
    getline(cin, pass);

    User newUser = User(name, pass);
    
    Database db;
    db.addUser(newUser);

}

void User::loginUser() {
    string name, pass;

    cout << "Enter Username: ";
    getline(cin, name);
    cout << "Enter Password: ";
    getline(cin, pass);

    Database db;
    string userFromDb = db.getUser(name); // must return all his informations return object User
    if (userFromDb != NULL || userFromDb != "") {
        if (userFromDb.password == pass) {
            cout << "logged in :)";
        }
        else {
            cout << "username or password is wrong please try again :(";
        }
    }
    else
    {
        cout << "you are not logged in please register";
    }

}

void User::logoutUser() {
    // may be call the destructor
}

double User::viewBalance() {
    return balance;
}

bool User::sendMoney(const string& to, double amount) {
    Database db;
    
    // check if receiver in our db
    string userFromDb = db.getUser(to);

    if (userFromDb != NULL || userFromDb != "") {
        // check if my balance cover the amount
        if (balance >= amount) {
            balance -= amount;
            Transaction transaction = new Transaction(username, to, amount);

            // add to database logs
            db.addTransaction(transaction);
        }
        else
        {
            cout << "your are poor to send this amount of money ahhhhhh!" << endl;
            cout << "try lower amount of money to send";
        }
    }
    else
    {
        cout << "wrong reciever username";
    }

}

bool User::requestMoney(const string& from, double amount) {
    return false;
}

void User::viewTransactionHistory() {
}

void User::editProfile() {
}

User::~User() {
}
