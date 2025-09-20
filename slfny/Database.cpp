#include "Database.h"
#include <unordered_map>
#include <map>

using namespace std;

static unordered_map<string, User> usersDB; 
static map<string, vector<Transaction>> transactionsDB;

// ----------------- User Management -----------------
vector<User> Database::loadUsers() {
    vector<User> userList;
    for (auto& pair : usersDB) {
        userList.push_back(pair.second);
    }
    return userList;
}

User Database::getUser(string username) {
    if (usersDB.find(username) != usersDB.end()) {
        return usersDB[username];
    }
    cout << "User not found: " << username << endl;
    return User();
}

bool Database::addUser(User& user) {
    if (usersDB.find(user.username) != usersDB.end()) {
        cout << "User already exists: " << user.username << endl;
        return false;
    }
    usersDB[user.username] = user;
    cout << "User added: " << user.username << endl;
    return true;
}

void Database::deleteUser(string username) {
    if (usersDB.erase(username)) {
        cout << "User deleted: " << username << endl;
    } else {
        cout << "Cannot delete. User not found: " << username << endl;
    }
}

void Database::updateUser(User user) {
    if (usersDB.find(user.username) != usersDB.end()) {
        usersDB[user.username] = user;
        cout << "User updated: " << user.username << endl;
    } else {
        cout << "User not found for update: " << user.username << endl;
    }
}

// ----------------- Transaction Management -----------------
void Database::addTransaction(Transaction transaction) {
    transactionsDB[transaction.sender].push_back(transaction);
    transactionsDB[transaction.receiver].push_back(transaction);
    cout << "Transaction recorded between " 
         << transaction.sender << " and " << transaction.receiver << endl;
}

vector<Transaction> Database::loadTransactionsFor(string username) {
    if (transactionsDB.find(username) != transactionsDB.end()) {
        return transactionsDB[username];
    }
    cout << "No transactions found for " << username << endl;
    return {};
}

void Database::deleteTransactionFor(string username) {
    if (transactionsDB.erase(username)) {
        cout << "Transactions deleted for " << username << endl;
    } else {
        cout << "No transactions to delete for " << username << endl;
    }
}
