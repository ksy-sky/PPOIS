#pragma once
#include <string>

class Permission {
public:
    Permission(std::string key, std::string description, int priority);
    const std::string& getKey() const;
    const std::string& getDescription() const;
    int getPriorityLevel() const;
private:
    std::string permissionKey;
    std::string permissionDescription;
    int priorityLevel;
};
