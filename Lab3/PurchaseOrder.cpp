#include "PurchaseOrder.h"

PurchaseOrder::PurchaseOrder(int uniqueId, Supplier* supplier, const std::string& date)
    : purchaseOrderId(uniqueId), supplierReference(supplier), orderDate(date), orderStatus("Open") {}
int PurchaseOrder::getId() const { return purchaseOrderId; }
void PurchaseOrder::addItem(InventoryItem* item) { orderedItems.push_back(item); }
void PurchaseOrder::markAsCompleted() { orderStatus = "Completed"; }
const std::string& PurchaseOrder::getStatus() const { return orderStatus; }
