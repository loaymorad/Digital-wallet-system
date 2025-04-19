#pragma once
#include <iostream>
#include <vector>

#include "User.h"
#include "Transaction.h"

using namespace std;

class Database
{
public:
	vector<User> loadUsers(); // USED
	User getUser(string username);
	void addUser(User& user); // USED
	void deleteUser(string username);
	void updateUser(User user);
	
	
	void addTransaction(Transaction transaction);
	// getTransaction(string senderName)
	vector<Transaction> loadTransactions();

};

