#include "Recipe.h"
#include "Ingredient.h"
#include <algorithm>

Recipe::Recipe(int uniqueRecipeId, const std::string& nameOfRecipe, int preparationTimeMinutes, Chef* chefCreator)
    : recipeId(uniqueRecipeId), recipeName(nameOfRecipe),estimatedPreparationTimeMinutes(preparationTimeMinutes), createdByChef(chefCreator) {}

void Recipe::addIngredient(Ingredient* ingredientToAdd) {
    for (const auto& ingredient : recipeIngredients) {
        if (ingredient->getName() == ingredientToAdd->getName()) {
            return; 
        }
    }
    recipeIngredients.push_back(ingredientToAdd);
}
void Recipe::removeIngredient(const std::string& ingredientNameToRemove) {
    recipeIngredients.erase(
        std::remove_if(recipeIngredients.begin(), recipeIngredients.end(),
            [&](Ingredient* ingredient) {
                return ingredient->getName() == ingredientNameToRemove;
            }),
        recipeIngredients.end()
    );
}
bool Recipe::hasIngredient(const std::string& ingredientName) const {
    for (const auto& ingredient : recipeIngredients) {
        if (ingredient->getName() == ingredientName) {
            return true;
        }
    }
    return false;
}
bool Recipe::canBePrepared(Warehouse* warehouseReference) const { return true; }
double Recipe::calculateCost() const {
    double totalCost = 0.0;
    for (const auto& ingredient : recipeIngredients) {
        totalCost += 1.0 * ingredient->getQuantity();
    }
    return totalCost;
}
bool Recipe::isEmpty() const { return recipeIngredients.empty(); }
const std::string& Recipe::getName() const { return recipeName; }
int Recipe::getId() const { return recipeId; }
int Recipe::getPreparationTime() const { return estimatedPreparationTimeMinutes; }
int Recipe::getIngredientCount() const { return recipeIngredients.size(); }
Chef* Recipe::getCreator() const { return createdByChef; }
const std::vector<Ingredient*>& Recipe::getIngredients() const { return recipeIngredients; }