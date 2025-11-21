#pragma once
#include <vector>
#include "Order.h"
#include "OrderItem.h"
#include "Customer.h"

class BillSplitter {
public:
    BillSplitter(int uniqueSplitterId, Order* orderReference);
    void splitEvenly(int numberOfGuests, const std::vector<Customer*>& guestList);
    void assignItemsToCustomer(Customer* customerReference, const std::vector<OrderItem*>& items);
    double getTotalForCustomer(Customer* customerReference) const;
    std::vector<double> getAllTotals() const;
private:
    int splitterId;
    Order* originalOrder;
    std::vector<Customer*> customers;
    std::vector<std::vector<OrderItem*>> customerItems;
    std::vector<double> customerTotals;
};
