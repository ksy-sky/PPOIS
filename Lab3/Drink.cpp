#include "Drink.h"

Drink::Drink(int uniqueDrinkId, const std::string& nameOfDrink, int volumeInMilliliters,
          bool alcoholicFlag, double initialPrice, const NutritionInfo& nutritionData)
    : drinkId(uniqueDrinkId), drinkName(nameOfDrink), volumeMilliliters(volumeInMilliliters),
      isAlcoholic(alcoholicFlag), drinkPrice(initialPrice), nutritionInformation(nutritionData) {}

bool Drink::isAlcoholicDrink() const { return isAlcoholic; }
double Drink::calculatePricePerLiter() const { return (drinkPrice / volumeMilliliters) * 1000.0; }
int Drink::getCalories() const { return nutritionInformation.getCalories(); }
const std::string& Drink::getName() const { return drinkName; }
double Drink::getPrice() const { return drinkPrice; }
