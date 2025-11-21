#pragma once
#include <iostream>
#include <string>

class Smartphone {
public:
    std::string brand;
    std::string model;
    int releaseYear;
    double screenSize;
    int storageGB;
    
    Smartphone(const std::string& b = "", const std::string& m = "", int y = 0, 
               double s = 0.0, int st = 0)
        : brand(b), model(m), releaseYear(y), screenSize(s), storageGB(st) {}
    
    bool operator<(const Smartphone& other) const { 
        return releaseYear < other.releaseYear; 
    }
    bool operator==(const Smartphone& other) const {
        return brand == other.brand && model == other.model && 
               releaseYear == other.releaseYear && screenSize == other.screenSize &&
               storageGB == other.storageGB;
    }
};