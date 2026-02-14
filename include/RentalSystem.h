#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <vector>
#include <string>
#include "Bike.h"
#include "Rider.h"
#include "Rental.h"

class RentalSystem {
private:
    std::vector<Bike> bikes;
    std::vector<Rider> riders;
    std::vector<Rental> rentals;
    
    const std::string bikeFile = "data/bikes.csv";
    const std::string riderFile = "data/riders.csv";
    const std::string rentalFile = "data/rentals.csv";

    int nextBikeId = 1;
    int nextRiderId = 1;
    int nextRentalId = 1;

    void loadBikes();
    void loadRiders();
    void loadRentals();
    
    void saveBikes();
    void saveRiders();
    void saveRentals();

public:
    RentalSystem();
    ~RentalSystem();

    // Bike Management
    void addBike(std::string make, std::string model, BikeType type, double rate);
    void listBikes() const;
    Bike* findBike(int id);

    // Rider Management
    void addRider(std::string name, std::string contact);
    void listRiders() const;
    Rider* findRider(int id);

    // Rental Management
    void rentBike(int bikeId, int riderId);
    void returnBike(int rentalId);
    void listRentals() const;
    void listActiveRentals() const;
    
    // Analytics
    void showAnalytics() const;
};

#endif // RENTALSYSTEM_H
