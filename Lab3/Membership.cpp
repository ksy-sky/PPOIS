#include "Membership.h"

Membership::Membership(std::string id, User* user, std::string initialLevel, LoyaltyAccount* account)
    : membershipId(id), client(user), level(initialLevel), loyaltyAccount(account) {}

void Membership::upgradeLevel() { if (level == "Basic") level = "Premium"; }
void Membership::downgradeLevel() { if (level == "Premium") level = "Basic"; }
const std::string& Membership::getId() const { return membershipId; }
const std::string& Membership::getLevel() const { return level; }
