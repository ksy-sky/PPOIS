#include "Notification.h"
#include <iostream>

Notification::Notification(std::string id, User* user, std::string message)
    : notificationId(id), recipient(user), text(message), isSent(false) {}

void Notification::send() {
    isSent = true;
    std::cout << "Notification sent: " << text << "\n";
}
const std::string& Notification::getId() const { return notificationId; }
bool Notification::getStatus() const { return isSent; }
