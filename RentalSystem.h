//
// Created by vladi on 09.03.2025.
//

#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include "Account.h"
#include "PremiumAccount.h"
#include "Car.h"
#include "RentalOrder.h"
#include <vector>
#include <memory>

class RentalSystem {
private:
    std::vector<std::unique_ptr<Account>> accounts; // Вектор вказівників на акаунти
    std::vector<Car> cars;
    std::vector<RentalOrder> rental_orders;
    int next_order_id;

public:
    RentalSystem();

    //управління акаунтами
    void addAccount(std::unique_ptr<Account> account);
    void accountDeposit(int account_id, double amount);
    Account* findAccount(int account_id);

    //управління автомобілями
    void addCar(const Car& car);
    Car* findCar(int car_id);

    // Методи оренди
    bool rentCar(int account_id, int car_id, int rental_days);
    bool returnCar(int order_id);

    // Виведення списків акаунтів, машин та ордерів
    void displayAccounts() const;
    void displayCars() const;
    void displayOrders() const;
};

#endif // RENTALSYSTEM_H

