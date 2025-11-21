#include "InventoryItem.h"

InventoryItem::InventoryItem(const std::string& name, int quantity, const std::string& unit)
    : name(name), quantity(quantity), unit(unit) {}

void InventoryItem::addStock(int amount) {
    if (amount > 0) quantity += amount;
}
bool InventoryItem::consumeStock(int amount) {
    if (amount <= 0) return false;
    if (quantity >= amount) {
        quantity -= amount;
        return true;
    }
    return false;
}
bool InventoryItem::isAvailable(int amount) const {
    return amount >= 0 && quantity >= amount;
}
const std::string& InventoryItem::getName() const { return name; }
int InventoryItem::getQuantity() const { return quantity; }
const std::string& InventoryItem::getUnit() const { return unit; }
void InventoryItem::addQuantity(int amount) {
    if (amount > 0) {
        quantity += amount;
    }
}
bool InventoryItem::reduceQuantity(int amount) {
    if (amount > 0 && quantity >= amount) {
        quantity -= amount;
        return true;
    }
    return false; 
}