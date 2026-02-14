#include "Rental.h"
#include <cmath>

Rental::Rental(int id, int bike_id, int rider_id, long start_date)
    : id(id), bike_id(bike_id), rider_id(rider_id), start_date(start_date), end_date(0), cost(0.0), is_active(true) {}

void Rental::completeRental(long end_time, double calculated_cost) {
    end_date = end_time;
    cost = calculated_cost;
    is_active = false;
}

int Rental::getDurationDays() const {
    if (is_active) {
        // Calculate duration from start to now (for status display)
        long now = std::time(nullptr);
        double seconds = std::difftime(now, start_date);
        return static_cast<int>(std::ceil(seconds / (60 * 60 * 24)));
    } else {
        double seconds = std::difftime(end_date, start_date);
        return static_cast<int>(std::ceil(seconds / (60 * 60 * 24)));
    }
}
