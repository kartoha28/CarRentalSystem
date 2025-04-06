//
// Created by vladi on 07.04.2025.
//

#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double max_load_capacity; // у тоннах
    int axles;                // кількість осей

public:
    Truck(std::string brand, std::string model, int year, double rental_price,
          double max_load_capacity, int axles);

    double getMaxLoadCapacity() const;
    int getAxles() const;

    void displayInfo() const override;
};

#endif // TRUCK_H
