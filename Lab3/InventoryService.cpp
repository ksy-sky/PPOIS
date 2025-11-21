#include "InventoryService.h"

InventoryService::InventoryService(Warehouse* warehouseReference) 
    : managedWarehouse(warehouseReference) {}

void InventoryService::registerItem(InventoryItem* item) { trackedItems.push_back(item); }
bool InventoryService::moveItem(InventoryItem* item, const std::string& sourceName,
                                const std::string& destinationName, int quantity) {
    if (!item) return false;
    if (item->getQuantity() < quantity) return false;
    item->reduceQuantity(quantity);
    std::string entry = "Moved " + std::to_string(quantity) + " of " + item->getName() +
                        " from " + sourceName + " to " + destinationName;
    return true;
}
int InventoryService::getTotalStock(const std::string& name) const {
    int total = 0;
    for (auto* item : trackedItems) {
        if (item->getName() == name) {
            total += item->getQuantity();
        }
    }
    return total;
}

