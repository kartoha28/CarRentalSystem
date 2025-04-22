//
// Created by vladi on 02.04.2025.
//

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "IDisplayable.h"

enum class VehicleStatus { Available, Rented, Maintenance, Unknown };

std::string to_string(VehicleStatus status);
VehicleStatus from_string(const std::string& status);

class Vehicle : public IDisplayable{
protected:
    static int last_id;
    int id;
    std::string brand;
    std::string model;
    int year;
    double rental_price;
    VehicleStatus status;

public:

    Vehicle(std::string brand, std::string model, int year, double rental_price);

    // отримання данних
    virtual std::string getType() = 0;  // чисто віртуальна функція
    int getId() const;
    std::string getBrand() const;
    std::string getModel() const;
    int getYear() const;
    double getRentalPrice() const;
    VehicleStatus getStatus() const;
    bool isAvailable() const;//чи доступно для оренди

    virtual void setId(int new_id);
    void setStatus(VehicleStatus new_status);//змінити статус авто

    virtual void displayInfo() const;
};



#endif //VEHICLE_H
