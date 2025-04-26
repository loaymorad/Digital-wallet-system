#include "Transaction.h"
#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

// Constructor
Transaction::Transaction(string sender, string receiver, double amount) 
    : sender(sender), receiver(receiver), amount(amount) {}

// Method to display transaction details
void Transaction::displayTransactionDetails() {
    std::cout << "Transaction Details: " << std::endl;
    std::cout << "Sender: " << sender << std::endl;
    std::cout << "Receiver: " << receiver << std::endl;
    std::cout << "Amount: " << std::fixed << std::setprecision(2) << amount << std::endl;
}

// Destructor
Transaction::~Transaction() {
    // No dynamic memory to free, but can be used for logging or cleanup if needed
}