//
// Created by vladi on 09.03.2025.
//

#include "Car.h"
#include <iostream>

std::string to_string_fuel(FuelType fuelType) {
    switch (fuelType) {
        case FuelType::Petrol: return "Petrol";
        case FuelType::Diesel: return "Diesel";
        case FuelType::Electric: return "Electric";
        case FuelType::Hybrid: return "Hybrid";
        default: return "Unknown";
    }
}

FuelType from_string_fuel(const std::string& fuelType) {
    if (fuelType == "Petrol") return FuelType::Petrol;
    if (fuelType == "Diesel") return FuelType::Diesel;
    if (fuelType == "Electric") return FuelType::Electric;
    if (fuelType == "Hybrid") return FuelType::Hybrid;
    else return FuelType::Unknown;
}

Car::Car(std::string brand, std::string model, int year, double rental_price, FuelType fuel_type, bool is_automatic)
    : Vehicle(brand, model, year, rental_price), fuel_type(fuel_type), is_automatic(is_automatic) {}

std::string Car::getType() {
    return "Car";
}


FuelType Car::getFuelType() const {
    return fuel_type;
}

bool Car::getIsAutomatic() const {
    return is_automatic;
}

void Car::displayInfo() const {
    std::cout << "Vehicle ID: " << id << "\n" << "Vehicle type: " << "Car\n";
    Vehicle::displayInfo();
    std::cout << "Fuel Type: ";

    switch (fuel_type) {
        case FuelType::Petrol:   std::cout << "Petrol"; break;
        case FuelType::Diesel:   std::cout << "Diesel"; break;
        case FuelType::Electric: std::cout << "Electric"; break;
        case FuelType::Hybrid:   std::cout << "Hybrid"; break;
    }

    std::cout << "\nTransmission: " << (is_automatic ? "Automatic" : "Manual") << "\n"
              << "----------------------\n";
}

