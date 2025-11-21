#pragma once
#include <string>
#include <vector>
#include "Role.h"
#include "LoyaltyAccount.h"

class User {
public:
    User(std::string id, std::string name);
    void addRole(const Role& role);
    void removeRole(const std::string& roleName);
    bool canDo(const std::string& action) const;
    const std::string& getName() const;
    void attachLoyaltyAccount(LoyaltyAccount* account);
    LoyaltyAccount* getLoyaltyAccount() const;
private:
    std::string userId;
    std::string userName;
    std::vector<Role> assignedRoles;
    LoyaltyAccount* loyaltyAccount;
};
