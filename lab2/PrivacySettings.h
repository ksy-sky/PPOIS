#pragma once

class PrivacySettings {
public:
    PrivacySettings(bool isPublic, bool allowRequests);
    void setPrivacy(bool isPublic, bool allowRequests);
private:
    bool isPublic;
    bool allowFriendRequests;
};

