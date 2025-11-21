#pragma once
#include "AccessControl.h"
#include "User.h"

class Admin {
public:
    Admin(AccessControl* accessControl, std::string name);
    void grantRole(User& user, const std::string& roleName);
    void revokeRole(User& user, const std::string& roleName);
    void listAvailableRoles() const;
    const std::string& getName() const;
private:
    AccessControl* accessControlSystem;
    std::string adminName;
};
