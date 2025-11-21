#pragma once
#include <iostream>
#include <string>
using namespace std;
class SecurityManager {
public:
    SecurityManager(const string& initialPassword);
    bool changePassword(const string& oldPassword, const string& newPassword);
    void enableTwoFactorAuthentication();
private:
    string password;
    bool twoFactorEnabled;
};

