//
// Created by vladi on 26.02.2025.
//

#include "account.h"

#include <iostream>
#include <string>

account::account(): account("None", 0.0) {}
account::account(std::string newusername): username(newusername, 0.0) {}
account::account(std::string newusername, balance newaccbalance): username(newusername), accbalance(newaccbalance) {}

void account::deposit(double sum) {
    accbalance.deposit(sum);
}

bool account::withdraw(double sum) {
    return accbalance.withdraw(sum);
}

void account::showInfo() const {
    std::cout << "username: " << username << "\n";
    std::cout<< "balance: " << accbalance.getBalance() << "\n";
}




