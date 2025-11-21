#pragma once
#include <string>
#include <vector>
#include "Supplier.h"
#include "InventoryItem.h"

class PurchaseOrder {
public:
    PurchaseOrder(int uniqueId, Supplier* supplier, const std::string& date);
    int getId() const;
    void addItem(InventoryItem* item);
    void markAsCompleted();
    const std::string& getStatus() const;
private:
    int purchaseOrderId;
    Supplier* supplierReference;
    std::vector<InventoryItem*> orderedItems;
    std::string orderDate;
    std::string orderStatus;
};
