//
// Created by vladi on 09.03.2025.
//

#include "Car.h"
#include <iostream>

int Car::last_id=0;

Car::Car(std::string brand, std::string model, int year, double rental_price): id(++last_id), brand(brand), model(model), year(year), rental_price(rental_price), status(CarStatus::Available) {}

// отримання данних
int Car::getId() const {
    return id;
}

std::string Car::getBrand() const {
    return brand;
}

std::string Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

double Car::getRentalPrice() const {
    return rental_price;
}

CarStatus Car::getStatus() const {
    return status;
}

//змінити статус авто
void Car::setStatus(CarStatus new_status) {
    status = new_status;
}

// Перевірка доступності авто
bool Car::isAvailable() const {
    return status == CarStatus::Available;
}

// Виведення інформації про автомобіль
void Car::displayInfo() const {
    std::cout << "Car ID: " << id << "\n"
              << "Brand: " << brand << "\n"
              << "Model: " << model << "\n"
              << "Year: " << year << "\n"
              << "Rental Price per day: $" << rental_price << "\n"
              << "Status: " << (status == CarStatus::Available ? "Available" :
                              (status == CarStatus::Rented ? "Rented" : "Maintenance"))
              << "\n----------------------\n";
}

