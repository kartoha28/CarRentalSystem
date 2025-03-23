//
// Created by vladi on 23.03.2025.
//

#ifndef PREMIUM_ACCOUNT_H
#define PREMIUM_ACCOUNT_H

#include "Account.h"

class PremiumAccount : public Account {
private:
    double discount_rate; // Відсоток знижки на оренду
    double bonus_rate;    // Відсоток бонусів при поповненні балансу

public:
    PremiumAccount(std::string name, double balance, double discount = 0.1, double bonus = 0.05);

    void deposit(double amount) override; // Перевизначення методу поповнення балансу
    double getDiscountRate() const;
    double applyDiscount(double price) const;
    void displayInfo() const override; // Перевизначений метод для виводу інформації
};

#endif

