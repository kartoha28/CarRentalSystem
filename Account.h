#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
private:
    int id;
    std::string name;
    double balance;
    std::vector<int> rental_history; // Список ID орендованих авто

public:
    // Конструктори та деструктор
    Account(int id);
    Account(int id, std::string name);
    Account(int id, std::string name, double balance);
    ~Account();

    // отримання данних
    int getId() const;
    std::string getName() const;
    double getBalance() const;
    std::vector<int> getRentalHistory() const;

    // Методи роботи з балансом
    void deposit(double amount);
    bool withdraw(double amount);

    void addRental(int car_id);

    void displayInfo() const;
};

#endif // ACCOUNT_H
