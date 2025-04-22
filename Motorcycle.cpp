//
// Created by vladi on 02.04.2025.
//

#include "Motorcycle.h"
#include <iostream>

std::string to_string_motorcycleType(MotorcycleType type) {
    switch (type) {
        case MotorcycleType::Cruiser: return "Cruiser";
        case MotorcycleType::Sport: return "Sport";
        case MotorcycleType::Touring: return "Touring";
        case MotorcycleType::Standard: return "Standard";
        case MotorcycleType::OffRoad: return "OffRoad";
        default: return "Unknown";
    }
}

MotorcycleType from_string_motorcycleType(const std::string& type) {
    if (type == "Cruiser") return MotorcycleType::Cruiser;
    if (type == "Sport") return MotorcycleType::Sport;
    if (type == "Touring") return MotorcycleType::Touring;
    if (type == "Standard") return MotorcycleType::Standard;
    if (type == "OffRoad") return MotorcycleType::OffRoad;
    else return MotorcycleType::Unknown;
}

Motorcycle::Motorcycle(std::string brand, std::string model, int year, double rental_price, MotorcycleType type, bool has_sidecar)
    : Vehicle(brand, model, year, rental_price), type(type), has_sidecar(has_sidecar) {}

std::string Motorcycle::getType() {
    return "Motorcycle";
}

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
