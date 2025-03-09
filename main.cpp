#include "RentalSystem.h"
#include <iostream>

int main() {
    RentalSystem rentalSystem;

    // Додавання акаунтів
    rentalSystem.addAccount(Account(1, "John Doe", 500.0));
    rentalSystem.addAccount(Account(2, "Alice Smith", 300.0));

    // Додавання автомобілів
    rentalSystem.addCar(Car(1, "Toyota", "Camry", 2020, 50.0));
    rentalSystem.addCar(Car(2, "BMW", "X5", 2022, 100.0));

    // Виведення початкового стану
    std::cout << "\n--- Initial Data ---\n";
    rentalSystem.displayAccounts();
    rentalSystem.displayCars();

    // Оренда автомобіля
    std::cout << "\n--- Renting a Car ---\n";
    if (rentalSystem.rentCar(1, 1, 3)) { // John Doe орендує Toyota Camry на 3 дні
        std::cout << "Car rented successfully!\n";
    }

    // Виведення ордерів
    std::cout << "\n--- Rental Orders ---\n";
    rentalSystem.displayOrders();

    // Спроба повернути авто
    std::cout << "\n--- Returning a Car ---\n";
    rentalSystem.returnCar(1);

    // Виведення фінального стану
    std::cout << "\n--- Final Data ---\n";
    rentalSystem.displayAccounts();
    rentalSystem.displayCars();
    rentalSystem.displayOrders();

    return 0;
}
