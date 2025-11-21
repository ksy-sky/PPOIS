#pragma once
#include <string>

class InventoryItem {
public:
    InventoryItem() = default;
    InventoryItem(const std::string& name, int quantity, const std::string& unit);
    void addStock(int amount);
    bool consumeStock(int amount);
    bool isAvailable(int amount) const;
    const std::string& getName() const;
    int getQuantity() const;
    const std::string& getUnit() const;
    void addQuantity(int amount);
    bool reduceQuantity(int amount); 
private:
    std::string name;     
    int quantity;   
    std::string unit;
};
