#pragma once
#include <vector>
#include <string>
#include "Employee.h"
#include "Table.h"
#include "OrderItem.h"

class Order {
public:
    Order(int uniqueOrderId, Employee* waiterReference, Table* tableReference, const std::string& time);
    void addItem(OrderItem* itemToAdd);
    void removeItem(OrderItem* itemToRemove);
    double calculateTotalAmount() const;
    void markAsPaid();
    std::string getOrderSummary() const;
    int getId() const;
    std::string getOrderTime() const;
private:
    int orderId;
    Employee* servedByWaiter;
    std::vector<OrderItem*> orderItems;
    std::string orderTime;
    std::string orderStatus;
    Table* associatedTable;
};
