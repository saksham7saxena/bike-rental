#ifndef RIDER_H
#define RIDER_H

#include <string>

class Rider {
public:
    int id;
    std::string name;
    std::string contact;

    Rider(int id, std::string name, std::string contact);
};

#endif // RIDER_H
