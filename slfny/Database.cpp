#include "Database.h"
#include "User.h"
#include "Transaction.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

// USER CRUD Operations

// DONE
bool Database::addUser(User& user) {
    // Data Format: username,password,balance,isSuspended
    fstream file;
    string filename = "users.txt";

    file.open(filename, ios::app);

    if (file.is_open()) {
        file << user.username << ","
            << user.password << ","
            << user.balance << ","
            << user.isSuspended << endl;
        return true;
    }
    else {
        cout << "There is an error in opening file: " << filename << endl;
        return false;
    }

    file.close();
}

User Database::getUser(string username) {
    fstream file;
    string filename = "users.txt";
    string line;

    file.open(filename, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string userName, password, balanceStr, isSuspendedStr;

            getline(ss, userName, ',');
            getline(ss, password, ',');
            getline(ss, balanceStr, ',');
            getline(ss, isSuspendedStr, ',');

            if (userName == username) {

                User user  = User(userName, password, stod(balanceStr), (isSuspendedStr == "1"));

                user.transactions = loadTransactionsFor(user.username);

                file.close();
                return user;
            }
        }
        file.close();
    } else {
        cout << "There is an error in opening file: " << filename << endl;
    }

    return User();
}

vector<User> Database::loadUsers() {
    fstream file;
    string filename = "users.txt";
    string line;
    vector<User> users;

    file.open(filename, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string userName, password, balanceStr, isSuspendedStr;

            getline(ss, userName, ',');
            getline(ss, password, ',');
            getline(ss, balanceStr, ',');
            getline(ss, isSuspendedStr, ',');

            User user  = User(userName, password, stod(balanceStr), (isSuspendedStr == "1"));

            user.transactions = loadTransactionsFor(user.username);

            users.push_back(user); 
        }
        file.close();
    } else {
        cout << "There is an error in opening file: " << filename << endl;
    }

    return users;
}



void Database::updateUser(User user) {
    fstream file;
    string filename = "users.txt";
    string line;
    vector<User> users;

    file.open(filename, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string userName, password, balanceStr, isSuspendedStr;

            getline(ss, userName, ',');
            getline(ss, password, ',');
            getline(ss, balanceStr, ',');
            getline(ss, isSuspendedStr, ',');

            User existingUser  = User(userName, password, stod(balanceStr), (isSuspendedStr == "1"));

            if (existingUser.username == user.username) {
                existingUser.password = user.password; 
                existingUser.balance = user.balance;
                existingUser.isSuspended = user.isSuspended;
            }

            users.push_back(existingUser);
        }
        file.close();
    } else {
        cout << "There is an error in opening file: " << filename << endl;
        return;
    }

    // Write updated users back to the file
    file.open(filename, ios::out | ios::trunc);
    if (file.is_open()) {
        for (const auto& existingUser : users) {
            file << existingUser.username << ","
                 << existingUser.password << ","
                 << existingUser.balance << ","
                 << existingUser.isSuspended << endl;
        }
        file.close();
    } else {
        cout << "There is an error in opening file: " << filename << endl;
    }
}


// USED BY THE ADMIN
void Database::deleteUser(string username) {
    fstream file;
    string filename = "users.txt";
    string line;
    vector<User> users;

    // Load existing users
    file.open(filename, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string userName, password, balanceStr, isSuspendedStr;

            getline(ss, userName, ',');
            getline(ss, password, ',');
            getline(ss, balanceStr, ',');
            getline(ss, isSuspendedStr, ',');

            // Only add users that are not being deleted
            if (userName != username) {
                User existingUser;
                existingUser.username = userName;
                existingUser.password = password;
                existingUser.balance = stod(balanceStr);
                existingUser.isSuspended = (isSuspendedStr == "1");
                users.push_back(existingUser); // Add to the list
            }
        }
        file.close();
    } else {
        cout << "There is an error in opening file: " << filename << endl;
        return;
    }

    // Write remaining users back to the file
    file.open(filename, ios::out | ios::trunc);
    if (file.is_open()) {
        for (const auto& existingUser : users) {
            file << existingUser.username << ","
                 << existingUser.password << ","
                 << existingUser.balance << ","
                 << existingUser.isSuspended << endl;
        }
        file.close();
    } else {
        cout << "There is an error in opening file: " << filename << endl;
    }
}



// Transactions CRUD Operations

vector<Transaction> Database::loadTransactionsFor(string username) {
    fstream file;
    string filename = "transaction.txt";
    string line;
    vector<Transaction> transactions;

    file.open(filename, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string sender, receiver, amountStr;

            getline(ss, sender, ',');
            getline(ss, receiver, ',');
            getline(ss, amountStr, ',');

            if (sender == username || receiver == username) {
                Transaction transaction(sender, receiver, stod(amountStr));

                transactions.push_back(transaction);
            }
        }
        file.close();
    } else {
        cout << "There is an error in opening file: " << filename << endl;
    }

    return transactions; 
}

void Database::addTransaction(Transaction transaction) {
    // Data Format: sender,receiver,amount

    fstream file;
    string filename = "transaction.txt";

    file.open(filename, ios::app);

    if (file.is_open()) {
        file << transaction.sender << ","
             << transaction.receiver << ","
             << transaction.amount << endl;
    }
    else {
        cout << "There is an error in opening file: " << filename << endl;
    }

    file.close();
};

void Database::deleteTransactionFor(string username) {
    fstream file;
    string filename = "transaction.txt";
    string line;
    vector<Transaction> transactions;

    file.open(filename, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string sender, receiver, amountStr;

            getline(ss, sender, ',');
            getline(ss, receiver, ',');
            getline(ss, amountStr, ',');

            if (sender != username && receiver != username) {
                Transaction transaction(sender, receiver, stod(amountStr));
                transactions.push_back(transaction); 
            }
        }
        file.close();
    } else {
        cout << "There is an error in opening file: " << filename << endl;
        return;
    }

    file.open(filename, ios::out | ios::trunc);
    if (file.is_open()) {
        for (const auto& transaction : transactions) {
            file << transaction.sender << ","
                 << transaction.receiver << ","
                 << transaction.amount << endl;
        }
        file.close();
    } else {
        cout << "There is an error in opening file: " << filename << endl;
    }
}