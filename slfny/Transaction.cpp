#include "Transaction.h"
#include <iostream>
using namespace std;

// Start from 1 and increase with every transaction
long long lastTransactionId = 0;

Transaction::Transaction(string sender, string receiver, double amount) {
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;

    // Sequential ID
    transactionId = ++lastTransactionId;

    cout << "Transaction created successfully!\n";
    cout << "ID: " << transactionId << ", From: " << sender << ", To: " << receiver << ", Amount: " << amount << "\n";

    // Note: you may want to save this transaction to database here if needed.
    // But it's better to leave that to wherever this constructor is used.
}

void Transaction::displayTransactionDetails(long long idToShow) {
    if (idToShow == -1 || idToShow == transactionId) {
        cout << "-----------------------------\n";
        cout << "Transaction ID: " << transactionId << "\n";
        cout << "From: " << sender << "\n";
        cout << "To: " << receiver << "\n";
        cout << "Amount: $" << amount << "\n";
    }
}

Transaction::~Transaction() {}
