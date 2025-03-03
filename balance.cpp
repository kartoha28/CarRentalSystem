//
// Created by vladi on 26.02.2025.
//

#include "balance.h"

#include <iostream>
#include <ostream>

balance::balance(double initbalance): amount(initbalance) {}
balance::balance(): amount(0.0) {}
balance::~balance() {
    std::cout << "Destructor balance" << "\n";
}


void balance::deposit(double sum) {
    amount += sum;
}

bool balance::withdraw(double sum) {
    if(amount < sum) return false;
    amount -= sum;
    return true;
}

double balance::getBalance() const {
    return amount;
}
