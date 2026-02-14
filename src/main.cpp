#include <iostream>
#include <limits>
#include "RentalSystem.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    RentalSystem system;
    int choice;

    while (true) {
        std::cout << "\n=== Bike Rental System ===\n";
        std::cout << "1. Add Bike\n";
        std::cout << "2. List Bikes\n";
        std::cout << "3. Register Rider\n";
        std::cout << "4. List Riders\n";
        std::cout << "5. Rent Bike\n";
        std::cout << "6. Return Bike\n";
        std::cout << "7. View Active Rentals\n";
        std::cout << "8. Show Analytics\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        
        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::string make, model;
                int typeInt;
                double rate;
                
                std::cout << "Enter Make: ";
                std::cin >> make;
                std::cout << "Enter Model: ";
                std::cin >> model;
                std::cout << "Enter Type (0: Standard, 1: Premium): ";
                std::cin >> typeInt;
                std::cout << "Enter Rate per Day: ";
                std::cin >> rate;
                
                system.addBike(make, model, (typeInt == 1 ? BikeType::PREMIUM : BikeType::STANDARD), rate);
                break;
            }
            case 2:
                system.listBikes();
                break;
            case 3: {
                std::string name, contact;
                std::cout << "Enter Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter Contact: ";
                std::cin >> contact;
                
                system.addRider(name, contact);
                break;
            }
            case 4:
                system.listRiders();
                break;
            case 5: {
                int bikeId, riderId;
                std::cout << "Enter Bike ID: ";
                std::cin >> bikeId;
                std::cout << "Enter Rider ID: ";
                std::cin >> riderId;
                
                system.rentBike(bikeId, riderId);
                break;
            }
            case 6: {
                int rentalId;
                std::cout << "Enter Rental ID to return: ";
                std::cin >> rentalId;
                
                system.returnBike(rentalId);
                break;
            }
            case 7:
                system.listActiveRentals();
                break;
            case 8:
                system.showAnalytics();
                break;
            case 0:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
