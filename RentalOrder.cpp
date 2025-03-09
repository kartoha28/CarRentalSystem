//
// Created by vladi on 09.03.2025.
//

#include "RentalOrder.h"
#include <iostream>
#include <iomanip>
#include <ctime>

// Конструктор
RentalOrder::RentalOrder(int order_id, int account_id, int car_id, std::time_t start_date, std::time_t end_date, double total_price)
    : order_id(order_id), account_id(account_id), car_id(car_id), start_date(start_date), end_date(end_date), total_price(total_price), is_active(true) {}

// отримання данних
int RentalOrder::getOrderId() const {
    return order_id;
}

int RentalOrder::getAccountId() const {
    return account_id;
}

int RentalOrder::getCarId() const {
    return car_id;
}

std::time_t RentalOrder::getStartDate() const {
    return start_date;
}

std::time_t RentalOrder::getEndDate() const {
    return end_date;
}

double RentalOrder::getTotalPrice() const {
    return total_price;
}

bool RentalOrder::getIsActive() const {
    return is_active;
}

// Завершення оренди
void RentalOrder::completeOrder() {
    if (is_active) {
        is_active = false;
        std::cout << "Rental order #" << order_id << " has been completed.\n";
    } else {
        std::cout << "Rental order #" << order_id << " is already completed.\n";
    }
}

// Виведення інформації
void RentalOrder::displayInfo() const {
    std::cout << "Order ID: " << order_id << "\n"
              << "Account ID: " << account_id << "\n"
              << "Car ID: " << car_id << "\n"
              << "Start Date: " << std::ctime(&start_date)
              << "End Date: " << std::ctime(&end_date)
              << "Total Price: $" << total_price << "\n"
              << "Status: " << (is_active ? "Active" : "Completed") << "\n"
              << "----------------------\n";
}

