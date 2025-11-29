#pragma once
#include <iostream>
#include <string>

class City {
public:
    std::string name;
    int population;
    
    City(const std::string& n = "", int p = 0) : name(n), population(p) {}
    bool operator==(const City& other) const {
        return name == other.name && population == other.population;
    }
    friend std::ostream& operator<<(std::ostream& os, const City& c) {
        return os << c.name << "(" << c.population << ")";
    }
};

