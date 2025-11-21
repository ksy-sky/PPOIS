#include "NutritionInfo.h"
#include <string>

NutritionInfo::NutritionInfo(int totalCalories, double proteinGrams, double fatGrams, 
    double carbohydrateGrams, double fiberGrams, double sugarGrams) 
    : calories(totalCalories), protein(proteinGrams), fat(fatGrams), carbohydrates(carbohydrateGrams),
      fiber(fiberGrams), sugar(sugarGrams) {}

int NutritionInfo::getCalories() const { return calories; }
double NutritionInfo::getProtein() const { return protein; }
double NutritionInfo::getFat() const { return fat; }
double NutritionInfo::getCarbohydrates() const { return carbohydrates; }
double NutritionInfo::getFiber() const { return fiber; }
double NutritionInfo::getSugar() const { return sugar; }
std::string NutritionInfo::asString() const {
    return "Calories: " + std::to_string(calories) +
           ", Protein: " + std::to_string(protein) + "g" +
           ", Fat: " + std::to_string(fat) + "g" +
           ", Carbs: " + std::to_string(carbohydrates) + "g" +
           ", Fiber: " + std::to_string(fiber) + "g" +
           ", Sugar: " + std::to_string(sugar) + "g";
}
double NutritionInfo::calculateEnergyKJ() const {
    return calories * 4.184;
}
