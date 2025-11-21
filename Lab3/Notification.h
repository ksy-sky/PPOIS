#pragma once
#include <string>
class User; 

class Notification {
public:
    Notification(std::string id, User* user, std::string message);
    void send();
    const std::string& getId() const;
    bool getStatus() const;
private:
    std::string notificationId;
    User* recipient;
    std::string text;
    bool isSent;
};
