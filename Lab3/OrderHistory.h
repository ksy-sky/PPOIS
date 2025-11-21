#pragma once
#include <vector>
#include <string>
#include "Customer.h"
#include "Order.h"

class OrderHistory {
public:
    OrderHistory(Customer* customerReference);
    void addOrder(Order* completedOrder);
    std::vector<Order*> getOrdersBetween(const std::string& startDate, const std::string& endDate) const;
    double getTotalSpent() const;
private:
    Customer* associatedCustomer;
    std::vector<Order*> completedOrders;
};
