#pragma once
#include <string>

class Tip {
public:
    Tip(int uniqueTipId, double amount, int customerId, int employeeId, int orderId);
    double calculatePercentageOfOrder(double orderTotal) const;
    bool isCashTip() const;
    bool isIncludedInBill(double orderTotal) const;
private:
    int tipId;
    double tipAmount;
    int giverId;     
    int receiverId;
    int orderId;
};
