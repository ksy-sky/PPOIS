#pragma once
#include <vector>
#include <string>
#include "Warehouse.h"
#include "InventoryItem.h"

class InventoryService {
public:
    InventoryService(Warehouse* warehouseReference);
    void registerItem(InventoryItem* item);
    bool moveItem(InventoryItem* item, const std::string& sourceName, const std::string& destinationName, int quantity);
    int getTotalStock(const std::string& sku) const;
private:
    Warehouse* managedWarehouse;
    std::vector<InventoryItem*> trackedItems;
};
