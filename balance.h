//
// Created by vladi on 26.02.2025.
//

#ifndef BALANCE_H
#define BALANCE_H



class balance {
private:
    double amount;
public:
    balance(double initbalance);
    balance();
    ~balance();
    void deposit(double sum);
    bool withdraw(double sum);
    double getBalance() const;
};



#endif //BALANCE_H
