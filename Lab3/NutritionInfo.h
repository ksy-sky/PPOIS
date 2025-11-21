#pragma once
#include <string>

class NutritionInfo {
public:
    NutritionInfo(int totalCalories, double proteinGrams, double fatGrams, double carbohydrateGrams,
         double fiberGrams, double sugarGrams);

    int getCalories() const;
    double getProtein() const;
    double getFat() const;
    double getCarbohydrates() const;
    double getFiber() const;
    double getSugar() const;
    std::string asString() const;
    double calculateEnergyKJ() const;
private:
    int calories;
    double protein;
    double fat;
    double carbohydrates;
    double fiber;
    double sugar;
};
