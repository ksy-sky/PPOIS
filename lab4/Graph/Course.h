#pragma once
#include <iostream>
#include <string>

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
