#pragma once
#include <vector>
#include <string>
#include "User.h"
using namespace std;
class NotificationSystem {
public:
    NotificationSystem(User* user); 
    void addNotification(const string& message);
    void clearNotifications();
    vector<string> getNotifications() const;
private:
    vector<string> notifications;
    User* user;
};