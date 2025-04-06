#include "RentalSystem.h"
#include "Account.h"
#include <iostream>

#include "Motorcycle.h"
#include "Bus.h"
#include "PremiumAccount.h"
#include "Truck.h"

int main() {
    RentalSystem rentalSystem;
    rentalSystem.addAccount(std::make_unique<PremiumAccount>("John", 500.0, 0.1, 0.05));
    rentalSystem.addAccount(std::make_unique<Account>("Alice Smith", 300.0));

    rentalSystem.addVehicle(std::make_unique<Bus>("Toyota", "Camry", 2020, 50.0, 20, true, false ));
    rentalSystem.addVehicle(std::make_unique<Truck>("BMW", "X5", 2022, 100.0,20, 1));

    std::cout << "\n--- Initial Data ---\n";
    rentalSystem.displayAccounts();
    rentalSystem.displayVehicles();

    std::cout << "\n--- Renting a Car ---\n";
    rentalSystem.rentVehicle(1, 1, 3);
    rentalSystem.rentVehicle(2, 1, 3);

    std::cout << "\n--- Rental Orders ---\n";
    rentalSystem.displayOrders();

    std::cout << "\n--- Returning a Car ---\n";
    rentalSystem.returnVehicle(1);

    rentalSystem.rentVehicle(2, 1, 3);
    rentalSystem.rentVehicle(1, 2, 3);
    rentalSystem.returnVehicle(2);
    rentalSystem.accountDeposit(1,200);

    std::cout << "\n--- Final Data ---\n";
    rentalSystem.displayAccounts();
    rentalSystem.displayVehicles();
    rentalSystem.displayOrders();
    return 0;
}
