#include "NotificationSystem.h"

NotificationSystem::NotificationSystem(User* user) 
    : user(user) {
}
void NotificationSystem::addNotification(const string& message) {
    notifications.push_back(message); 
}
void NotificationSystem::clearNotifications() {
    notifications.clear(); 
}
vector<string> NotificationSystem::getNotifications() const {
    return notifications; 
}