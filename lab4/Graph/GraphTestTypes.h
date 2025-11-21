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

class Course {
public:
    std::string title;
    int credits;
    
    Course(const std::string& t = "", int c = 0) : title(t), credits(c) {}
    
    bool operator==(const Course& other) const {
        return title == other.title && credits == other.credits;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Course& c) {
        return os << c.title << " (" << c.credits << " credits)";
    }
};