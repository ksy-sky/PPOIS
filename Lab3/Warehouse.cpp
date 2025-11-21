#include "Warehouse.h"

Warehouse::Warehouse(const std::string& id, const std::string& addr)
    : warehouseId(id), address(addr) {}

bool Warehouse::addItem(const InventoryItem& item) {
    for (auto& it : items) {
        if (it.getName() == item.getName()) {
            it = item; 
            return false;
        }
    }
    items.push_back(item);
    return true;
}
InventoryItem* Warehouse::findItem(const std::string& name) {
    for (auto& it : items) {
        if (it.getName() == name) return &it;
    }
    return nullptr;
}
bool Warehouse::isAvailable(const std::string& name, double amount) const {
    for (const auto& it : items) {
        if (it.getName() == name) return it.isAvailable(amount);
    }
    return false;
}
bool Warehouse::consumeItem(const std::string& name, double amount) {
    for (auto& it : items) {
        if (it.getName() == name) return it.consumeStock(amount);
    }
    return false;
}
void Warehouse::addStock(const std::string& name, double amount) {
    for (auto& it : items) {
        if (it.getName() == name) {
            it.addStock(amount);
            return;
        }
    }
}
std::string Warehouse::listItems() const {
    std::string out = "Warehouse " + warehouseId + " at " + address + ":\n";
    for (const auto& item : items) {
        out += " - " + item.getName() + ": "
             + std::to_string(item.getQuantity()) + " " + item.getUnit() + "\n";
    }
    return out;
}
const std::string& Warehouse::getId() const { return warehouseId; }
const std::string& Warehouse::getAddress() const { return address; }