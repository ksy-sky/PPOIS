#include "BillSplitter.h"
#include <algorithm>

BillSplitter::BillSplitter(int uniqueSplitterId, Order* orderReference)
    : splitterId(uniqueSplitterId), originalOrder(orderReference) {}

void BillSplitter::splitEvenly(int numberOfGuests, const std::vector<Customer*>& guestList) {
    double total = originalOrder->calculateTotalAmount();
    double perPerson = total / numberOfGuests;
    customers = guestList;
    customerItems.clear();
    customerTotals.clear();
    for (Customer* guest : guestList) {
        customerItems.push_back({});
        customerTotals.push_back(perPerson);
    }
}
void BillSplitter::assignItemsToCustomer(Customer* customerReference, const std::vector<OrderItem*>& items) {
    auto it = std::find(customers.begin(), customers.end(), customerReference);
    if (it != customers.end()) {
        int index = static_cast<int>(std::distance(customers.begin(), it));
        customerItems[index] = items;

        double total = 0;
        for (auto* item : items) {
            total += item->calculateTotalPrice();
        }
        customerTotals[index] = total;
    }
}
double BillSplitter::getTotalForCustomer(Customer* customerReference) const {
    auto it = std::find(customers.begin(), customers.end(), customerReference);
    if (it != customers.end()) {
        int index = static_cast<int>(std::distance(customers.begin(), it));
        return customerTotals[index];
    }
    return 0.0;
}
std::vector<double> BillSplitter::getAllTotals() const {
    return customerTotals;
}
