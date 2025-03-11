//
// Created by vladi on 09.03.2025.
//

#ifndef CAR_H
#define CAR_H

#define CAR_H

#include <string>

enum class CarStatus { Available, Rented, Maintenance };

class Car {
private:
    int id;
    std::string brand;
    std::string model;
    int year;
    double rental_price;
    CarStatus status;

public:

    Car(int id, std::string brand, std::string model, int year, double rental_price);

    // отримання данних
    int getId() const;
    std::string getBrand() const;
    std::string getModel() const;
    int getYear() const;
    double getRentalPrice() const;
    CarStatus getStatus() const;

    void setStatus(CarStatus new_status);//змінити статус авто

    bool isAvailable() const;//чи доступно для оренди
    void displayInfo() const;
};



#endif //CAR_H
