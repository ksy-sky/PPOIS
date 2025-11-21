#pragma once
#include <vector>
#include "Order.h"
#include "Customer.h"
#include "Table.h"
#include "OrderItem.h"

class OrderService {
public:
    OrderService();
    Order* createOrder(Customer* customerReference, Table* tableReference);
    void addItemToOrder(Order* orderReference, OrderItem* itemToAdd);
    void finalizeOrder(Order* orderReference);
    void cancelOrder(Order* orderReference);
    Order* getOrderById(int orderId) const;
private:
    std::vector<Order*> activeOrders;
    std::vector<Order*> completedOrders;
};
