#include "Account.h"
#include "RentalSystem.h"
#include <iostream>

int Account::last_id=0;

//Конструктори та деструктор
//Account::Account() : Account("None", 0.0) {}
Account::Account(std::string name, std::string password) : Account(name, password, 0.0) {}
Account::Account(std::string name, std::string password, double balance): id(++last_id), name(name), password(password), balance(balance) {}
Account::~Account() {
    std::cout << "Account with ID " << id << " is being destroyed.\n";
}


// Конструктор копіювання
Account::Account(const Account& other)
    : id(other.id), name(other.name),password(other.password), balance(other.balance), rental_history(other.rental_history) {
    std::cout << "Copy constructor called for Account ID: " << id << "\n";
}

// Конструктор переміщення
Account::Account(Account&& other) noexcept
    : id(other.id), name(std::move(other.name)), password(std::move(other.password)), balance(other.balance), rental_history(std::move(other.rental_history)) {
    std::cout << "Move constructor called for Account ID: " << id << "\n";

    other.id = 0;
    other.balance = 0.0;
}

// Оператор присвоєння копіювання
Account& Account::operator=(const Account& other) {
    if (this != &other) {
        name = other.name;
        password = other.password;
        balance = other.balance;
        rental_history = other.rental_history;
    }
    return *this;
}

// Оператор присвоєння переміщення
Account& Account::operator=(Account&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        password = std::move(other.password);
        balance = other.balance;
        rental_history = std::move(other.rental_history);

        other.id = 0;
        other.balance = 0.0;
    }
    return *this;
}

void Account::setId(int new_id) {
    id = new_id;
    last_id = new_id;
}

// отримання данних
int Account::getId() const {
    return id;
}

std::string Account::getName() const {
    return name;
}

std::string Account::getPassword() const {
    return password;
}

double Account::getBalance() const {
    return balance;
}

std::vector<int> Account::getRentalHistory() const {
    return rental_history;
}

int Account::numberOfUser() {
    return last_id;
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
void Account::addRental(int order_id) {
    rental_history.push_back(order_id);
}

void Account::displayAccountInfo() const {
    std::cout << "Account ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Balance: $" << balance << "\n";
}

void Account::displayRentalHistory(const RentalSystem& system) const {
    std::cout << "\n--- Rental History for Account ID: " << id << " ---\n";
    if (rental_history.empty()) {
        std::cout << "No rental history available.\n";
        return;
    }
    for (int orderId : rental_history) {
        const RentalOrder* order = system.getOrderById(orderId);
        if (order) {
            order->displayInfo();
        }
    }
}

// Виведення інформації
void Account::displayInfo() const {
    std::cout << *this;
}

// Перевантаження оператора <<
std::ostream& operator<<(std::ostream& out, const Account& account) {
    out << "Account ID: " << account.id << "\n"
        << "Name: " << account.name << "\n"
        << "Balance: $" << account.balance << "\n"
        << "Rental History: ";
    if (account.rental_history.empty()) {
        out << "No rentals yet.";
    } else {
        for (int car_id : account.rental_history) {
            out << car_id << " ";
        }
    }
    out << "\n----------------------\n";
    return out;
}
