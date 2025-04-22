//
// Created by vladi on 09.03.2025.
//

#include "RentalSystem.h"
#include <iostream>
#include <ctime>
#include "Account.h"
#include "PremiumAccount.h"
#include "RentalOrder.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorcycle.h"
#include "Truck.h"
#include <vector>
#include <memory>
#include <fstream>

RentalSystem::RentalSystem() : next_order_id(1) {}

void RentalSystem::saveData() const {
    try {
    std::ofstream accOut("accounts.txt");
    if (!accOut.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл accounts.txt для запису.");
    }
    for (const auto& account : accounts) {
        if (const auto* premium = dynamic_cast<PremiumAccount*>(account.get())) {
            accOut << "premium " << premium->getId() << " "
                << premium->getName() << " "
                << premium->getPassword() << " "
                << premium->getBalance() << " "
                << premium->getDiscountRate() << " "
                << premium->getBonusRate() << "\n";
        } else {
            accOut << "regular " << account->getId() << " "
                << account->getName() << " "
                << account->getPassword() << " "
                << account->getBalance() << "\n";
        }
        if (accOut.fail()) {
            throw std::runtime_error("Помилка запису в файл accounts.txt.");
        }
    }
    accOut.close();

    std::ofstream vehicleOut("vehicles.txt");
    if (!vehicleOut.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл vehicles.txt для запису.");
    }
    for (const auto& vehicle : vehicles) {
        if (const auto* car = dynamic_cast<const Car*>(vehicle.get())) {
            vehicleOut << "Car " << car->getId() << " "
                       << car->getBrand() << " "
                       << car->getModel() << " "
                       << car->getYear() << " "
                       << car->getRentalPrice() << " "
                       << to_string(car->getStatus()) << " "
                       << to_string_fuel(car->getFuelType()) << " "
                       << car->getIsAutomatic() << "\n";
        } else if (const auto* bus = dynamic_cast<const Bus*>(vehicle.get())) {
            vehicleOut << "Bus " << bus->getId() << " "
                       << bus->getBrand() << " "
                       << bus->getModel() << " "
                       << bus->getYear() << " "
                       << bus->getRentalPrice() << " "
                       << to_string(bus->getStatus()) << " "
                       << bus->getSeatingCapacity() << " "
                       << bus->hasWiFi() << " "
                       << bus->hasWC() << "\n";
        } else if (const auto* motorcycle = dynamic_cast<const Motorcycle*>(vehicle.get())) {
            vehicleOut << "Motorcycle " << motorcycle->getId() << " "
                       << motorcycle->getBrand() << " "
                       << motorcycle->getModel() << " "
                       << motorcycle->getYear() << " "
                       << motorcycle->getRentalPrice() << " "
                       << to_string(motorcycle->getStatus()) << " "
                       << to_string_motorcycleType(motorcycle->getType()) << " "
                       << motorcycle->getHasSidecar() << "\n";
        } else if (const auto* truck = dynamic_cast<const Truck*>(vehicle.get())) {
            vehicleOut << "Truck " << truck->getId() << " "
                       << truck->getBrand() << " "
                       << truck->getModel() << " "
                       << truck->getYear() << " "
                       << truck->getRentalPrice() << " "
                       << to_string(truck->getStatus()) << " "
                       << truck->getMaxLoadCapacity() << " "
                       << truck->getAxles() << "\n";
        }else {
            throw std::runtime_error("Невідомий тип транспортного засобу.");
        }
        if (vehicleOut.fail()) {
            throw std::runtime_error("Помилка запису в файл vehicles.txt");
        }
    }
    vehicleOut.close();

    std::ofstream orderOut("orders.txt");
        if (!orderOut.is_open()) {
            throw std::runtime_error("Не вдалося відкрити файл orders.txt для запису.");
        }
    for (const auto& order : rental_orders) {
        orderOut << order.getOrderId() << " "
                 << order.getAccountId() << " "
                 << order.getVehicleId() << " "
                 << order.getStartDate() << " "
                 << order.getEndDate() << " "
                 << order.getTotalPrice() << " "
                 << order.getIsActive() << "\n";
        if (orderOut.fail()) {
            throw std::runtime_error("Помилка запису в файл orders.txt.");
        }
    }
    orderOut.close();

    } catch (const std::exception& e) {
        std::cerr << "[Помилка збереження Даних]: " << e.what() << "\n";
    }
}

void RentalSystem::loadData() {
    try{
    std::ifstream accIn("accounts.txt");
    if (!accIn.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл accounts.txt для зчитування.");
    }
    std::string typeacc;
    while (accIn >> typeacc) {
        int id;
        std::string username, password;
        double balance;

        if (typeacc == "premium") {
            double discount, bonus;
            accIn >> id >> username >> password >> balance >> discount >> bonus;
            if (accIn.fail()) {
                throw std::runtime_error("Помилка зчитування полів преміумного акаунта.");
            }
            auto account = std::make_unique<PremiumAccount>(username, password, balance, discount, bonus);
            account->setId(id);
            accounts.push_back(std::move(account));
        } else if (typeacc == "regular") {
            accIn >> id >> username >> password >> balance;
            if (accIn.fail()) {
                throw std::runtime_error("Помилка зчитування полів звичайного акаунта.");
            }
            auto account = std::make_unique<Account>(username, password, balance);
            account->setId(id);
            accounts.push_back(std::move(account));
        }else {
            throw std::runtime_error("Невідомий тип акаунта в файлі: " + typeacc);
        }
    }
    accIn.close();

    std::ifstream vehicleIn("vehicles.txt");
    if (!vehicleIn.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл vehicles.txt для зчитування.");
    }
    std::string typevehicle;
    while (vehicleIn >> typevehicle) {
        if (typevehicle == "Car") {
            int id, year;
            std::string brand, model, status, fuelType;
            double rentalPrice;
            bool isAutomatic;

            vehicleIn >> id >> brand >> model >> year >> rentalPrice >> status >> fuelType >> isAutomatic;
            auto car = std::make_unique<Car>(brand, model, year, rentalPrice, from_string_fuel(fuelType), isAutomatic);
            vehicles.push_back(std::move(car));
            car->setStatus(from_string(status));
            car->setId(id);
        } else if (typevehicle == "Bus") {
            int id, year, seatingCapacity;
            std::string brand, model, status;
            double rentalPrice;
            bool hasWiFi, hasWC;

            vehicleIn >> id >> brand >> model >> year >> rentalPrice >> status >> seatingCapacity >> hasWiFi >> hasWC;
            auto bus = std::make_unique<Bus>(brand, model, year, rentalPrice, seatingCapacity, hasWiFi, hasWC);
            bus->setStatus(from_string(status));
            bus->setId(id);
            vehicles.push_back(std::move(bus));
        } else if (typevehicle == "Motorcycle") {
            int id, year;
            std::string brand, model, status, motorcycleType;
            double rentalPrice;
            bool hasSidecar;

            vehicleIn >> id >> brand >> model >> year >> rentalPrice >> status >> motorcycleType >> hasSidecar;
            auto motorcycle = std::make_unique<Motorcycle>(brand, model, year, rentalPrice, from_string_motorcycleType(motorcycleType), hasSidecar);
            motorcycle->setStatus(from_string(status));
            motorcycle->setId(id);
            vehicles.push_back(std::move(motorcycle));
        } else if (typevehicle == "Truck") {
            int id, year, axles;
            std::string brand, model, status;
            double rentalPrice, maxLoadCapacity;

            vehicleIn >> id >> brand >> model >> year >> rentalPrice >> status >> maxLoadCapacity >> axles;

            auto truck = std::make_unique<Truck>(brand, model, year, rentalPrice,maxLoadCapacity, axles);
            truck->setStatus(from_string(status));
            truck->setId(id);
            vehicles.push_back(std::move(truck));
        } else {
            throw std::runtime_error("Невідомий тип транспортного засобу в файлі.");
        }
        if (vehicleIn.fail()) {
            throw std::runtime_error("Помилка читання полів транспортного засобу.");
        }
    }
    vehicleIn.close();

    std::ifstream orderIn("orders.txt");
    if (!orderIn.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл orders.txt для зчитування.");
    }
    int orderId, accountId, vehicleId;
    std::time_t startTime, endTime;
    double totalPrice;
    bool isActive;

    while (orderIn >> orderId >> accountId >> vehicleId >> startTime >> endTime >> totalPrice >> isActive) {
        if (orderIn.fail()) {
            throw std::runtime_error("Помилка зчитування полів замовлення.");
        }
        RentalOrder order(orderId, accountId, vehicleId, startTime, endTime, totalPrice);
        if (!isActive) {
            order.completeOrder(); // якщо ордер неактивний — позначаємо його завершеним
        }
        rental_orders.push_back(order);
        next_order_id = std::max(next_order_id, orderId + 1);
    }
    orderIn.close();

    } catch (const std::exception& e) {
        std::cerr << "[Помилка завантаження Даних]: " << e.what() << "\n";
    }
}

void RentalSystem::displayInfo() const{
    std::cout << "Rental System Info:\n";
    std::cout << "Accounts: " << accounts.size() << "\n";
    std::cout << "Vehicles: " << vehicles.size() << "\n";
    std::cout << "Orders: " << rental_orders.size() << "\n";
}

//отримання списку акаунтів
const std::vector<std::unique_ptr<Account>>& RentalSystem::getAccounts() const {
    return accounts;
}


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

const RentalOrder* RentalSystem::getOrderById(int id) const {
    for (const auto& order : rental_orders) {
        if (order.getOrderId() == id) {
            return &order;
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
    account->addRental(next_order_id);
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
    for (const auto& vehiclePtr : vehicles) {
        const Vehicle* vehicle = vehiclePtr.get();
        vehicle->displayInfo();
    }
}

void RentalSystem::displayOrders() const {
    for (const auto& order : rental_orders) {
        order.displayInfo();
    }
}