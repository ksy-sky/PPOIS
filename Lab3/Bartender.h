#pragma once
#include "Employee.h"
#include <iostream>

class Bartender : public Employee {
public:
    Bartender(User* account, double salary, int experience);
    void mixCocktail();
    int getCocktailsMixed() const;
private:
    int cocktailsMixed;
};
