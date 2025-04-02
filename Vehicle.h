//
// Created by vladi on 02.04.2025.
//

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

enum class VehicleStatus { Available, Rented, Maintenance };

class Vehicle {
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
    int getId() const;
    std::string getBrand() const;
    std::string getModel() const;
    int getYear() const;
    double getRentalPrice() const;
    VehicleStatus getStatus() const;

    void setStatus(VehicleStatus new_status);//змінити статус авто

    bool isAvailable() const;//чи доступно для оренди
    virtual void displayInfo() const;
};



#endif //VEHICLE_H
