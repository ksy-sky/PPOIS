#pragma once
#include <string>
#include "PrivacySettings.h"
using namespace std;
class UserProfile {
public:
    UserProfile(const string& name, const string& email, const PrivacySettings& settings);
    void updateProfile(const string& newName, const string& newEmail);
    void setPrivacySettings(const PrivacySettings& settings);
private:
    string name;
    string email;
    string profilePicture;
    PrivacySettings privacySettings;
};

