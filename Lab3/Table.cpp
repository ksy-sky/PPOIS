#include "Table.h"

Table::Table(int uniqueTableId,const std::string& number,int capacity,const std::string& zone)
    : tableId(uniqueTableId), tableNumber(number), seatingCapacity(capacity),locationZone(zone),currentOrder(nullptr) {}

int Table::getId() const { return tableId; }
Order* Table::getCurrentOrder() const { return currentOrder; }
void Table::assignOrder(Order* orderReference) { currentOrder = orderReference; }
