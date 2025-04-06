//
// Created by vladi on 09.03.2025.
//

#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>

enum class FuelType {
    Petrol,
    Diesel,
    Electric,
    Hybrid
};

class Car : public Vehicle {
private:
    FuelType fuel_type;
    bool is_automatic;

public:
    Car(std::string brand, std::string model, int year, double rental_price, FuelType fuel_type, bool is_automatic);

    std::string getType() override;
    FuelType getFuelType() const;
    bool getIsAutomatic() const;
    void displayInfo() const;
};



#endif //CAR_H
