#include "Order.h"
#include "OrderItem.h"
#include "Employee.h"
#include "Table.h"
#include <algorithm>

Order::Order(int uniqueOrderId, Employee* waiterReference, Table* tableReference, const std::string& time)
    : orderId(uniqueOrderId), servedByWaiter(waiterReference), associatedTable(tableReference), orderTime(time), orderStatus("Active") {}

void Order::addItem(OrderItem* itemToAdd) { orderItems.push_back(itemToAdd); }
void Order::markAsPaid() { orderStatus = "Paid"; }
int Order::getId() const { return orderId; }
std::string Order::getOrderTime() const{ return orderTime; }
void Order::removeItem(OrderItem* itemToRemove) {
    orderItems.erase(
        std::remove(orderItems.begin(), orderItems.end(), itemToRemove),
        orderItems.end());
}
double Order::calculateTotalAmount() const {
    double total = 0;
    for (auto* item : orderItems) {
        total += item->calculateTotalPrice();
    }
    return total;
}
std::string Order::getOrderSummary() const {
    return "Order #" + std::to_string(orderId) +
           " (" + orderStatus + ") Total: " +
           std::to_string(calculateTotalAmount());

}


