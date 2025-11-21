#include "OrderService.h"
#include <algorithm>

OrderService::OrderService() : activeOrders(), completedOrders() {}

Order* OrderService::createOrder(Customer*, Table* table) {
    int newId = activeOrders.size() + completedOrders.size() + 1;
    auto* order = new Order(newId, nullptr, table, ""); 
    activeOrders.push_back(order);
    return order;
}
void OrderService::addItemToOrder(Order* orderReference, OrderItem* itemToAdd) {
    if (orderReference && itemToAdd) {
        orderReference->addItem(itemToAdd);
    }
}
void OrderService::finalizeOrder(Order* orderReference) {
    if (!orderReference) return;
    activeOrders.erase(
        std::remove(activeOrders.begin(), activeOrders.end(), orderReference),
        activeOrders.end()
    );
    completedOrders.push_back(orderReference);
}
void OrderService::cancelOrder(Order* orderReference) {
    if (!orderReference) return;
    activeOrders.erase(
        std::remove(activeOrders.begin(), activeOrders.end(), orderReference),
        activeOrders.end()
    );
    delete orderReference; 
}
Order* OrderService::getOrderById(int orderId) const {
    for (auto* order : activeOrders) {
        if (order->getId() == orderId) return order;
    }
    for (auto* order : completedOrders) {
        if (order->getId() == orderId) return order;
    }
    return nullptr;
}
