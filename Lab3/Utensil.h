#pragma once
#include <string>
class KitchenStation;

class Utensil {
public:
    Utensil(int uniqueUtensilId, const std::string& nameOfUtensil, int initialQuantity, KitchenStation* stationReference);
    bool useUtensil();
    void returnUtensil();
    bool checkAvailability() const;
    const std::string& getName() const;
    int getQuantity() const;
private:
    int utensilId;
    std::string utensilName;
    int quantityAvailable;
    KitchenStation* assignedStation;
};
