#include "Sommelier.h"

Sommelier::Sommelier(User* account, double salary, int experience, std::string specialtyRegion)
    : Employee(account, "Sommelier", salary, experience),
      wineRecommendations(0),
      wineSpecialtyRegion(specialtyRegion) {}

void Sommelier::recommendWine(const std::string& dish) {
    if (canDo("recommend_wine")) {
        std::cout << "Сомелье рекомендует вино к блюду \"" << dish << "\".\n";
        wineRecommendations++;
    } else {
        std::cout << "Нет прав на рекомендацию вина!\n";
    }
}

int Sommelier::getWineRecommendations() const { return wineRecommendations; }
const std::string& Sommelier::getSpecialtyRegion() const { return wineSpecialtyRegion; }
