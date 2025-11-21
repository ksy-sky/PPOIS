#include "Ingredient.h"
#include "Supplier.h"

Ingredient::Ingredient(int uniqueIngredientId, const std::string& nameOfIngredient,
                       double initialQuantity, const std::string& unitOfMeasurement)
    : ingredientId(uniqueIngredientId), ingredientName(nameOfIngredient),
      ingredientQuantity(initialQuantity), measurementUnit(unitOfMeasurement),linkedSupplier(nullptr) {}

void Ingredient::addStock(double additionalQuantity) {
    if (additionalQuantity > 0) ingredientQuantity += additionalQuantity;
}
bool Ingredient::useStock(double requiredQuantity) {
    if (ingredientQuantity >= requiredQuantity) {
        ingredientQuantity -= requiredQuantity;
        return true;
    }
    return false;
}
bool Ingredient::isAvailable(double requiredQuantity) const { return ingredientQuantity >= requiredQuantity; }
void Ingredient::linkSupplier(Supplier* supplierReference) { linkedSupplier = supplierReference; }
const std::string& Ingredient::getName() const { return ingredientName; }
double Ingredient::getQuantity() const { return ingredientQuantity; }
