#pragma once
#include <string>
#include "Supplier.h"
#include "PurchaseOrder.h"

class Delivery {
public:
    Delivery(int uniqueId, Supplier* supplier, PurchaseOrder* order, const std::string& date);
    int getId() const;
    const std::string& getStatus() const;
    void markAsReceived();
private:
    int deliveryId;
    Supplier* supplierReference;
    PurchaseOrder* relatedOrder;
    std::string deliveryDate;
    std::string deliveryStatus;
};
