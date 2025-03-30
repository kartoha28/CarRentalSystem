#include "RentalSystem.h"
#include "Account.h"
#include <iostream>

#include "PremiumAccount.h"

int main() {
    RentalSystem rentalSystem;
    rentalSystem.addAccount(std::make_unique<PremiumAccount>("John", 500.0, 0.1, 0.05));
    rentalSystem.addAccount(std::make_unique<Account>("Alice Smith", 300.0));

    rentalSystem.addCar(Car("Toyota", "Camry", 2020, 50.0));
    rentalSystem.addCar(Car("BMW", "X5", 2022, 100.0));

    std::cout << "\n--- Initial Data ---\n";
    rentalSystem.displayAccounts();
    rentalSystem.displayCars();

    std::cout << "\n--- Renting a Car ---\n";
    rentalSystem.rentCar(1, 1, 3);

    std::cout << "\n--- Rental Orders ---\n";
    rentalSystem.displayOrders();

    std::cout << "\n--- Returning a Car ---\n";
    rentalSystem.returnCar(1);

    //rentalSystem.accountDeposit(1,200);

    std::cout << "\n--- Final Data ---\n";
    rentalSystem.displayAccounts();
    rentalSystem.displayCars();
    rentalSystem.displayOrders();
    return 0;
}
