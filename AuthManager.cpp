//
// Created by vladi on 20.04.2025.
//

#include "AuthManager.h"
#include <iostream>

AuthManager::AuthManager(RentalSystem& system) : rentalSystem(system) {}

Account* AuthManager::loginUser() {
    std::string username, password;
    std::cout << "\n--- User Login ---\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    for (const auto& acc : rentalSystem.getAccounts()) {
        if (acc->getName() == username && acc->getPassword() == password) {
            std::cout << "Login successful!\n";
            return acc.get();
        }
    }
    std::cout << "Invalid username or password.\n";
    return nullptr;
}

bool AuthManager::loginAdmin() {
    std::string username, password;
    std::cout << "\n--- Admin Login ---\n";
    std::cout << "Enter admin username: ";
    std::cin >> username;
    std::cout << "Enter admin password: ";
    std::cin >> password;

    // Тимчасово хардкодимо доступ
    if (username == "admin" && password == "admin123") {
        std::cout << "Admin login successful!\n";
        return true;
    }
    std::cout << "Invalid admin credentials.\n";
    return false;
}

void AuthManager::registerUser() {
    std::string username, password;
    std::cout << "\n--- User Registration ---\n";
    std::cout << "Enter new username: ";
    std::cin >> username;
    std::cout << "Enter new password: ";
    std::cin >> password;

    auto newAccount = std::make_unique<Account>(username, password);
    rentalSystem.addAccount(std::move(newAccount));

    std::cout << "Account registered successfully!\n";
}


