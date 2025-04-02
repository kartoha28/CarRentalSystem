//
// Created by vladi on 02.04.2025.
//

#include "Vehicle.h"
#include <iostream>

int Vehicle::last_id=0;

Vehicle::Vehicle(std::string brand, std::string model, int year, double rental_price): id(++last_id), brand(brand), model(model), year(year), rental_price(rental_price), status(VehicleStatus::Available) {}

// отримання данних
int Vehicle::getId() const {
    return id;
}

std::string Vehicle::getBrand() const {
    return brand;
}

std::string Vehicle::getModel() const {
    return model;
}

int Vehicle::getYear() const {
    return year;
}

double Vehicle::getRentalPrice() const {
    return rental_price;
}

VehicleStatus Vehicle::getStatus() const {
    return status;
}

//змінити статус авто
void Vehicle::setStatus(VehicleStatus new_status) {
    status = new_status;
}

// Перевірка доступності авто
bool Vehicle::isAvailable() const {
    return status == VehicleStatus::Available;
}

// Виведення інформації про автомобіль
void Vehicle::displayInfo() const {
    std::cout << "Brand: " << brand << "\n"
              << "Model: " << model << "\n"
              << "Year: " << year << "\n"
              << "Rental Price per day: $" << rental_price << "\n"
              << "Status: " << (status == VehicleStatus::Available ? "Available" :
                              (status == VehicleStatus::Rented ? "Rented" : "Maintenance"))
              << "\n----------------------\n";
}
