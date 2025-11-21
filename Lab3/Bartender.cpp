#include "Bartender.h"

Bartender::Bartender(User* account, double salary, int exp)
    : Employee(account, "Bartender", salary, exp), cocktailsMixed(0) {}
void Bartender::mixCocktail() {
    if (canDo("mix_cocktail")) {
        std::cout << "Бармен смешивает коктейль.\n";
        cocktailsMixed++;
    } else {
        std::cout << "Нет прав на приготовление коктейля!\n";
    }
}
int Bartender::getCocktailsMixed() const { return cocktailsMixed; }
