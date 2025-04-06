//
// Created by vladi on 06.04.2025.
//

#include "Bus.h"
#include <iostream>

Bus::Bus(std::string brand, std::string model, int year, double rental_price,int seating_capacity, bool has_wifi, bool has_wc)
    : Vehicle(brand, model, year, rental_price),
      seating_capacity(seating_capacity),
      has_wifi(has_wifi),
      has_wc(has_wc) {}

int Bus::getSeatingCapacity() const {
    return seating_capacity;
}

bool Bus::hasWiFi() const {
    return has_wifi;
}

bool Bus::hasWC() const {
    return has_wc;
}

void Bus::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Seating Capacity: " << seating_capacity << "\n"
              << "Wi-Fi: " << (has_wifi ? "Yes" : "No") << "\n"
              << "Toilet: " << (has_wc ? "Yes" : "No") << "\n"
              << "----------------------\n";
}
