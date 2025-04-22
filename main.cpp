#include <iostream>
#include "RentalSystem.h"
#include "AuthManager.h"
#include "Account.h"
#include "Motorcycle.h"
#include "Bus.h"
#include "PremiumAccount.h"
#include "Truck.h"

void userMenu(RentalSystem& system, Account* user) {
    int choice;
    do {
        std::cout << "\n--- User Menu ---\n";
        std::cout << "1. View available vehicles\n";
        std::cout << "2. Rent vehicle\n";
        std::cout << "3. Return vehicle\n";
        std::cout << "4. Deposit money\n";
        std::cout << "5. View account info\n";
        std::cout << "6. View rental history\n";
        std::cout << "0. Logout\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system.displayVehicles();
                break;
            case 2: {
                int vehicleId, days;
                std::cout << "Enter Vehicle ID: ";
                std::cin >> vehicleId;
                std::cout << "Enter number of days: ";
                std::cin >> days;
                system.rentVehicle(user->getId(), vehicleId, days);
                break;
            }
            case 3: {
                int orderId;
                std::cout << "Enter Order ID to return: ";
                std::cin >> orderId;
                system.returnVehicle(orderId);
                break;
            }
            case 4: {
                double amount;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                user->deposit(amount);
                std::cout << "Deposit successful.\n";
                break;
            }
            case 5:
                user->displayAccountInfo();
                break;
            case 6:
                user->displayRentalHistory(system);
                break;

            case 0:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid option!\n";
        }
    } while (choice != 0);
}

void adminMenu(RentalSystem& system) {
    int choice;
    do {
        std::cout << "\n--- Admin Menu ---\n";
        std::cout << "1. Add vehicle\n";
        std::cout << "2. View all vehicles\n";
        std::cout << "3. View all accounts\n";
        std::cout << "4. View all orders\n";
        std::cout << "0. Logout\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Adding vehicle is not implemented yet.\n";
                break;
            case 2:
                system.displayVehicles();
                break;
            case 3:
                system.displayAccounts();
                break;
            case 4:
                system.displayOrders();
                break;
            case 0:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid option!\n";
        }
    } while (choice != 0);
}

int main() {

    RentalSystem system;
    system.loadData();
    AuthManager auth(system);

    while (true) {
        std::cout << "\n--- Welcome to Vehicle Rental System ---\n";
        std::cout << "1. Login as User\n";
        std::cout << "2. Register as New User\n";
        std::cout << "3. Login as Admin\n";
        std::cout << "0. Exit\n";
        std::cout << "Your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Account* user = auth.loginUser();
                if (user) userMenu(system, user);
                break;
            }
            case 2:
                auth.registerUser();
                break;
            case 3: {
                if (auth.loginAdmin()) adminMenu(system);
                break;
            }
            case 0:
                std::cout << "Exiting...\n";
                system.saveData();
            return 0;
            default:
                std::cout << "Invalid option.\n";
        }
    }


    return 0;
}
