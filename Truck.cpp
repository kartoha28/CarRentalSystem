//
// Created by vladi on 07.04.2025.
//

#include "Truck.h"
#include <iostream>

Truck::Truck(std::string brand, std::string model, int year, double rental_price,double max_load_capacity, int axles)
    : Vehicle(brand, model, year, rental_price),
      max_load_capacity(max_load_capacity),
      axles(axles) {}

std::string Truck::getType() {
    return "Truck";
}

double Truck::getMaxLoadCapacity() const {
    return max_load_capacity;
}

int Truck::getAxles() const {
    return axles;
}

void Truck::displayInfo() const {
    std::cout << "Vehicle ID: " << id << "\n" << "Vehicle type: " << "Truck\n";
    Vehicle::displayInfo();
    std::cout << "Max Load Capacity: " << max_load_capacity << " tons\n"
              << "Axles: " << axles << "\n"
              << "----------------------\n";
}
