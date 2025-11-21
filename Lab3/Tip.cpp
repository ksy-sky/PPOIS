#include "Tip.h"

Tip::Tip(int uniqueTipId, double amount, int customerId, int employeeId, int orderId)
    : tipId(uniqueTipId), tipAmount(amount), giverId(customerId), receiverId(employeeId), orderId(orderId) {}

double Tip::calculatePercentageOfOrder(double orderTotal) const {
    if (orderTotal <= 0.0) return 0.0;
    return (tipAmount / orderTotal) * 100.0;
}
bool Tip::isCashTip() const { return tipAmount < 100.0; }
bool Tip::isIncludedInBill(double orderTotal) const { return calculatePercentageOfOrder(orderTotal) >= 10.0; }
