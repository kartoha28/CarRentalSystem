//
// Created by vladi on 23.03.2025.
//

#include "PremiumAccount.h"
#include <iostream>

PremiumAccount::PremiumAccount(std::string name, double balance, double discount, double bonus)
    : Account(name, balance), discount_rate(discount), bonus_rate(bonus) {}

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

