#pragma once
#include <vector>
#include "Role.h"

class AccessControl {
public:
    void addRole(const Role& role);
    const Role* findRole(const std::string& name) const;
    void listRoles() const;
private:
    std::vector<Role> availableRoles;
};
