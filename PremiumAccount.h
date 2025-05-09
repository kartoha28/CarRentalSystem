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
    PremiumAccount(std::string name,std::string password, double balance, double discount = 0.1, double bonus = 0.05);
    PremiumAccount(const PremiumAccount& other);
    PremiumAccount(PremiumAccount&& other) noexcept;
    PremiumAccount(const Account& other);
    PremiumAccount& operator=(const PremiumAccount& other);
    PremiumAccount& operator=(PremiumAccount&& other) noexcept;

    void deposit(double amount) final; // Перевизначення методу поповнення балансу
    double getDiscountRate() const;
    double getBonusRate() const;
    double applyDiscount(double price) const;
    void displayAccountInfo() const override;
    void displayInfo() const override; // Перевизначений метод для виводу інформації
};

#endif

