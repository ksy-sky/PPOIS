#include "SeasonalMenu.h"
#include "Admin.h"
#include <algorithm>

SeasonalMenu::SeasonalMenu(int uniqueMenuId, const std::string& seasonLabel, Admin* adminCreator)
    : seasonalMenuId(uniqueMenuId), seasonName(seasonLabel), createdByAdmin(adminCreator) {}

void SeasonalMenu::addSeasonalDish(const Dish& dishToAdd) { seasonalDishes.push_back(dishToAdd); }
void SeasonalMenu::removeSeasonalDish(const std::string& dishNameToRemove) {
    seasonalDishes.erase(
        std::remove_if(seasonalDishes.begin(), seasonalDishes.end(),
                       [&](const Dish& dish) { return dish.getName() == dishNameToRemove; }),
        seasonalDishes.end());
}
std::vector<Dish> SeasonalMenu::listSeasonalDishes() const { return seasonalDishes;}
