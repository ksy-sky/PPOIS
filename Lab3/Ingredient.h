#pragma once
#include <string>
class Supplier;

class Ingredient {
public:
    Ingredient(int uniqueIngredientId, const std::string& nameOfIngredient, double initialQuantity, const std::string& unitOfMeasurement);
    void addStock(double additionalQuantity);
    bool useStock(double requiredQuantity);
    bool isAvailable(double requiredQuantity) const;
    void linkSupplier(Supplier* supplierReference);
    const std::string& getName() const;
    double getQuantity() const;
private:
    int ingredientId;
    std::string ingredientName;
    double ingredientQuantity;
    std::string measurementUnit;
    Supplier* linkedSupplier;
};
