//
// Created by vladi on 09.03.2025.
//

#ifndef RENTALORDER_H
#define RENTALORDER_H

#include <string>
#include <ctime>

class RentalOrder {
private:
    int order_id;
    int account_id;
    int vehicle_id;
    std::time_t start_date;
    std::time_t end_date;
    double total_price;
    bool is_active;

public:

    RentalOrder(int order_id, int account_id, int vehicle_id, std::time_t start_date, std::time_t end_date, double total_price);

    // отримання данних
    int getOrderId() const;
    int getAccountId() const;
    int getVehicleId() const;
    std::time_t getStartDate() const;
    std::time_t getEndDate() const;
    double getTotalPrice() const;
    bool getIsActive() const;

    // Методи управління орендами
    void completeOrder(); // Завершує оренду
    void displayInfo() const;
};

#endif // RENTALORDER_H

