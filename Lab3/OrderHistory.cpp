#include "OrderHistory.h"

OrderHistory::OrderHistory(Customer* customerReference) : associatedCustomer(customerReference) {}

void OrderHistory::addOrder(Order* completedOrder) {
    if (completedOrder) {
        completedOrders.push_back(completedOrder);
    }
}
std::vector<Order*> OrderHistory::getOrdersBetween(const std::string& startDate, const std::string& endDate) const {
    std::vector<Order*> result;
    for (Order* order : completedOrders) {
        const std::string& time = order->getOrderTime();
        if (time >= startDate && time <= endDate) {
            result.push_back(order);
        }
    }
    return result;
}
double OrderHistory::getTotalSpent() const {
    double total = 0.0;
    for (Order* order : completedOrders) {
        total += order->calculateTotalAmount();
    }
    return total;
}

