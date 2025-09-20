#include "Menu.h"
#include "Database.h"
#include <iostream>
using namespace std;

static Database db;

void Menu::mainMenu() {
    int choice;
    while (true) {
        cout << "\n===== Digital Wallet System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Admin Login\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            User newUser = User().registerUser();
            db.addUser(newUser);

        } else if (choice == 2) {
            string uname, pass;
            cout << "Enter username: ";
            cin >> uname;
            cout << "Enter password: ";
            cin >> pass;

            User user = db.getUser(uname);
            if (user.username == uname && user.password == pass && !user.isSuspended) {
                cout << "Welcome back, " << uname << "!\n";
                userMenu(user);
                db.updateUser(user);
            } else {
                cout << "Invalid login.\n";
            }

        } else if (choice == 3) {
            Admin admin;
            admin.loginAdmin();
            adminMenu();

        } else if (choice == 4) {
            cout << "Goodbye!\n";
            break;

        } else {
            cout << "Invalid choice.\n";
        }
    }
}

void Menu::userMenu(User& user) {
    int choice;
    while (true) {
        cout << "\n===== User Menu =====\n";
        cout << "1. View Balance\n";
        cout << "2. Send Money\n";
        cout << "3. Request Money\n";
        cout << "4. View Transaction History\n";
        cout << "5. Edit Profile\n";
        cout << "6. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            user.viewBalance();

        } else if (choice == 2) {
            string to;
            double amount;
            cout << "Enter recipient username: ";
            cin >> to;
            cout << "Enter amount: ";
            cin >> amount;

            if (user.sendMoney(to, amount)) {
                db.updateUser(user);
                db.addTransaction(Transaction(user.username, to, amount));
            }

        } else if (choice == 3) {
            string from;
            double amount;
            cout << "Enter username to request from: ";
            cin >> from;
            cout << "Enter amount: ";
            cin >> amount;

            user.requestMoney(from, amount);
            db.updateUser(user);

        } else if (choice == 4) {
            user.viewTransactionHistory();

        } else if (choice == 5) {
            user.editProfile();
            db.updateUser(user);

        } else if (choice == 6) {
            user.logoutUser();
            break;

        } else {
            cout << "Invalid choice.\n";
        }
    }
}

void Menu::adminMenu() {
    int choice;
    while (true) {
        cout << "\n===== Admin Menu =====\n";
        cout << "1. View All Users\n";
        cout << "2. Suspend User\n";
        cout << "3. Reactivate User\n";
        cout << "4. Adjust User Balance\n";
        cout << "5. View All Transactions\n";
        cout << "6. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            vector<User> users = db.loadUsers();
            cout << "Registered Users:\n";
            for (auto& u : users) {
                cout << " - " << u.username 
                     << " | Balance: " << u.balance
                     << " | Suspended: " << (u.isSuspended ? "Yes" : "No") << endl;
            }

        } else if (choice == 2) {
            string uname;
            cout << "Enter username to suspend: ";
            cin >> uname;
            User u = db.getUser(uname);
            if (!u.username.empty()) {
                u.isSuspended = true;
                db.updateUser(u);
                cout << "User suspended.\n";
            }

        } else if (choice == 3) {
            string uname;
            cout << "Enter username to reactivate: ";
            cin >> uname;
            User u = db.getUser(uname);
            if (!u.username.empty()) {
                u.isSuspended = false;
                db.updateUser(u);
                cout << "User reactivated.\n";
            }

        } else if (choice == 4) {
            string uname;
            double amount;
            cout << "Enter username: ";
            cin >> uname;
            cout << "Enter amount to adjust (+/-): ";
            cin >> amount;

            User u = db.getUser(uname);
            if (!u.username.empty()) {
                u.balance += amount;
                db.updateUser(u);
                cout << "Balance updated.\n";
            }

        } else if (choice == 5) {
            vector<User> users = db.loadUsers();
            for (auto& u : users) {
                vector<Transaction> txs = db.loadTransactionsFor(u.username);
                if (!txs.empty()) {
                    cout << "\nTransactions for " << u.username << ":\n";
                    for (auto& t : txs) {
                        t.displayTransactionDetails();
                    }
                }
            }

        } else if (choice == 6) {
            cout << "Admin logged out.\n";
            break;

        } else {
            cout << "Invalid choice.\n";
        }
    }
}
