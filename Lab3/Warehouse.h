#pragma once
#include <string>
#include <vector>
#include "InventoryItem.h"

class Warehouse {
public:
    Warehouse(const std::string& id, const std::string& address);
    bool addItem(const InventoryItem& item); 
    InventoryItem* findItem(const std::string& name); 
    bool isAvailable(const std::string& name, double amount) const; 
    bool consumeItem(const std::string& name, double amount); 
    void addStock(const std::string& name, double amount); 
    std::string listItems() const;
    const std::string& getId() const;
    const std::string& getAddress() const;
private:
    std::string warehouseId;
    std::string address;
    std::vector<InventoryItem> items;
};