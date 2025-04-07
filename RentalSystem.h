//
// Created by vladi on 09.03.2025.
//

#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include "Account.h"
#include "PremiumAccount.h"
#include "RentalOrder.h"
#include "Vehicle.h"
#include "IDisplayable.h"
#include <vector>
#include <memory>

class RentalSystem final : public IDisplayable{
private:
    std::vector<std::unique_ptr<Account>> accounts; // Вектор унікальних вказівників на акаунти
    std::vector<std::unique_ptr<Vehicle>> vehicles; // Вектор унікальних вказівників на транспортні засоби
    std::vector<RentalOrder> rental_orders;
    int next_order_id;

public:
    RentalSystem();

    void displayInfo() const override;

    // Управління акаунтами
    void addAccount(std::unique_ptr<Account> account);
    void accountDeposit(int account_id, double amount);
    Account* findAccount(int account_id);

    // Управління транспортними засобами
    void addVehicle(std::unique_ptr<Vehicle> vehicle);
    Vehicle* findVehicle(int vehicle_id);

    // Методи оренди
    bool rentVehicle(int account_id, int vehicle_id, int rental_days);
    bool returnVehicle(int order_id);

    // Виведення списків акаунтів, транспортних засобів та ордерів
    void displayAccounts() const;
    void displayVehicles() const;
    void displayOrders() const;
};

#endif // RENTALSYSTEM_H

