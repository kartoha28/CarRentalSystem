//
// Created by vladi on 09.03.2025.
//

#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include "Account.h"
#include "Car.h"
#include "RentalOrder.h"
#include <vector>

class RentalSystem {
private:
    std::vector<Account> accounts;
    std::vector<Car> cars;
    std::vector<RentalOrder> rental_orders;
    int next_order_id;

public:
    RentalSystem();

    //управління акаунтами
    void addAccount(const Account& account);
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

