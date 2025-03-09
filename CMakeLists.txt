cmake_minimum_required(VERSION 3.29)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 main.cpp
        Account.cpp
        Account.h
        Car.cpp
        Car.h
        RentalOrder.cpp
        RentalOrder.h
        RentalSystem.cpp
        RentalSystem.h)
