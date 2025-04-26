#include "Menu.h"
#include "User.h"
#include <iostream>
#include <string>

using namespace std;

void Menu::mainMenu() { // For AUTH : assign current user to his data : redirct him to userMenu OR adminMenu
    int choice;
    User currentUser;

    do {
        cout << "== Main Menu ==" << endl;
        cout << "   1. User Signup" << endl;
        cout << "   2. User Login" << endl;
        cout << "   3. Admin Login" << endl;
        cout << "   4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                currentUser = currentUser.registerUser();
                Menu::userMenu(currentUser);
                break;
            case 2:
                currentUser = currentUser.loginUser();
                Menu::userMenu(currentUser);
                break;
            case 3:
                // adminLogin
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);
}

void Menu::userMenu(User& currentUser) {
    int choice;

    do {
        cout << "== User Menu ==" << endl;
        cout << "   1. View Balance" << endl;
        cout << "   2. Send Money" << endl;
        cout << "   3. View Transaction History" << endl;
        cout << "   4. Edit Profile" << endl;
        cout << "   5. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Your balance is: " << currentUser.viewBalance() << endl;
                break;
            case 2: {
                string recipient;
                double amount;
                cout << "Enter recipient username: ";
                getline(cin, recipient);
                cout << "Enter amount to send: ";
                cin >> amount;
                cin.ignore(); 

                if (currentUser.sendMoney(recipient, amount)) {
                    cout << "Money sent successfully!" << endl;
                } else {
                    cout << "Failed to send money." << endl;
                }
                break;
            }
            case 3:
                currentUser.viewTransactionHistory();
                break;
            case 4:
                currentUser.editProfile();
                break;
            case 5:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);
}


void Menu::adminMenu(){



};

