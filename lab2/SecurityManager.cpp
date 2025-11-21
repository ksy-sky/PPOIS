#include "SecurityManager.h"
#include <iostream>

SecurityManager::SecurityManager(const string& initialPassword)
    : password(initialPassword), twoFactorEnabled(false) {}

bool SecurityManager::changePassword(const string& oldPassword, const string& newPassword) {
    if (oldPassword == password) {
        password = newPassword;
        return true; 
    }
    return false; 
}
void SecurityManager::enableTwoFactorAuthentication() {
    twoFactorEnabled = true; 
}