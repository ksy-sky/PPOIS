#include "Admin.h"
#include <iostream>

Admin::Admin(AccessControl* accessControl, std::string name)
    : accessControlSystem(accessControl), adminName(name) {}
void Admin::grantRole(User& user, const std::string& roleName) {
    const Role* role = accessControlSystem->findRole(roleName);
    if (role) {
        user.addRole(*role);
        std::cout << "Админ " << adminName << " назначил роль " << roleName << " пользователю " << user.getName() << ".\n";
    } else {
        std::cout << "Роль " << roleName << " не найдена.\n";
    }
}
void Admin::revokeRole(User& user, const std::string& roleName) {
    user.removeRole(roleName);
    std::cout << "Админ " << adminName << " удалил роль " << roleName << " у пользователя " << user.getName() << ".\n";
}
void Admin::listAvailableRoles() const {
    std::cout << "Доступные роли:\n";
    accessControlSystem->listRoles();
}
const std::string& Admin::getName() const { return adminName; }
