#include "Dish.h"
#include "Chef.h"

Dish::Dish(int uniqueDishId, const std::string& nameOfDish, const std::string& categoryOfDish, double initialPrice,
         bool availabilityStatus, const NutritionInfo& nutritionData, Chef* chefCreator)
    : dishId(uniqueDishId),dishName(nameOfDish), dishCategory(categoryOfDish),dishPrice(initialPrice),
      isCurrentlyAvailable(availabilityStatus), nutritionInformation(nutritionData), createdByChef(chefCreator) {}

bool Dish::isAvailable() const { return isCurrentlyAvailable; }
void Dish::setAvailability(bool availabilityStatus) { isCurrentlyAvailable = availabilityStatus; }
int Dish::getCalories() const { return nutritionInformation.getCalories(); }
void Dish::applyDiscount(double discountPercent) {
    if (discountPercent > 0 && discountPercent <= 100) {
        dishPrice -= dishPrice * (discountPercent / 100.0);
    }
}
const std::string& Dish::getName() const { return dishName; }
double Dish::getPrice() const { return dishPrice; }
const std::vector<std::string>& Dish::getAllergenTags() const { return allergenTags; }