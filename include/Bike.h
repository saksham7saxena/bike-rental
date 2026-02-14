#ifndef BIKE_H
#define BIKE_H

#include <string>
#include <iostream>

enum class BikeType {
    STANDARD,
    PREMIUM
};

enum class BikeState {
    AVAILABLE,
    RENTED,
    MAINTENANCE
};

class Bike {
public:
    int id;
    std::string make;
    std::string model;
    BikeType type;
    BikeState state;
    double rate_per_day;

    Bike(int id, std::string make, std::string model, BikeType type, double rate);

    std::string getTypeString() const;
    std::string getStateString() const;
    
    // Helper to parse strings back to enums for CSV loading
    static BikeType stringToType(const std::string& typeStr);
    static BikeState stringToState(const std::string& stateStr);
};

#endif // BIKE_H
