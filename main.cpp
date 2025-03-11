#include "RentalSystem.h"
#include "Account.h"
#include <iostream>

int main() {
    RentalSystem rentalSystem;

    rentalSystem.addAccount(Account("John Doe", 500.0));
    rentalSystem.addAccount(Account("Alice Smith", 300.0));

    rentalSystem.addCar(Car(1, "Toyota", "Camry", 2020, 50.0));
    rentalSystem.addCar(Car(2, "BMW", "X5", 2022, 100.0));

    std::cout << "\n--- Initial Data ---\n";
    rentalSystem.displayAccounts();
    rentalSystem.displayCars();

    std::cout << "\n--- Renting a Car ---\n";
    if (rentalSystem.rentCar(1, 1, 3)) {
        std::cout << "Car rented successfully!\n";
    }

    std::cout << "\n--- Rental Orders ---\n";
    rentalSystem.displayOrders();

    std::cout << "\n--- Returning a Car ---\n";
    rentalSystem.returnCar(1);

    std::cout << "\n--- Final Data ---\n";
    rentalSystem.displayAccounts();
    rentalSystem.displayCars();
    rentalSystem.displayOrders();
    return 0;
}
