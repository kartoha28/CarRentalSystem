//
// Created by vladi on 26.02.2025.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "balance.h"
#include <iomanip>
#include <string>

class account {
private:
    std::string username;
    balance accbalance;
public:
    account();
    account::account(std::string newusername);
    account(std::string newusername, balance newaccbalance);
    ~account();

    void deposit(double sum);
    bool withdraw(double sum);
    void editname(std::string newname);
    void showInfo()const;

};



#endif //ACCOUNT_H
