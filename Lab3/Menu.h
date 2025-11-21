#pragma once
#include <string>
#include <vector>
#include "Dish.h"
class Admin;

class Menu {
public:
    Menu(int uniqueMenuId, const std::string& titleOfMenu, const std::string& seasonOfMenu, Admin* adminCreator);
    void addDish(const Dish& dishToAdd);
    void removeDish(const std::string& dishNameToRemove);
    Dish* findDish(const std::string& dishNameToFind);
    std::vector<Dish> listAvailableDishes() const;
private:
    int menuId;
    std::string menuTitle;
    std::vector<Dish> menuDishes;
    std::string menuSeason;
    Admin* createdByAdmin;
};
