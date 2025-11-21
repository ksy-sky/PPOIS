#pragma once
#include <string>
#include "NutritionInfo.h"
class Chef;

class Dessert {
public:
    Dessert(int uniqueDessertId, const std::string& nameOfDessert, int sweetnessScale,
         const NutritionInfo& nutritionData, double initialPrice, Chef* chefCreator);
    std::string describeDessert() const;
    bool isSugarFree() const;
    double calculateCaloriesPerGram(double weightInGrams) const;
    const std::string& getName() const;
    double getPrice() const;
private:
    int dessertId;
    std::string dessertName;
    int sweetnessLevel; 
    NutritionInfo nutritionInformation;
    double dessertPrice;
    Chef* createdByChef;
};
