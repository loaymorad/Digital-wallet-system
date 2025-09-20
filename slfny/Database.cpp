#include "Database.h"
#include <unordered_map>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

static unordered_map<string, User> usersDB; 
static map<string, vector<Transaction>> transactionsDB;

static const string USERS_FILE = "users.txt";
static const string TRANSACTIONS_FILE = "transactions.txt";

// ----------------- Helper Functions -----------------
vector<string> split(const string& line, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(line);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void saveUsersToFile() {
    ofstream out(USERS_FILE);
    for (auto& pair : usersDB) {
        out << pair.second.username << "$"
            << pair.second.password << "$"
            << pair.second.balance << "$"
            << pair.second.isSuspended << "\n";
    }
    out.close();
}

void loadUsersFromFile() {
    ifstream in(USERS_FILE);
    if (!in.is_open()) return;

    string line;
    while (getline(in, line)) {
        vector<string> parts = split(line, '$');
        if (parts.size() == 4) {
            string uname = parts[0];
            string pass = parts[1];
            double bal = stod(parts[2]);
            bool suspended = stoi(parts[3]);

            User u(uname, pass, bal, suspended);
            usersDB[uname] = u;
        }
    }
    in.close();
}

void saveTransactionsToFile() {
    ofstream out(TRANSACTIONS_FILE);
    for (auto& pair : transactionsDB) {
        for (auto& t : pair.second) {
            out << t.sender << "$"
                << t.receiver << "$"
                << t.amount << "\n";
        }
    }
    out.close();
}

void loadTransactionsFromFile() {
    ifstream in(TRANSACTIONS_FILE);
    if (!in.is_open()) return;

    string line;
    while (getline(in, line)) {
        vector<string> parts = split(line, '$');
        if (parts.size() == 3) {
            string sender = parts[0];
            string receiver = parts[1];
            double amount = stod(parts[2]);

            Transaction t(sender, receiver, amount);
            transactionsDB[sender].push_back(t);
            transactionsDB[receiver].push_back(t);
        }
    }
    in.close();
}

// ----------------- User Management -----------------
vector<User> Database::loadUsers() {
    if (usersDB.empty()) loadUsersFromFile();
    vector<User> userList;
    for (auto& pair : usersDB) {
        userList.push_back(pair.second);
    }
    return userList;
}

User Database::getUser(string username) {
    if (usersDB.empty()) loadUsersFromFile();

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
    saveUsersToFile();
    cout << "User added: " << user.username << endl;
    return true;
}

void Database::deleteUser(string username) {
    if (usersDB.erase(username)) {
        saveUsersToFile();
        cout << "User deleted: " << username << endl;
    } else {
        cout << "Cannot delete. User not found: " << username << endl;
    }
}

void Database::updateUser(User user) {
    if (usersDB.find(user.username) != usersDB.end()) {
        usersDB[user.username] = user;
        saveUsersToFile();
        cout << "User updated: " << user.username << endl;
    } else {
        cout << "User not found for update: " << user.username << endl;
    }
}

// ----------------- Transaction Management -----------------
void Database::addTransaction(Transaction transaction) {
    transactionsDB[transaction.sender].push_back(transaction);
    transactionsDB[transaction.receiver].push_back(transaction);
    saveTransactionsToFile();
    cout << "Transaction recorded between " 
         << transaction.sender << " and " << transaction.receiver << endl;
}

vector<Transaction> Database::loadTransactionsFor(string username) {
    if (transactionsDB.empty()) loadTransactionsFromFile();

    if (transactionsDB.find(username) != transactionsDB.end()) {
        return transactionsDB[username];
    }
    cout << "No transactions found for " << username << endl;
    return {};
}

void Database::deleteTransactionFor(string username) {
    if (transactionsDB.erase(username)) {
        saveTransactionsToFile();
        cout << "Transactions deleted for " << username << endl;
    } else {
        cout << "No transactions to delete for " << username << endl;
    }
}
