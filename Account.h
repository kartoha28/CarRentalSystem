#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
protected:
    static int last_id;
    int id;
    std::string name;
    double balance;
    std::vector<int> rental_history; // Список ID орендованих авто

public:
    // Конструктори та деструктор
    Account();
    Account(std::string name);
    Account(std::string name, double balance);
    ~Account();

    Account(const Account& other);
    Account(Account&& other) noexcept;
    Account& operator=(const Account& other);
    Account& operator=(Account&& other) noexcept;

    // отримання данних
    int getId() const;
    std::string getName() const;
    double getBalance() const;
    std::vector<int> getRentalHistory() const;
    static int numberOfUser();

    // Методи роботи з балансом
    virtual void deposit(double amount);
    bool withdraw(double amount);

    void addRental(int car_id);//запис про оренду авто

    virtual void displayInfo() const;
    friend std::ostream& operator<<(std::ostream& out, const Account& account);
};

#endif // ACCOUNT_H
