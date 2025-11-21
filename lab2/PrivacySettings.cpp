#include "PrivacySettings.h"
#include <iostream>

PrivacySettings::PrivacySettings(bool isPublic, bool allowRequests)
    : isPublic(isPublic), allowFriendRequests(allowRequests) {}

void PrivacySettings::setPrivacy(bool isPublic, bool allowRequests) {
    this->isPublic = isPublic;
    this->allowFriendRequests = allowRequests;
}