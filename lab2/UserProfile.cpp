#include "UserProfile.h"
#include <iostream>
UserProfile::UserProfile(const string& name, const string& email, const PrivacySettings& settings)
    : name(name), email(email), privacySettings(settings) {}

void UserProfile::updateProfile(const string& newName, const string& newEmail) {
    name = newName;
    email = newEmail;
}
void UserProfile::setPrivacySettings(const PrivacySettings& settings) {
    privacySettings = settings;
}