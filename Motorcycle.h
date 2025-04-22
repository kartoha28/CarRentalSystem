//
// Created by vladi on 02.04.2025.
//

#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "Vehicle.h"

enum class MotorcycleType {
    Cruiser,
    Sport,
    Touring,
    Standard,
    OffRoad,
    Unknown
};

std::string to_string_motorcycleType(MotorcycleType type);
MotorcycleType from_string_motorcycleType(const std::string& type);

class Motorcycle : public Vehicle {
private:
    MotorcycleType type;
    bool has_sidecar;

public:
    Motorcycle(std::string brand, std::string model, int year, double rental_price, MotorcycleType type, bool has_sidecar);

    std::string getType() override;
    MotorcycleType getType() const;
    bool getHasSidecar() const;
    void displayInfo() const;
};



#endif //MOTORCYCLE_H
