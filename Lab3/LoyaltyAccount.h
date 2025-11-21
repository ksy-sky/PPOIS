#pragma once
#include <string>

class LoyaltyAccount {
public:
    LoyaltyAccount(std::string id, int initialPoints = 0, std::string initialLevel = "Bronze");
    void addPoints(int amount);
    bool redeemPoints(int amount);
    int getPoints() const;
    const std::string& getLevel() const;
private:
    std::string accountId;
    int points;
    std::string level; 
};
