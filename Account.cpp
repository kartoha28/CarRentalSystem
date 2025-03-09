#include "Account.h"
#include <iostream>

//Конструктори та деструктор
Account::Account(int id) : Account(id, "None", 0.0) {}
Account::Account(int id, std::string name) : Account(id, name, 0.0) {}
Account::Account(int id, std::string name, double balance): id(id), name(name), balance(balance) {}
Account::~Account() {
    std::cout << "Account with ID " << id << " is being destroyed.\n";
}

// отримання данних
int Account::getId() const {
    return id;
}

std::string Account::getName() const {
    return name;
}

double Account::getBalance() const {
    return balance;
}

std::vector<int> Account::getRentalHistory() const {
    return rental_history;
}

// Методи роботи з балансом
void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited $" << amount << ". New balance: $" << balance << std::endl;
    } else {
        std::cout << "Deposit amount must be greater than zero.\n";
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        std::cout << "Withdrawn $" << amount << ". New balance: $" << balance << std::endl;
        return true;
    } else {
        std::cout << "Insufficient funds or invalid amount.\n";
        return false;
    }
}

// Додавання запису про оренду авто
void Account::addRental(int car_id) {
    rental_history.push_back(car_id);
}

// Виведення інформації
void Account::displayInfo() const {
    std::cout << "Account ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Balance: $" << balance << "\n"
              << "Rental History: ";
    if (rental_history.empty()) {
        std::cout << "No rentals yet.";
    } else {
        for (int car_id : rental_history) {
            std::cout << car_id << " ";
        }
    }
    std::cout << "\n----------------------\n";
}
