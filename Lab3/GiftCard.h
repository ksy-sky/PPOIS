#pragma once
#include <string>

class GiftCard {
public:
    GiftCard(std::string code, double initialBalance);
    bool redeem(double amount);
    void deactivate();
    const std::string& getCode() const;
    double getBalance() const;
    bool getStatus() const;
private:
    std::string cardCode;
    double balance;
    bool isActive;
};
