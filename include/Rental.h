#ifndef RENTAL_H
#define RENTAL_H

#include <string>
#include <ctime>

class Rental {
public:
    int id;
    int bike_id;
    int rider_id;
    long start_date; // Unix timestamp
    long end_date;   // Unix timestamp (0 if active)
    double cost;
    bool is_active;

    Rental(int id, int bike_id, int rider_id, long start_date);
    
    void completeRental(long end_date, double cost);
    int getDurationDays() const;
};

#endif // RENTAL_H
