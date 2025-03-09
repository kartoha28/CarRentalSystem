//
// Created by vladi on 09.03.2025.
//

#include "RentalSystem.h"
#include <iostream>
#include <ctime>

// Конструктор
RentalSystem::RentalSystem() : next_order_id(1) {}

// Додавання акаунта
void RentalSystem::addAccount(const Account& account) {
    accounts.push_back(account);
}

// Пошук акаунта за ID
Account* RentalSystem::findAccount(int account_id) {
    for (auto& account : accounts) {
        if (account.getId() == account_id) {
            return &account;
        }
    }
    return nullptr;
}

// Додавання автомобіля
void RentalSystem::addCar(const Car& car) {
    cars.push_back(car);
}

// Пошук автомобіля за ID
Car* RentalSystem::findCar(int car_id) {
    for (auto& car : cars) {
        if (car.getId() == car_id) {
            return &car;
        }
    }
    return nullptr;
}

// Оренда автомобіля
bool RentalSystem::rentCar(int account_id, int car_id, int rental_days) {
    Account* account = findAccount(account_id);
    Car* car = findCar(car_id);

    if (!account) {
        std::cout << "Account not found.\n";
        return false;
    }
    if (!car) {
        std::cout << "Car not found.\n";
        return false;
    }
    if (!car->isAvailable()) {
        std::cout << "Car is not available for rent.\n";
        return false;
    }

    double total_price = car->getRentalPrice() * rental_days;
    if (!account->withdraw(total_price)) {
        std::cout << "Insufficient balance.\n";
        return false;
    }

    std::time_t now = std::time(nullptr);
    std::time_t end_date = now + (rental_days * 24 * 60 * 60);

    rental_orders.emplace_back(next_order_id, account_id, car_id, now, end_date, total_price);
    account->addRental(car_id);
    car->setStatus(CarStatus::Rented);

    std::cout << "Car successfully rented! Order ID: " << next_order_id << "\n";
    next_order_id++;
    return true;
}

// Повернення автомобіля
bool RentalSystem::returnCar(int order_id) {
    for (auto& order : rental_orders) {
        if (order.getOrderId() == order_id && order.getIsActive()) {
            Car* car = findCar(order.getCarId());
            if (car) {
                car->setStatus(CarStatus::Available);
                order.completeOrder();
                std::cout << "Car returned successfully!\n";
                return true;
            }
        }
    }
    std::cout << "Order not found or already completed.\n";
    return false;
}

// Виведення акаунтів
void RentalSystem::displayAccounts() const {
    for (const auto& account : accounts) {
        account.displayInfo();
    }
}

// Виведення автомобілів
void RentalSystem::displayCars() const {
    for (const auto& car : cars) {
        car.displayInfo();
    }
}

// Виведення ордерів
void RentalSystem::displayOrders() const {
    for (const auto& order : rental_orders) {
        order.displayInfo();
    }
}

