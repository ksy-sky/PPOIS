#pragma once
#include <iostream>
#include <string>

class Car {
public:
    std::string brand;
    std::string model;
    int year;
    double engine_size;
    Car(const std::string& b = "", const std::string& m = "", int y = 0, double e = 0.0)
        : brand(b), model(m), year(y), engine_size(e) {}
    
    bool operator<(const Car& other) const {
        return year < other.year;  
    }
    bool operator==(const Car& other) const {
        return brand == other.brand && model == other.model && 
               year == other.year && engine_size == other.engine_size;
    }
};