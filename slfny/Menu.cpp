#include "Menu.h"
#include "User.h"
#include "Database.h"
#include <iostream>

using namespace std;

void Menu::mainMenu() {
    int choice;
    User currentUser;
    Admin currentAdmin;

    while (true) {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Admin Login\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            currentUser.registerUser();
            break;
        case 2:
            currentUser.loginUser();
            userMenu(); // Show user menu after login
            break;
        case 3:
            // Assume Admin login is the same as User login for now
            currentAdmin.loginUser();
            adminMenu(); // Show admin menu after login
            break;
        case 0:
            cout << "Goodbye!\n";
            return;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

void Menu::userMenu() {
    int choice;
    User user; // This could be passed in future

    while (true) {
        cout << "\n========== USER MENU ==========\n";
        cout << "1. View Balance\n";
        cout << "2. Send Money\n";
        cout << "3. Request Money\n";
        cout << "4. View Transaction History\n";
        cout << "5. Edit Profile\n";
        cout << "6. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Your balance: $" << user.viewBalance() << "\n";
            break;
        case 2: {
            string to;
            double amount;
            cout << "Enter recipient username: ";
            cin >> to;
            cout << "Enter amount: ";
            cin >> amount;
            user.sendMoney(to, amount);
            break;
        }
        case 3: {
            string from;
            double amount;
            cout << "Enter sender username: ";
            cin >> from;
            cout << "Enter amount: ";
            cin >> amount;
            user.requestMoney(from, amount);
            break;
        }
        case 4:
            user.viewTransactionHistory();
            break;
        case 5:
            user.editProfile();
            break;
        case 6:
            user.logoutUser();
            return; // back to main menu
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

void Menu::adminMenu() {
    int choice;
    Admin admin; // This could also be passed in

    while (true) {
        cout << "\n========== ADMIN MENU ==========\n";
        cout << "1. View All Users\n";
        cout << "2. Edit User\n";
        cout << "3. Suspend User\n";
        cout << "4. Reactivate User\n";
        cout << "5. Adjust User Balance\n";
        cout << "6. View All Transactions\n";
        cout << "7. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            admin.viewAllUsers();
            break;
        case 2: {
            string user;
            cout << "Enter username to edit: ";
            cin >> user;
            admin.editUser(user);
            break;
        }
        case 3: {
            string user;
            cout << "Enter username to suspend: ";
            cin >> user;
            admin.suspendUser(user);
            break;
        }
        case 4: {
            string user;
            cout << "Enter username to reactivate: ";
            cin >> user;
            admin.reactivateUser(user);
            break;
        }
        case 5: {
            string user;
            double amount;
            cout << "Enter username: ";
            cin >> user;
            cout << "Enter new balance: ";
            cin >> amount;
            admin.adjustBalance(user, amount);
            break;
        }
        case 6:
            admin.viewAllTransactions();
            break;
        case 7:
            admin.logoutUser();
            return;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
