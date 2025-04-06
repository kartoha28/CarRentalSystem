//
// Created by vladi on 06.04.2025.
//

#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"
#include <string>

class Bus : public Vehicle {
private:
    int seating_capacity;
    bool has_wifi;
    bool has_wc;

public:
    Bus(std::string brand, std::string model, int year, double rental_price,
        int seating_capacity, bool has_wifi, bool has_wc);

    std::string getType() override;
    int getSeatingCapacity() const;
    bool hasWiFi() const;
    bool hasWC() const;

    void displayInfo() const override;
};

#endif // BUS_H
