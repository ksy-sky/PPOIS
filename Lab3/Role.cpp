#include "Role.h"

Role::Role(std::string name, std::string description) : roleName(name), description(description) {}
void Role::addPermission(const Permission& permission) { rolePermissions.push_back(permission); }
bool Role::hasPermission(const std::string& key) const {
    for (const auto& permission : rolePermissions) if (permission.getKey() == key) return true;
    return false;
}
const std::string& Role::getName() const { return roleName; }
const std::string& Role::getDescription() const { return description; }
