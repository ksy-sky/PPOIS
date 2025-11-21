#include "Delivery.h"

Delivery::Delivery(int uniqueId,Supplier* supplier, PurchaseOrder* order, const std::string& date)
    : deliveryId(uniqueId), supplierReference(supplier), relatedOrder(order), deliveryDate(date), deliveryStatus("Pending") {}
int Delivery::getId() const { return deliveryId; }
const std::string& Delivery::getStatus() const { return deliveryStatus; }
void Delivery::markAsReceived() {
    deliveryStatus = "Received";
}
