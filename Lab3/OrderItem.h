#pragma once
#include <string>
#include <vector>
#include "Dish.h"

class OrderItem {
public:
    OrderItem(int uniqueItemId, Dish* dishReference, int quantity,const std::string& instructions, double unitPrice);
    double calculateTotalPrice() const;
    bool isCustomizable() const;
    std::vector<std::string> getAllergenTags() const;
private:
    int orderItemId;
    Dish* linkedDish;
    int quantityOrdered;
    std::string specialInstructions;
    double pricePerUnit;
};
