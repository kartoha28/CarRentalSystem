#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "IDisplayable.h"

class RentalSystem;

class Account : public IDisplayable{
protected:
    static int last_id;
    int id;
    std::string name;
    std::string password;
    double balance;
    std::vector<int> rental_history; // Список ID договорів оренди

public:
    // Конструктори та деструктор
    Account();
    Account(std::string name, std::string password);
    Account(std::string name, std::string password, double balance);
    virtual ~Account();

    Account(const Account& other);
    Account(Account&& other) noexcept;
    Account& operator=(const Account& other);
    Account& operator=(Account&& other) noexcept;

    void setId(int new_id);
    // отримання данних
    int getId() const;
    std::string getName() const;
    std::string getPassword() const;
    double getBalance() const;
    std::vector<int> getRentalHistory() const;
    static int numberOfUser();

    // Методи роботи з балансом
    virtual void deposit(double amount);
    bool withdraw(double amount);

    void addRental(int car_id);//запис про оренду авто

    virtual void displayAccountInfo() const;
    void displayRentalHistory(const RentalSystem& system) const;
    virtual void displayInfo() const;
    friend std::ostream& operator<<(std::ostream& out, const Account& account);
};

#endif // ACCOUNT_H
