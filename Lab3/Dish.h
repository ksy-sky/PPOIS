#pragma once
#include <string>
#include <vector>
#include "NutritionInfo.h"
class Chef; 

class Dish {
public:
    Dish(int uniqueDishId, const std::string& nameOfDish, const std::string& categoryOfDish, double initialPrice,
         bool availabilityStatus, const NutritionInfo& nutritionData, Chef* chefCreator);
    bool isAvailable() const;
    void setAvailability(bool availabilityStatus);
    int getCalories() const;
    void applyDiscount(double discountPercent);
    const std::vector<std::string>& getAllergenTags() const;
    const std::string& getName() const;
    double getPrice() const;
private:
    int dishId;
    std::string dishName;
    std::string dishCategory; 
    double dishPrice;
    bool isCurrentlyAvailable;
    NutritionInfo nutritionInformation;
    std::vector<std::string> allergenTags;
    Chef* createdByChef;
};
