#include "Utensil.h"
#include "KitchenStation.h"

Utensil::Utensil(int uniqueUtensilId, const std::string& nameOfUtensil, int initialQuantity, KitchenStation* stationReference)
    : utensilId(uniqueUtensilId), utensilName(nameOfUtensil), quantityAvailable(initialQuantity),assignedStation(stationReference) {}

bool Utensil::useUtensil() {
    if (quantityAvailable > 0) {
        quantityAvailable--;
        return true;
    }
    return false;
}
void Utensil::returnUtensil() { quantityAvailable++; }
bool Utensil::checkAvailability() const { return quantityAvailable > 0; }
const std::string& Utensil::getName() const { return utensilName; }
int Utensil::getQuantity() const { return quantityAvailable; }
