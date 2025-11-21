#include "LoyaltyAccount.h"

LoyaltyAccount::LoyaltyAccount(std::string id, int initialPoints, std::string initialLevel)
    : accountId(id), points(initialPoints), level(initialLevel) {}

void LoyaltyAccount::addPoints(int amount) {
    points += amount;
    if (points >= 1000) level = "Gold";
    else if (points >= 500) level = "Silver";
    else level = "Bronze";
}
bool LoyaltyAccount::redeemPoints(int amount) {
    if (points >= amount) {
        points -= amount;
        return true;
    }
    return false;
}
int LoyaltyAccount::getPoints() const { return points; }
const std::string& LoyaltyAccount::getLevel() const { return level; }
