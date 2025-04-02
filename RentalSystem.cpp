//
// Created by vladi on 09.03.2025.
//

#include "RentalSystem.h"
#include <iostream>
#include <ctime>
#include "Account.h"
#include "PremiumAccount.h"
#include "Car.h"
#include "RentalOrder.h"
#include "Vehicle.h"
#include <vector>
#include <memory>

RentalSystem::RentalSystem() : next_order_id(1) {}

// Додавання акаунта
void RentalSystem::addAccount(std::unique_ptr<Account> account) {
    accounts.push_back(std::move(account));
}

// Поповнення рахунку
void RentalSystem::accountDeposit(int account_id, double amount) {
    accounts[account_id - 1]->deposit(amount);
}

// Пошук акаунта за ID
Account* RentalSystem::findAccount(int account_id) {
    for (auto& account : accounts) {
        if (account->getId() == account_id) {
            return account.get();
        }
    }
    return nullptr;
}

// Додавання транспортного засобу
void RentalSystem::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    vehicles.push_back(std::move(vehicle));
}

// Пошук транспортного засобу за ID
Vehicle* RentalSystem::findVehicle(int vehicle_id) {
    for (auto& vehicle : vehicles) {
        if (vehicle->getId() == vehicle_id) {
            return vehicle.get();
        }
    }
    return nullptr;
}

// Оренда транспортного засобу
bool RentalSystem::rentVehicle(int account_id, int vehicle_id, int rental_days) {
    Account* account = findAccount(account_id);
    Vehicle* vehicle = findVehicle(vehicle_id);

    if (!account) {
        std::cout << "Account not found.\n";
        return false;
    }
    if (!vehicle) {
        std::cout << "Vehicle not found.\n";
        return false;
    }
    if (!vehicle->isAvailable()) {
        std::cout << "Vehicle is not available for rent.\n";
        return false;
    }

    double total_price = vehicle->getRentalPrice() * rental_days;

    // Перевіряємо, чи акаунт є преміумом, і застосовуємо знижку
    if (PremiumAccount* premium = dynamic_cast<PremiumAccount*>(account)) {
        total_price = premium->applyDiscount(total_price);
    }

    if (!(account->withdraw(total_price))) {
        std::cout << "Insufficient balance.\n";
        return false;
    }

    std::time_t now = std::time(nullptr);
    std::time_t end_date = now + (rental_days * 24 * 60 * 60);

    rental_orders.emplace_back(next_order_id, account_id, vehicle_id, now, end_date, total_price);
    account->addRental(vehicle_id);
    vehicle->setStatus(VehicleStatus::Rented);

    std::cout << "Vehicle successfully rented! Order ID: " << next_order_id << "\n";
    next_order_id++;
    return true;
}

// Повернення транспортного засобу
bool RentalSystem::returnVehicle(int order_id) {
    for (auto& order : rental_orders) {
        if (order.getOrderId() == order_id && order.getIsActive()) {
            Vehicle* vehicle = findVehicle(order.getVehicleId());
            if (vehicle) {
                vehicle->setStatus(VehicleStatus::Available);
                order.completeOrder();
                std::cout << "Vehicle returned successfully!\n";
                return true;
            }
        }
    }
    std::cout << "Order not found or already completed.\n";
    return false;
}

// Виведення списків акаунтів, транспортних засобів та ордерів
void RentalSystem::displayAccounts() const {
    for (const auto& account : accounts) {
        account->displayInfo();
    }
}

void RentalSystem::displayVehicles() const {
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
    }
}

void RentalSystem::displayOrders() const {
    for (const auto& order : rental_orders) {
        order.displayInfo();
    }
}


