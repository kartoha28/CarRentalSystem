//
// Created by vladi on 02.04.2025.
//

#include "Motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle(std::string brand, std::string model, int year, double rental_price, MotorcycleType type, bool has_sidecar)
    : Vehicle(brand, model, year, rental_price), type(type), has_sidecar(has_sidecar) {}

MotorcycleType Motorcycle::getType() const {
    return type;
}

bool Motorcycle::getHasSidecar() const {
    return has_sidecar;
}

void Motorcycle::displayInfo() const {
    std::cout << "Vehicle ID: " << id << "\n" << "Vehicle type: " << "Motorcycle\n";
    Vehicle::displayInfo();
    std::cout << "Motorcycle Type: ";

    switch (type) {
        case MotorcycleType::Cruiser:  std::cout << "Cruiser"; break;
        case MotorcycleType::Sport:    std::cout << "Sport"; break;
        case MotorcycleType::Touring:  std::cout << "Touring"; break;
        case MotorcycleType::Standard: std::cout << "Standard"; break;
        case MotorcycleType::OffRoad:  std::cout << "Off-Road"; break;
    }

    std::cout << "\nHas Sidecar: " << (has_sidecar ? "Yes" : "No") << "\n"
              << "----------------------\n";
}
