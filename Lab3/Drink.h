#pragma once
#include <string>
#include "NutritionInfo.h"

class Drink {
public:
    Drink(int uniqueDrinkId, const std::string& nameOfDrink, int volumeInMilliliters,
          bool alcoholicFlag, double initialPrice, const NutritionInfo& nutritionData);
    bool isAlcoholicDrink() const;
    double calculatePricePerLiter() const;
    int getCalories() const;
    const std::string& getName() const;
    double getPrice() const;
private:
    int drinkId;
    std::string drinkName;
    int volumeMilliliters;
    bool isAlcoholic;
    double drinkPrice;
    NutritionInfo nutritionInformation;
};
