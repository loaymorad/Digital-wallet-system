#include "Database.h"
#include "User.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

/*
fstream recap
fstream file;
file.open("filename.txt", ios::out)
ios::
	- out: write 
	- app: append
	- in: get data
if (file.isopen())
// add to file
file << "hack"; -- smiler to --> cout << "hack"; output in file | output in console

// get from file
getline(file, variable)
get first line and add it to variable

*/



// USER CRUD Operations

void Database::addUser(User& user) {
    // Data Format: username,password,balance,isSuspended
    fstream file;
    string filename = "users.txt";

    file.open(filename, ios::app);

    if (file.is_open()) {
        file << user.username << ","
            << user.password << ","
            << user.balance << ","
            << user.isSuspended << endl;
    }
    else {
        cout << "There is an error in opening file: " << filename << endl;
    }

    file.close();
}


void Database::updateUser(User user) {


};

void Database::deleteUser(string username) {


};



User Database::getUser(string username) { // add with transaction parameter with a handy method private to get the transactions from the text file that for a specific user


};

vector<User> Database::loadUsers() { // add with transaction parameter with a handy method private to get the transactions from the text file that for a specific user


};



// Transactions CRUD Operations

vector<Transaction> Database::loadTransactions() {


};
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


