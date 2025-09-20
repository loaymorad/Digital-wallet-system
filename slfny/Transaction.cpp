#include "Transaction.h"
#include "Database.h"
#include <iostream>
using namespace std;

static Database db;

Transaction::Transaction(string sender, string receiver, double amount) {
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
}

void Transaction::displayTransactionDetails() {
    cout << "Transaction Details:\n";
    cout << "   Sender:   " << sender << endl;
    cout << "   Receiver: " << receiver << endl;
    cout << "   Amount:   " << amount << endl;
    cout << "------------------------------------\n";
}

void Transaction::save() {
    db.addTransaction(*this);
    cout << "Transaction saved to database.\n";
}

Transaction::~Transaction() {}
