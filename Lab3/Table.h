#pragma once
#include <string>
class Order;

class Table {
public:
    Table(int uniqueTableId, const std::string& number, int capacity, const std::string& zone);
    int getId() const;
    Order* getCurrentOrder() const;
    void assignOrder(Order* orderReference);
private:
    int tableId;
    std::string tableNumber;
    int seatingCapacity;
    std::string locationZone;
    Order* currentOrder;
};
