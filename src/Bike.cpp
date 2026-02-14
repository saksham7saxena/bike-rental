#include "Bike.h"

Bike::Bike(int id, std::string make, std::string model, BikeType type, double rate)
    : id(id), make(make), model(model), type(type), rate_per_day(rate), state(BikeState::AVAILABLE) {}

std::string Bike::getTypeString() const {
    return (type == BikeType::STANDARD) ? "STANDARD" : "PREMIUM";
}

std::string Bike::getStateString() const {
    switch (state) {
        case BikeState::AVAILABLE: return "AVAILABLE";
        case BikeState::RENTED: return "RENTED";
        case BikeState::MAINTENANCE: return "MAINTENANCE";
        default: return "UNKNOWN";
    }
}

BikeType Bike::stringToType(const std::string& typeStr) {
    if (typeStr == "PREMIUM") return BikeType::PREMIUM;
    return BikeType::STANDARD;
}

BikeState Bike::stringToState(const std::string& stateStr) {
    if (stateStr == "RENTED") return BikeState::RENTED;
    if (stateStr == "MAINTENANCE") return BikeState::MAINTENANCE;
    return BikeState::AVAILABLE;
}
