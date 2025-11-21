#include "Dessert.h"
#include "Chef.h"

Dessert::Dessert(int uniqueDessertId, const std::string& nameOfDessert, int sweetnessScale,
         const NutritionInfo& nutritionData, double initialPrice, Chef* chefCreator)
    : dessertId(uniqueDessertId),dessertName(nameOfDessert), sweetnessLevel(sweetnessScale),
    nutritionInformation(nutritionData),dessertPrice(initialPrice), createdByChef(chefCreator) {}
std::string Dessert::describeDessert() const {
    return "Dessert: " + dessertName + ", Sweetness: " + std::to_string(sweetnessLevel) +
           ", Price: " + std::to_string(dessertPrice);
}
bool Dessert::isSugarFree() const { return nutritionInformation.getSugar() == 0.0;}
double Dessert::calculateCaloriesPerGram(double weightInGrams) const { return (nutritionInformation.getCalories() / 100.0) * weightInGrams;}
const std::string& Dessert::getName() const { return dessertName; }
double Dessert::getPrice() const { return dessertPrice; }
