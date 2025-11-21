#pragma once
#include <string>
#include <vector>
#include "Permission.h"

class Role {
public:
    Role(std::string name, std::string description);
    void addPermission(const Permission& permission);
    bool hasPermission(const std::string& key) const;
    const std::string& getName() const;
    const std::string& getDescription() const;
private:
    std::string roleName;
    std::vector<Permission> rolePermissions;
    std::string description;
};
