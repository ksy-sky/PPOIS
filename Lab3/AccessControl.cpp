#include "AccessControl.h"
#include <iostream>

void AccessControl::addRole(const Role& role) { availableRoles.push_back(role); }
const Role* AccessControl::findRole(const std::string& name) const {
    for (const auto& role : availableRoles) if (role.getName() == name) return &role;
    return nullptr;
}
void AccessControl::listRoles() const {
    for (const auto& role : availableRoles)
        std::cout << "Role: " << role.getName() << " - " << role.getDescription() << "\n";
}