#pragma once
#include <string>
#include "LoyaltyAccount.h"
class User; 

class Membership {
public:
    Membership(std::string id, User* user, std::string initialLevel, LoyaltyAccount* account);
    void upgradeLevel();
    void downgradeLevel();
    const std::string& getId() const;
    const std::string& getLevel() const;
private:
    std::string membershipId;
    User* client;
    std::string level; 
    LoyaltyAccount* loyaltyAccount;
};
