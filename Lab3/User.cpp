#include "User.h"
#include <algorithm>

User::User(std::string id, std::string name) : userId(id), userName(name), loyaltyAccount(nullptr) {}
void User::addRole(const Role& role) { assignedRoles.push_back(role); }
void User::removeRole(const std::string& roleName) {
    assignedRoles.erase(std::remove_if(assignedRoles.begin(), assignedRoles.end(),
        [&](const Role& role){ return role.getName() == roleName; }), assignedRoles.end());
}
bool User::canDo(const std::string& action) const {
    for (const auto& role : assignedRoles)
        if (role.hasPermission(action)) return true;
    return false;
}
const std::string& User::getName() const { return userName; }
void User::attachLoyaltyAccount(LoyaltyAccount* account) { loyaltyAccount = account; }
LoyaltyAccount* User::getLoyaltyAccount() const { return loyaltyAccount; }