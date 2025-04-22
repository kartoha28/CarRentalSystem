//
// Created by vladi on 02.04.2025.
//

#include "Vehicle.h"
#include <iostream>

int Vehicle::last_id=0;

std::string to_string(VehicleStatus status) {
    switch (status) {
        case VehicleStatus::Available: return "Available";
        case VehicleStatus::Rented: return "Rented";
        case VehicleStatus::Maintenance: return "UnderMaintenance";
        default: return "Unknown";
    }
}

VehicleStatus from_string(const std::string& status) {
    if (status == "Available") return VehicleStatus::Available;
    if (status == "Rented") return VehicleStatus::Rented;
    if (status == "UnderMaintenance") return VehicleStatus::Maintenance;
    else return VehicleStatus::Unknown;
}

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

void Vehicle::setId(int new_id) {
    id = new_id;
    last_id = new_id;
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
