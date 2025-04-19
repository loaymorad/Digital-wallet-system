#pragma once
#include<iostream>
using namespace std;


class Transaction
{
public:
	string sender;
	string receiver;
	double amount;

	Transaction(string sender, string receiver, double amount);

	void displayTransactionDetails();

	~Transaction();
};

