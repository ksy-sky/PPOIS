#include "Menu.h"
#include "Admin.h"
#include <algorithm>

Menu::Menu(int uniqueMenuId, const std::string& titleOfMenu, const std::string& seasonOfMenu, Admin* adminCreator)
    : menuId(uniqueMenuId), menuTitle(titleOfMenu), menuSeason(seasonOfMenu), createdByAdmin(adminCreator) {}

void Menu::addDish(const Dish& dishToAdd) { menuDishes.push_back(dishToAdd); }
void Menu::removeDish(const std::string& dishNameToRemove) {
    menuDishes.erase(
        std::remove_if(menuDishes.begin(), menuDishes.end(),
                       [&](const Dish& dish) { return dish.getName() == dishNameToRemove; }),
        menuDishes.end());
}
Dish* Menu::findDish(const std::string& dishNameToFind) {
    for (auto& dish : menuDishes) {
        if (dish.getName() == dishNameToFind) return &dish;
    }
    return nullptr;
}
std::vector<Dish> Menu::listAvailableDishes() const {
    std::vector<Dish> availableDishes;
    for (const auto& dish : menuDishes) {
        if (dish.isAvailable()) availableDishes.push_back(dish);
    }
    return availableDishes;
}
