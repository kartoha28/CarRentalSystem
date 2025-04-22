//
// Created by vladi on 20.04.2025.
//

#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "RentalSystem.h"
#include <string>

class AuthManager {
private:
    RentalSystem& rentalSystem;

public:
    AuthManager(RentalSystem& system);

    Account* loginUser();
    bool loginAdmin();
    void registerUser();
};


#endif //AUTHMANAGER_H
