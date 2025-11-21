#include "OrderItem.h"
#include "Dish.h"

OrderItem::OrderItem(int uniqueItemId, Dish* dishReference, int quantity, const std::string& instructions, double unitPrice)
    : orderItemId(uniqueItemId), linkedDish(dishReference),
      quantityOrdered(quantity), specialInstructions(instructions), pricePerUnit(unitPrice) {}

double OrderItem::calculateTotalPrice() const { return quantityOrdered * pricePerUnit; }
bool OrderItem::isCustomizable() const { return !specialInstructions.empty(); }
std::vector<std::string> OrderItem::getAllergenTags() const { return linkedDish->getAllergenTags(); }
