#pragma once
#include <string>
#include <vector>
class Ingredient;
class Chef;
class Warehouse;

class Recipe {
public:
    Recipe(int uniqueRecipeId, const std::string& nameOfRecipe, int preparationTimeMinutes, Chef* chefCreator);
    void addIngredient(Ingredient* ingredientToAdd);
    void removeIngredient(const std::string& ingredientNameToRemove);
    bool hasIngredient(const std::string& ingredientName) const;
    bool canBePrepared(Warehouse* warehouseReference) const;
    double calculateCost() const;
    bool isEmpty() const;
    const std::string& getName() const;
    int getId() const;
    int getPreparationTime() const;
    int getIngredientCount() const;
    Chef* getCreator() const;
    const std::vector<Ingredient*>& getIngredients() const;
private:
    int recipeId;
    std::string recipeName;
    std::vector<Ingredient*> recipeIngredients;
    int estimatedPreparationTimeMinutes;
    Chef* createdByChef;
};