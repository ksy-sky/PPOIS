#pragma once
#include <string>
#include <vector>
#include "Dish.h"
class Admin;

class SeasonalMenu {
public:
    SeasonalMenu(int uniqueMenuId, const std::string& seasonLabel, Admin* adminCreator);
    void addSeasonalDish(const Dish& dishToAdd);
    void removeSeasonalDish(const std::string& dishNameToRemove);
    std::vector<Dish> listSeasonalDishes() const;
private:
    int seasonalMenuId;
    std::string seasonName; 
    std::vector<Dish> seasonalDishes;
    Admin* createdByAdmin;
};
