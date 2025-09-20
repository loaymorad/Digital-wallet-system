#pragma once
#include <iostream>
#include <vector>
#include <cstdarg>

#include "User.h"
#include "Transaction.h"

using namespace std;

class Database
{
public:
	vector<User> loadUsers();
	User getUser(string username);
	bool addUser(User& user);
	void deleteUser(string username);
	void updateUser(User user);
	
	void addTransaction(Transaction transaction);
	vector<Transaction> loadTransactionsFor(string username);
	void deleteTransactionFor(string username);

};

