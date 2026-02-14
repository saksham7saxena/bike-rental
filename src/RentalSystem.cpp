#include "RentalSystem.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

RentalSystem::RentalSystem() {
    loadBikes();
    loadRiders();
    loadRentals();
    
    // Initialize IDs
    if (!bikes.empty()) nextBikeId = bikes.back().id + 1;
    if (!riders.empty()) nextRiderId = riders.back().id + 1;
    if (!rentals.empty()) nextRentalId = rentals.back().id + 1;
}

RentalSystem::~RentalSystem() {
    saveBikes();
    saveRiders();
    saveRentals();
}

// --- Persistence ---

void RentalSystem::loadBikes() {
    std::ifstream file(bikeFile);
    if (!file.is_open()) return;
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        auto tokens = Utils::split(line, ',');
        if (tokens.size() >= 5) {
            int id = std::stoi(tokens[0]);
            std::string make = tokens[1];
            std::string model = tokens[2];
            BikeType type = Bike::stringToType(tokens[3]);
            double rate = std::stod(tokens[4]);
            BikeState state = Bike::stringToState(tokens[5]);
            
            Bike b(id, make, model, type, rate);
            b.state = state;
            bikes.push_back(b);
        }
    }
}

void RentalSystem::saveBikes() {
    std::ofstream file(bikeFile);
    for (const auto& b : bikes) {
        file << b.id << "," << b.make << "," << b.model << "," 
             << b.getTypeString() << "," << b.rate_per_day << "," 
             << b.getStateString() << "\n";
    }
}

void RentalSystem::loadRiders() {
    std::ifstream file(riderFile);
    if (!file.is_open()) return;
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        auto tokens = Utils::split(line, ',');
        if (tokens.size() >= 3) {
            int id = std::stoi(tokens[0]);
            std::string name = tokens[1];
            std::string contact = tokens[2];
            riders.emplace_back(id, name, contact);
        }
    }
}

void RentalSystem::saveRiders() {
    std::ofstream file(riderFile);
    for (const auto& r : riders) {
        file << r.id << "," << r.name << "," << r.contact << "\n";
    }
}

void RentalSystem::loadRentals() {
    std::ifstream file(rentalFile);
    if (!file.is_open()) return;
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        auto tokens = Utils::split(line, ',');
        if (tokens.size() >= 7) {
            int id = std::stoi(tokens[0]);
            int bikeId = std::stoi(tokens[1]);
            int riderId = std::stoi(tokens[2]);
            long start = std::stol(tokens[3]);
            long end = std::stol(tokens[4]);
            double cost = std::stod(tokens[5]);
            bool active = (tokens[6] == "1");

            Rental r(id, bikeId, riderId, start);
            r.end_date = end;
            r.cost = cost;
            r.is_active = active;
            rentals.push_back(r);
        }
    }
}

void RentalSystem::saveRentals() {
    std::ofstream file(rentalFile);
    for (const auto& r : rentals) {
        file << r.id << "," << r.bike_id << "," << r.rider_id << "," 
             << r.start_date << "," << r.end_date << "," 
             << r.cost << "," << (r.is_active ? "1" : "0") << "\n";
    }
}

// --- Logic ---

void RentalSystem::addBike(std::string make, std::string model, BikeType type, double rate) {
    bikes.emplace_back(nextBikeId++, make, model, type, rate);
    std::cout << "Bike added successfully. ID: " << nextBikeId - 1 << "\n";
    saveBikes();
}

void RentalSystem::listBikes() const {
    std::cout << "\n--- Available Bikes ---\n";
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(15) << "Make" 
              << std::setw(15) << "Model" 
              << std::setw(10) << "Type" 
              << std::setw(10) << "Rate" 
              << "State" << "\n";
    
    for (const auto& b : bikes) {
        std::cout << std::left << std::setw(5) << b.id 
                  << std::setw(15) << b.make 
                  << std::setw(15) << b.model 
                  << std::setw(10) << b.getTypeString() 
                  << std::setw(10) << b.rate_per_day 
                  << b.getStateString() << "\n";
    }
}

Bike* RentalSystem::findBike(int id) {
    for (auto& b : bikes) {
        if (b.id == id) return &b;
    }
    return nullptr;
}

void RentalSystem::addRider(std::string name, std::string contact) {
    riders.emplace_back(nextRiderId++, name, contact);
    std::cout << "Rider registered successfully. ID: " << nextRiderId - 1 << "\n";
    saveRiders();
}

void RentalSystem::listRiders() const {
    std::cout << "\n--- Rider List ---\n";
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(20) << "Name" 
              << "Contact" << "\n";
    
    for (const auto& r : riders) {
        std::cout << std::left << std::setw(5) << r.id 
                  << std::setw(20) << r.name 
                  << r.contact << "\n";
    }
}

Rider* RentalSystem::findRider(int id) {
    for (auto& r : riders) {
        if (r.id == id) return &r;
    }
    return nullptr;
}

void RentalSystem::rentBike(int bikeId, int riderId) {
    Bike* bike = findBike(bikeId);
    Rider* rider = findRider(riderId);

    if (!bike) {
        std::cout << "Error: Bike ID not found.\n";
        return;
    }
    if (!rider) {
        std::cout << "Error: Rider ID not found.\n";
        return;
    }
    if (bike->state != BikeState::AVAILABLE) {
        std::cout << "Error: Bike is not available (Current state: " << bike->getStateString() << ").\n";
        return;
    }

    // Check if rider already has an active rental
    for (const auto& r : rentals) {
        if (r.rider_id == riderId && r.is_active) {
            std::cout << "Error: Rider already has an active rental.\n";
            return;
        }
    }

    bike->state = BikeState::RENTED;
    rentals.emplace_back(nextRentalId++, bikeId, riderId, Utils::getCurrentTimestamp());
    
    std::cout << "Bike rented successfully to " << rider->name << ".\n";
    saveBikes();
    saveRentals();
}

void RentalSystem::returnBike(int rentalId) {
    Rental* rental = nullptr;
    for (auto& r : rentals) {
        if (r.id == rentalId) {
            rental = &r;
            break;
        }
    }

    if (!rental) {
        std::cout << "Error: Rental ID not found.\n";
        return;
    }
    if (!rental->is_active) {
        std::cout << "Error: Rental is already completed.\n";
        return;
    }

    Bike* bike = findBike(rental->bike_id);
    if (!bike) {
        std::cout << "Error: Bike data consistency error.\n";
        return;
    }

    long now = Utils::getCurrentTimestamp();
    double seconds = std::difftime(now, rental->start_date);
    int days = static_cast<int>(std::ceil(seconds / (60 * 60 * 24)));
    if (days == 0) days = 1; // Minimum 1 day charge

    double totalCost = days * bike->rate_per_day;
    
    // Late penalty logic (simplified: if > 7 days, 20% surcharge)
    if (days > 7) {
        totalCost *= 1.20; 
        std::cout << "Notice: Rental exceeded 7 days. Late penalty applied.\n";
    }

    rental->completeRental(now, totalCost);
    bike->state = BikeState::AVAILABLE;

    std::cout << "Bike returned successfully.\n";
    std::cout << "Total Days: " << days << "\n";
    std::cout << "Total Cost: $" << totalCost << "\n";
    
    saveBikes();
    saveRentals();
}

void RentalSystem::listRentals() const {
    std::cout << "\n--- All Rentals ---\n";
    // ... logic to list all ...
}

void RentalSystem::listActiveRentals() const {
    std::cout << "\n--- Active Rentals ---\n";
    std::cout << std::left << std::setw(10) << "RentalID" 
              << std::setw(10) << "BikeID" 
              << std::setw(10) << "RiderID" 
              << "Start Date" << "\n";
    
    for (const auto& r : rentals) {
        if (r.is_active) {
            std::cout << std::left << std::setw(10) << r.id 
                      << std::setw(10) << r.bike_id 
                      << std::setw(10) << r.rider_id 
                      << r.start_date << "\n"; // Date formatting can be improved
        }
    }
}

void RentalSystem::showAnalytics() const {
    double totalRevenue = 0;
    int activeCount = 0;
    int completedCount = 0;

    for (const auto& r : rentals) {
        if (r.is_active) {
            activeCount++;
        } else {
            completedCount++;
            totalRevenue += r.cost;
        }
    }

    std::cout << "\n--- Analytics ---\n";
    std::cout << "Total Revenue: $" << totalRevenue << "\n";
    std::cout << "Active Rentals: " << activeCount << "\n";
    std::cout << "Completed Rentals: " << completedCount << "\n";
}
