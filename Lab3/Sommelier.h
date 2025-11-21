#pragma once
#include "Employee.h"
#include <iostream>
#include <string>

class Sommelier : public Employee {
public:
    Sommelier(User* account, double salary, int experience, std::string specialtyRegion);
    void recommendWine(const std::string& dish);
    int getWineRecommendations() const;
    const std::string& getSpecialtyRegion() const;
private:
    int wineRecommendations;
    std::string wineSpecialtyRegion;
};
