//
// Created by vladi on 23.03.2025.
//

#include "PremiumAccount.h"
#include <iostream>

PremiumAccount::PremiumAccount(std::string name, double balance, double discount, double bonus)
    : Account(name, balance), discount_rate(discount), bonus_rate(bonus) {
}

// Конструктор копіювання
PremiumAccount::PremiumAccount(const PremiumAccount& other)
    : Account(other), discount_rate(other.discount_rate), bonus_rate(other.bonus_rate) {
    std::cout << "Copy constructor called for PremiumAccount ID: " << id << "\n";
}

// Конструктор переміщення
PremiumAccount::PremiumAccount(PremiumAccount&& other) noexcept
    : Account(std::move(other)), discount_rate(other.discount_rate), bonus_rate(other.bonus_rate) {
    std::cout << "Move constructor called for PremiumAccount ID: " << id << "\n";

    other.discount_rate = 0.0;
    other.bonus_rate = 0.0;
}

// Оператор присвоєння копіювання
PremiumAccount& PremiumAccount::operator=(const PremiumAccount& other) {
    if (this != &other) {
        Account::operator=(other); // Викликаємо оператор копіювання базового класу
        discount_rate = other.discount_rate;
        bonus_rate = other.bonus_rate;
    }
    return *this;
}

// Оператор присвоєння переміщення
PremiumAccount& PremiumAccount::operator=(PremiumAccount&& other) noexcept {
    if (this != &other) {
        Account::operator=(std::move(other)); // Викликаємо оператор переміщення базового класу
        discount_rate = other.discount_rate;
        bonus_rate = other.bonus_rate;

        other.discount_rate = 0.0;
        other.bonus_rate = 0.0;
    }
    return *this;
}

PremiumAccount::PremiumAccount(const Account &other)
    : Account(other) {
}

void PremiumAccount::deposit(double amount) {
    if (amount > 0) {
        double bonus = amount * bonus_rate;
        balance += amount + bonus;
        std::cout << "Deposited $" << amount << " + Bonus $" << bonus << ". New balance: $" << balance << std::endl;
    } else {
        std::cout << "Deposit amount must be greater than zero.\n";
    }
}

double PremiumAccount::getDiscountRate() const {
    return discount_rate;
}

double PremiumAccount::applyDiscount(double price) const {
    return price * (1 - discount_rate);
}

void PremiumAccount::displayInfo() const {
    Account::displayInfo();
    std::cout << "Premium Discount Rate: " << discount_rate * 100 << "%\n"
            << "Bonus Rate: " << bonus_rate * 100 << "%\n"
            << "----------------------\n";
}
